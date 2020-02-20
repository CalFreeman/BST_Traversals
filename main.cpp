#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <ostream>
#include "buildTree.h"
#include "traversals.h"
using namespace std;

int main(int argc, char *argv[]) {
  string f_name;

  ifstream inFile;
  string words;

  int i;

  // redirection variables
  string inputFile;
  ofstream ofFile;

  //variables for parsing characters from input
  int size;
  char wordArr[1024];

  // variables for feeding input into tree
  char letter;
  string word;
  struct Node *root = NULL;  

  // string extension
  string outputPrefix;
  string outputFile;

  //checkig if file is empty
  FILE *f;
  
  //  Process command arguments, set up file to process regardless of source
  //  check if file is readable, set the basename for the output file.
  //  if argc == 2; read from the file
  if (argc > 2) {
    cout << argv[0] << ' ' << argv[1] << ' ' << argv[2] << endl;
    cout << "Fatal: Improper usage" << endl;
    cout << "Usage: P0 [filename]" << endl;
    exit(1);
  }
  else if (argc == 2) {
    f_name = argv[1];
    outputPrefix = argv[1];

    cout << " argc is 2, processes " << argv[1] << endl;
    cout << "file provided" << endl;
  
  } 
  else if (argc == 1){
    cout << " argc is 1, processes: " << argv[0] << endl;
    cout << " redirection or keyboard input" << endl;
    f_name = "temp.txt";
    outputPrefix = "out";
    ofFile.open(f_name.c_str());

    while( cin >> inputFile) {
      ofFile << inputFile << " ";
    }

   ofFile.close();
 
  if (isatty(STDIN_FILENO)){
    //no redirection, keyboard input use out extension
    outputPrefix = "out";
  } else {
    // redirection use argv[0] filename represents start of extension 
    outputPrefix = "out";
    cout << "argv[] " << argv[0] << " " << argv[1] << " " << argv[2] << "\n";
  }

  }
  else {
    cout << "Improper usage" << endl;
  }


  cout << "FILE PREFIX: " << outputPrefix;
  char ch;
  f = fopen(f_name.c_str(), "r");
  if(fscanf(f,"%c", &ch)==EOF){
    perror("Error: empty file provided exiting program");
    exit(1);
  }

  // building BST by calling node* buildTree
  root = buildTree(f_name);
  cout << outputPrefix << "\n";
  outputFile = outputPrefix;

  //cout << "inOrder: \n";
  inorder(root, outputFile);
  //cout << "PostOrder: \n";
  //postorder(root, outputFile);
  //cout << "PreOrder: \n";
  preorder(root, outputFile);
  printLevelOrder(root, outputFile);

  //cleaning
  inFile.close();

  // if temp file was used for redirection or user input remove.
  if(remove( "temp.txt" ) == 0)
    perror("Deleting temp file used for redirection or user input");

  return 0;
}

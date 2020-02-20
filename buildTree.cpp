#include<vector>
#include<string>
#include"buildTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
using namespace std;

// A utility function to create a new BST node 
struct Node *newNode(char letter, string word, int depth) 
{
 
  struct Node *temp = new Node; 
  temp->letter = letter;
  temp->depth = depth; 
  temp->left = temp->right = NULL;
  temp->words.push_back(word);
  
  return temp; 
};
 
/* A utility function to insert a new Node with 
 *    given key in BST */

struct Node* insert(struct Node* node, char letter, string word, int depth) 
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) {
      return newNode(letter, word, depth); // first level of BST 
    }
    /* Otherwise, recur down the tree */
    if(letter == node->letter)
    {
      node->words.push_back(word);
    }
    if (letter < node->letter) 
    { 
        Node *lchild = insert(node->left, letter, word, (node->depth+1));
        node->left  = lchild; 
        // Set parent of root of left subtree 
        lchild->parent = node; 
    } 
    else if (letter > node->letter) 
    { 
        Node *rchild = insert(node->right, letter, word, (node->depth+1)); 
        node->right  = rchild; 
        // Set parent of root of right subtree 
        rchild->parent = node; 
    }
    /* return the (unchanged) Node pointer */
    return node;
}

Node* buildTree(string f_name){
  string words;
  ifstream inFile;
  char letter;
  struct Node *root = NULL;


  inFile.open(f_name.c_str());
  if(inFile){
    while(inFile >> words){
      for (int i=0; i<words.length(); i++){
        if(!islower(words.at(i))){
          perror("invalid input now exiting");
          return NULL;
        } else {
        }
      }
      letter = words.at(0);
      if (root == 0){
        root = insert(root, letter, words, 0);
      } else
        insert(root, letter, words, 0);
    }
  } else {
    cout << "Error, file did not open" << endl;
    return NULL;
  }

  inFile.close();
  return root;

}


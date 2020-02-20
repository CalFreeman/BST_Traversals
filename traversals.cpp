#include "traversals.h"
#include<cstdio>
#include<string>
#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<iostream>

using namespace std;

// function to visit nodes inorder
void inorder(struct Node *root, string fileName)
{
  string name = (fileName + ".inorder");
  //cout << fileName << "\n";
  FILE * pFile;
  pFile = fopen(name.c_str() ,"a");
  
  if (root != NULL){
  inorder(root->left, fileName);
    //fprintf(pFile,"%*c ", (root->depth*2)); 
    
  for (int i = 0; i < root->depth; i++){
    fprintf(pFile, "  ");
  }

  fprintf(pFile," %d %c ",root->depth, root->letter);
  int size = (int)root->words.size();
  for(int i = 0; i < size; i++){
    fprintf(pFile,"%s ", root->words[i].c_str());
  }
  fprintf(pFile, "\n");
  
  fclose(pFile);
        
  inorder(root->right, fileName);
  } else {
    return;
  }


};
/*
////////////////////////////////////////////////////////////////////
// function to visit nodes postorder
void postorder(Node *root, string fileName) {

  string name = (fileName + ".levelorder");
  //cout << fileName << "\n";
  FILE * pFilee;
  pFilee = fopen(name.c_str() ,"a");


  if(root == NULL) return;

  postorder(root->left, fileName);    // Visit left subtree
  //postorder(root->right, fileName);   // Visit right subtree

  //fprintf(pFilee, "%*c ", (root->depth*2));
  
  for (int i = 0; i < root->depth; i++){
    fprintf(pFilee, "  ");
  }

  fprintf(pFilee, " %d %c ",root->depth, root->letter);
  int size = (int)root->words.size();
  for(int i = 0; i < size; i++){
    fprintf(pFilee,"%s ", root->words[i].c_str());
  }
  fprintf(pFilee, "\n");
  
  postorder(root->right, fileName);   // Visit right subtree

  fclose(pFilee);
}
*/

void printLevelOrder(Node* root, string fileName)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i, fileName);  
}  

void printGivenLevel(Node* root, int level, string fileName)  
{  

  string name = (fileName + ".levelorder");
  //cout << fileName << "\n";
  FILE * pFilee;
  pFilee = fopen(name.c_str() ,"a");

  if (root == NULL)  
      return;
  if (level == 1){

    for (int i = 0; i < root->depth; i++){
      fprintf(pFilee, "  ");
    }

    fprintf(pFilee, " %d %c ",root->depth, root->letter);
    int size = (int)root->words.size();
    for(int i = 0; i < size; i++){
      fprintf(pFilee,"%s ", root->words[i].c_str());
    }
      fprintf(pFilee, "\n");
    //cout << root->letter << " ";  
  }else if (level > 1)   
  {  
    printGivenLevel(root->left, level-1, fileName);  
    printGivenLevel(root->right, level-1, fileName);  
  }
  fclose(pFilee);  
}  

int height(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree */
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}  


//////////////////////////////////////////////////////////////////////
// function to visit nodes preorder
void preorder(struct Node *root, string fileName) {
  
  string name = (fileName + ".preorder");
  //cout << fileName << "\n";
  FILE * pFilea;
  pFilea = fopen(name.c_str() ,"a");

  if(root == NULL) return;

  //fprintf(pFilea, "%*c ", (root->depth*2));
  for (int i = 0; i < root->depth; i++){
    fprintf(pFilea, "  ");
  }
  fprintf(pFilea, " %d %c ",root->depth, root->letter);
  int size = (int)root->words.size();
  for(int i = 0; i < size; i++){
    fprintf(pFilea, "%s ", root->words[i].c_str());
  }
  fprintf(pFilea, "\n");  

  fclose(pFilea);
  	
  preorder(root->left, fileName);     // Visit left subtree
  preorder(root->right, fileName);    // Visit right subtree
  
  
}



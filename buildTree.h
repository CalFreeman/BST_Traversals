#ifndef BUILDTREE_H
#define BUILDTREE_H
#include "node.h"

Node* newNode(char letter, string word, int depth);

Node* insert(struct Node* node, char letter, string word, int depth);

Node* buildTree(string f_name);

#endif

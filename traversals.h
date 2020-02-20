#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include "node.h"

void inorder(struct Node *root, string fileName);
void preorder(struct Node *root, string fileName);
void postorder(struct Node *root, string fileName);
void printGivenLevel(struct Node *root, int level, string fileName);
void printLevelOrder(struct Node *root, string fileName);
int height(struct Node *node);

#endif

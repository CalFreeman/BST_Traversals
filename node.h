#ifndef NODE_H
#define NODE_H
#include<vector>
#include<string>

using namespace std;

struct Node {
  char letter;
  int depth;
  vector<string> words;
  struct Node *left, *right, *parent;
  //vector<string> words;
};

#endif

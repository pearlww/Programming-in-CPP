#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <set>
#include <string>
using namespace std;

struct Node{
  std::string name;
  Node * left;
  Node * right;
};

void printSet(set<string> s);
void computeLeaves(Node *n, set<string> & leaves);
int countDescendants(Node * n);
#endif

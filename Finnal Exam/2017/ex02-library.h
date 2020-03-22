#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <set>
#include <string>

using namespace std;

/*
 * This data structure represents a node of a binary tree.
 * Each node can have up to two children, the left one, and the right one.
 * Special cases:
 * 	But it can have also just one child, or no children at all.
 * 	If it does not have the a left children, then the corresponding pointer has value nullptr
 * 	If it does not have the a right children, then the corresponding pointer has value nullptr
 * 	No particular order is considered among left and right: a node with one child only could point to it either via left, or via right
 */
struct Node{
	std::string name;
	Node * left;
	Node * right;
};

//Do not modify
/**
 * Print information on the set of strings s
 */
void printSet(set<string> s);

//Exercise 2 (a) Check and correct if necessary
/**
 * A 'parent node' is a node with at least one child.
 * This function populates the set of names of all 'parent nodes' met while navigating the tree starting from the current node n (including n itself, in case it has children).
 * For instance, the names of the parent nodes found starting from 'root' in the following tree are: root, n1 and n2. Instead, the names of the parent nodes found starting from n1 is just n1 itself
 * 			root
 * 			/  \
 * 		   n1   n2
 * 		  /       \
 * 		 n3        n4
 * The names of such 'parent nodes' have to be stored in the set parentNodes.
 */
void computeParentNodes(Node *n, set<string> & parents);

//Exercise 2 (b) Implement this function
/**
 * This function computes the set of names of all members of the subtree starting from node n (including n itself).
 * For instance, the names of the members of the subtree starting from node 'root' are: root, n1, n2, n3 and n4. Instead, the subtree starting from n3 contains only n3.
 * 			root
 * 			/  \
 * 		   n1   n2
 * 		  /       \
 * 		 n3        n4
 * Such names have are stored in the set memberNodes.
 */
void computeMembersOfSubTree(Node * n, set<string> & members);

#endif /* EX02_LIBRARY_H_ */

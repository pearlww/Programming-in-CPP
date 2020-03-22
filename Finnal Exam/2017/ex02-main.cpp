//============================================================================
// Name        : ex02.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Exercise 2 - Genealogy
//============================================================================

#include <iostream>
#include "ex02-library.h"
using namespace std;

void experimentParentNodes(Node * n){
	//Initialize the empty set of parent nodes
	set<string> parents;
	//Navigate the tree starting from node n, and add to parents all nodes that have at least one child
	computeParentNodes(n,parents);
	cout<<"The nodes with children starting from " << n->name << " are:\n";
	printSet(parents);
}

void experimentSubtree(Node * n){
	//Initialize the empty set of member nodes
	set<string> members;

	//Add to members all names of the nodes in the sub-tree with root n.
	computeMembersOfSubTree(n,members);
	cout<<"The sub-tree with root in "<< n->name << " contains:\n";
	printSet(members);
}

int main() {
	/* Create the following family tree
	 * 			Alice
	 * 			/  \
	 * 		  Bob  Carl
	 * 		  /       \
	 * 	   Daisy      Emma
	 */
	Node *Alice = new Node;
	Alice->name="Alice";
	Node *Bob = new Node;
	Bob->name="Bob";
	Node *Carl = new Node;
	Carl->name="Carl";
	Node *Daisy = new Node;
	Daisy->name="Daisy";
	Node *Emma = new Node;
	Emma->name="Emma";
	Alice->left=Bob;
	Alice->right=Carl;
	Bob->left=Daisy;
	Bob->right=nullptr;
	Carl->right=Emma;
	Carl->left=nullptr;
	Daisy->left=nullptr;
	Daisy->right=nullptr;
	Emma->left=nullptr;
	Emma->right=nullptr;

	cout << "Experiments about parent nodes\n";
	experimentParentNodes(Alice);
	experimentParentNodes(Bob);
	experimentParentNodes(Carl);
	experimentParentNodes(Daisy);
	experimentParentNodes(Emma);


	cout << "Experiments about sub-tree\n";
	experimentSubtree(Alice);
	experimentSubtree(Bob);
	experimentSubtree(Carl);
	experimentSubtree(Daisy);
	experimentSubtree(Emma);

	system("pause");
	return 0;
}
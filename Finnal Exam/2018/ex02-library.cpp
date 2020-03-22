#include "ex02-library.h"
#include <iostream>

//Do not modify
int Node::countChildren(){
	return children.size();
}

//Exercise 2 (a) Implement the constructor and getName()
Node::Node(string name){
	//put your code here
	this->name = name;
	return;
}

string Node::getName(){
	//put your code here
	return this->name;
}

//Exercise 2 (b) Implement this method
void Node::addChild(Node * child){
	//put your code here
	//int s = children.size();
	//children[s] = child;
	children.push_back(child);
	return;
}

//Exercise 2 (c) Check and correct if necessary
void Node::printParentNodes(){
	if (children.size() == 0)
		return;
	else{
		cout << this->name << ' ';
		for (int i = 0; i < children.size(); i++){
			children[i]->printParentNodes();
		}
	}
}

//Exercise 2 (d) Implement this method
void Node::printMembersOfSubTree(int generation){
	//put your code here	
	cout << this->name << ' ' << generation << ' ';
	if (children.size() == 0)
		return;
	else{
		generation += 1;
		for (int i = 0; i < children.size(); i++)
			children[i]->printMembersOfSubTree(generation);
	}
}

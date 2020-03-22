#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <vector>
#include <string>

using namespace std;

class Node{
	private:
		string name;
		vector<Node *> children;
	public:
		int countChildren();
		Node(string name);
		string getName();
		void addChild(Node * child);
		void printParentNodes();
		void printMembersOfSubTree(int generation=0);
};

#endif

#include <iostream>
#include "ex02-library.h"
using namespace std;

int main() {
	/* Bob's family tree from text */
	Node *Alice = new Node("Alice");
	Node *Bob = new Node("Bob");
	Node *Carl = new Node("Carl");
	Node *Daisy = new Node("Daisy");
	Node *Emma = new Node("Emma");
	Node *Frida = new Node("Frida");
	Node *Gabriel = new Node("Gabriel");
	Node *Hugo = new Node("Hugo");
	
	cout << "Alice's name: " << Alice->getName();
	cout << endl << endl;
	
	Alice->addChild(Bob);
	Alice->addChild(Carl);
	Alice->addChild(Daisy);
	Bob->addChild(Emma);
	Bob->addChild(Frida);
	Daisy->addChild(Gabriel);
	Frida->addChild(Hugo);
	
	cout << "Experiments about parent nodes";
	cout << endl << "Alice: ";
	Alice->printParentNodes();
	cout << endl << "Bob: ";
	Bob->printParentNodes();
	cout << endl << "Carl: ";	
	Carl->printParentNodes();
	cout << endl << "Daisy: ";
	Daisy->printParentNodes();
	cout << endl << "Emma: ";
	Emma->printParentNodes();
	cout << endl << "Frida: ";
	Frida->printParentNodes();	
	cout << endl << endl;
	
	cout << "Experiment about sub-tree";
	cout << endl << "Alice: ";
	Alice->printMembersOfSubTree();
	cout << endl << "Bob: ";
	Bob->printMembersOfSubTree();
	cout << endl << "Carl: ";	
	Carl->printMembersOfSubTree();
	cout << endl << "Daisy: ";
	Daisy->printMembersOfSubTree();
	cout << endl << "Emma: ";
	Emma->printMembersOfSubTree();	
	cout << endl << "Frida: ";
	Frida->printMembersOfSubTree();	
	cout << endl << "Gabriel: ";
	Gabriel->printMembersOfSubTree();	
	cout << endl << "Hugo: ";
	Hugo->printMembersOfSubTree();			
	cout << endl;
	
	system("pause");
	return 0;
}
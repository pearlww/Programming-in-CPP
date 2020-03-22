#include <iostream>
#include "ex04-library.h"

using namespace std;

int main() {
	/* Bob's family tree from text */
	Node<string> *Alice = new Node<string>("Alice", "01/01/1957");
	Node<string> *Bob = new Node<string>("Bob", "01/01/1977");
	Node<string> *Carl = new Node<string>("Carl", "01/01/1978");
	Node<string> *Daisy = new Node<string>("Daisy", "01/12/1978");
	Node<string> *Emma = new Node<string>("Emma","01/01/1998");
	Node<string> *Frida = new Node<string>("Frida","01/12/1998");
	Node<string> *Gabriel = new Node<string>("Gabriel","01/02/1998");
	Node<string> *Hugo = new Node<string>("Hugo","01/01/2018");
	
	cout << "Alice's name is: " << Alice->getName() << endl;
	cout << "Alice's value is: " << Alice->getValue() << endl;
	
	Alice->addChild(Bob);
	Alice->addChild(Carl);
	Alice->addChild(Daisy);
	Bob->addChild(Emma);
	Bob->addChild(Frida);
	Daisy->addChild(Gabriel);
	Frida->addChild(Hugo);
	
	cout << endl;
	cout << "Experiments about leaf nodes";
	cout << endl << "Alice: ";
	Alice->printLeafNodes();
	cout << endl << "Bob: ";
	Bob->printLeafNodes();
	cout << endl << "Carl: ";	
	Carl->printLeafNodes();
	cout << endl << "Daisy: ";
	Daisy->printLeafNodes();
	cout << endl << "Emma: ";
	Emma->printLeafNodes();
	cout << endl << "Frida: ";
	Frida->printLeafNodes();	
	cout << endl;

	cout << endl;	
	cout << "Experiment about sub-tree";
	cout << endl << "Alice: ";
	cout << Alice->countMembersOfSubTree();
	cout << endl << "Bob: ";
	cout << Bob->countMembersOfSubTree();
	cout << endl << "Carl: ";	
	cout << Carl->countMembersOfSubTree();
	cout << endl << "Daisy: ";
	cout << Daisy->countMembersOfSubTree();
	cout << endl << "Emma: ";
	cout << Emma->countMembersOfSubTree();
	cout << endl << "Frida: ";
	cout << Frida->countMembersOfSubTree();
	cout << endl;

	system("pause");	return 0;
}
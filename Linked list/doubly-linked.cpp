#include "doubly-linked.h"

using namespace std;


List::List(void){
	first = nullptr;
	return;
}

//if it is single linked list, we need another pointer to save the previous position
List::~List(void){
	for (Node *p = first; p != nullptr; p = p->next){
		delete p->prev;
	}
	first = nullptr;
	return;
}
void List::insert(int n){
	Node * newElement = new Node;
	newElement->val = n;
	newElement->next = nullptr;
	newElement->prev = nullptr;

	if (first == nullptr)
		first = newElement;
	else{
		Node *p;
		for (p = first; p->next!= nullptr; p = p->next);//get to the last node(p point to last node)
		p->next = newElement;
		newElement->prev = p;
	}

}
void List::reverse(void){ 
	Node *p;
	Node *q=nullptr;
	if (first == nullptr){
		return;
	}
	else if (first->next == nullptr){
		return;
	}
	else{
		for (p = first; p != nullptr; p = p->prev){
			q = p->prev;
			p->prev = p->next;
			p->next = q;
		}
		first = q->prev;
	}
	}

void List::print(void){
	for (Node *p = first; p != nullptr; p = p->next)
		cout << p->val << ' ';
	cout << endl;
}
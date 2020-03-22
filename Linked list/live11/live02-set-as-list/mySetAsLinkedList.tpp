//PUBLIC METHODS

// A constructor
template <class C>
Set<C>::Set(){
	// The empty set is just an empty list
	first = nullptr;
};

// check emptiness
template <class C>
bool Set<C>::empty(){
	return first == nullptr;
}

// add an element to the set
template <class C>
void Set<C>::insert(C e){

	// ignore if the set already contains the element
	if(contains(e)){
		return;
	}

	insertOrdered(e);

	return;
}

// check if an element is in the set
template <class C>
bool Set<C>::contains(C e){
	return containsR(e, first);
};

// delete an element from the set
template <class C>
void Set<C>::del(C e){
	delR(e,nullptr,first);
};

// extract some element from the set
template <class C>
C Set<C>::extract(void){
	if (empty()){
		// raise an error
		throw std::invalid_argument("trying to extract from empty set");
	}
	C e;
	e = first->content;
	del(e);
	return e;
};

// Destructors are needed since the internal representation
// is based on dynamically allocated list elements
template <class C>
Set<C>::~Set(){
	while(!empty()){
		extract();
	}
	return;
};

template <class C>
void Set<C>::print() {
	printR(first);
}

// This method tests if two sets are equal
// Is this a correct implementation?
template <class C>
bool Set<C>::operator ==(const Set &S) const {
	return equal(first,S.first);
}






//PRIVATE METHODS
template <class C>
void Set<C>::insertOrdered(C e){
	Node<int> * newElement;
	newElement = new Node<C>;
	newElement->content=e;
	newElement->next=nullptr;

	if(first==nullptr){
		//If the list is empty, the new element becomes the first and only element of the list.
		first=newElement;
	}
	else if(e < first->content){
		//If the new element is smaller than the first one, the new element becomes the new first element
		newElement->next=first;
		first=newElement;
	}
	else{
		//Otherwise I have to find the first element smaller than e (or I add the new element at the end of the list)
		insertOrderedRec(newElement,first,first->next);
	}
	return;
};

template <class C>
void Set<C>::insertOrderedRec(Node<C> * newElement, Node<C> * prevElement, Node<C> * currentElement){
	if(currentElement==nullptr){
		//I reached the end of the list without finding an element smaller than the new one. I just add the new element at the end of the list
		prevElement->next=newElement;
	}
	else if(newElement->content < currentElement->content){
		//I reached the first element of the list (currentElement) smaller than the new one.
		//I insert the new element before currentElement.
		prevElement->next=newElement;
		newElement->next=currentElement;
	}
	else{
		//Otherwise I have to consider the next element in the list
		insertOrderedRec(newElement,currentElement,currentElement->next);
	}
};

// check if an element is in the set
template <class C>
bool Set<C>::containsR(C e, Node<C> * p){

	// check if the list is empty
	if (p == nullptr) return false;

	// check if the first element is the one we are looking for
	if (p->content == e) return true;

	// check the rest of the list
	return containsR(e, p->next);
};

// delete an element from the set
template <class C>
void Set<C>::delR(C e, Node<C> * prevElement, Node<C> * currentElement){
	if(currentElement==nullptr){
		//I reached the last element of the list without finding the element to delete
		return;
	}
	else if (currentElement->content ==  e){
		//I found the node to delete

		// Save the pointer to the next element in q
		Node<C> * nextElement;
		nextElement = currentElement->next;
		// Delete the current element
		delete currentElement;

		if(prevElement==nullptr){
			first=nextElement;
		}
		else{
			prevElement->next=nextElement;
		}
		return;
	}
	else{
		//I have to consider the next element in the list
		delR(e,currentElement,currentElement->next);
	}
};

template <class C>
void Set<C>::printR(Node<C> * n) {
	if (n == nullptr){
		cout << endl;
		return;
	}
	cout << n->content << " ";
	printR(n->next);
	return;
}

template <class C>
bool Set<C>::equal(Node<C> * p, Node<C> * q) const {
	if(p == nullptr && q == nullptr) return true;
	if(p == nullptr) return false;
	if(q == nullptr) return false;
	if(p->content != q->content) return false;
	return equal(p->next,q->next);
}
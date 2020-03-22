#ifndef __linked_list__
#define __linked_list__

template<class C>
class Node {
public:
    C content;
    Node<C> * next;
};

#endif

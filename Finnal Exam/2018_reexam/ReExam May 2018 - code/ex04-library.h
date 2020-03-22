#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

template<class T>
struct Node{
  T content;
  Node<T> * next;
};

template <class T>
class mystack {
public:
  Node<T> * top;
  int size;
  mystack();
  ~mystack();
  int getSize();
  void print_top();
  void print();
  void push(T v);
  bool pop();
};
#endif

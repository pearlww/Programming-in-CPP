#include <iostream>
#include "ex04-library.h"

using namespace std;
  
int main() {
  mystack<int> stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  stack.print();

  cout <<"\n";
  cout << "The element on the top is: ";
  stack.print_top();
  cout <<"\n";

  do{
    cout <<"\n";
    cout << "pop(): ";
    if(stack.pop()){
      cout <<"succeeded\n";
    }
    else{
      cout <<"failed\n";
    }

    stack.print();
  }while(stack.getSize()>0);

  cout <<"\n";
  cout << "pop(): ";
  if(stack.pop()){
    cout <<"succeeded\n";
  }
  else{
    cout <<"failed\n";
  }
  system("pause");
  return 0;
}
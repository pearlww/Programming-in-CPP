#include <iostream>
#include "ex01-library.h"

using namespace std;

void testMoveRight(cell ** b,int n,int r,int c){
	bool moved=moveRight(b,n,r,c);
	cout<<"(" <<r<<','<<c<<") can";
	cout<<(moved?"":"'t") <<" move right"<<endl;
	printBoard(b,n);
}
void testMoveLeft(cell ** b,int n,int r,int c){
	bool moved=moveLeft(b,n,r,c);
	cout<<"(" <<r<<','<<c<<") can";
	cout<<(moved?"":"'t") <<" move left"<<endl;
	printBoard(b,n);
}

int main() {
	int n=8;
	cell ** b = createAndInitBoard(n);
	printBoard(b,n);

	cell ** copy = duplicateBoard(b,n);

	testMoveRight(b,n,2,1);
	testMoveRight(b,n,3,0);
	testMoveLeft(b,n,3,0);

	testMoveRight(b,n,5,6);
	testMoveLeft(b,n,4,7);

	cout <<"The copy:"<<endl;
	printBoard(copy,n);

	system("pause");
	return 0;
}
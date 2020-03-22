#include <iostream>
#include <vector>
#include "ex04-library.h"
using namespace std;

int main() {
	vector<Piece*> pieces;
	pieces.push_back(new BlackPiece(0,3));
	pieces.push_back(new BlackPiece(0,5));

	pieces.push_back(new WhitePiece(7,2));
	pieces.push_back(new WhitePiece(7,4));

	for(int i=0;i<pieces.size();i++){
		cout << "Piece " << i << " is ";
		cout << pieces[i]->getColor();
		cout << " (" << pieces[i]->printCode();
		cout << ")" << endl;
		
		cout << "It is in position ";
		pieces[i]->printPosition();

		pieces[i]->moveRight();
		cout << "After moving right: ";
		pieces[i]->printPosition();

		pieces[i]->moveLeft();
		cout << "After moving left: ";
		pieces[i]->printPosition();
		cout << endl;
	}
	system("pause");

}
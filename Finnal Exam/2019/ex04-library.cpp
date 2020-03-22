#include "ex04-library.h"
#include <iostream>


//Do not modify
Piece::~Piece(){}

//Do not modify
void Piece::printPosition(){
	cout << "(" << r << "," << c << ")" << endl;
}

//Exercise 4 (a) implement methods of WhitePiece
//put your code here
WhitePiece::WhitePiece(int r,int c){
	this->r = r;
	this->c = c;
}
string WhitePiece::getColor(){
	return "white";
}
string WhitePiece::printCode(){
	return "W";
}

void WhitePiece::moveLeft(){
	this->r--;
	this->c--;
}
void WhitePiece::moveRight(){
	this->r--;
	this->c++;
}
//Exercise 4 (b) implement methods of BlackPiece
//put your code here
BlackPiece::BlackPiece(int r, int c){
	this->r = r;
	this->c = c;
}
string BlackPiece::getColor(){
	return "black";
}
string BlackPiece::printCode(){
	return "B";
}

void BlackPiece::moveLeft(){
	this->r++;
	this->c++;
}
void BlackPiece::moveRight(){
	this->r++;
	this->c--;
}
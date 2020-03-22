#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	//put your code here
	cell ** board = new cell *[n];
	for (int i = 0; i<n; i++){
		board[i] = new cell[n];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			board[i][j].color = computeColor(i, j);
			if (board[i][j].color == dark && i < 3)
				board[i][j].status = blackPiece;
			else if (board[i][j].color == dark && i > n-4)
				board[i][j].status = whitePiece;
			else
				board[i][j].status = empty;
		}
	}

	return board;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	//put your code here
	cell ** newboard = new cell *[n];
	for (int i = 0; i<n; i++){
		newboard[i] = new cell[n];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			newboard[i][j].color = A[i][j].color;
			newboard[i][j].status = A[i][j].status;
		}
	}

	return newboard;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A,int n,int r, int c){
	//put your code here
	if (A[r][c].status == empty)
		return false;
	if (A[r][c].status==blackPiece){
		if (r + 1>n - 1 || c - 1 < 0)
			return false;
		else if (A[r + 1][c - 1].status != empty)
			return false;
		else{
			A[r][c].status = empty;
			A[r + 1][c - 1].status = blackPiece;
			return true;
		}
	}
	else{
		if (r - 1<0 || c + 1 >n-1)
			return false;
		else if (A[r -1][c + 1].status != empty)
			return false;
		else{
			A[r][c].status = empty;
			A[r - 1][c + 1].status = whitePiece;
			return true;

		}
	}
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){
	//put your code here
	if (A[r][c].status == empty)
		return false;
	if (A[r][c].status==blackPiece){
		if (r + 1>n - 1 || c + 1 >n-1)
			return false;
		else if (A[r + 1][c + 1].status != empty)
			return false;
		else{
			A[r][c].status = empty;
			A[r + 1][c + 1].status = blackPiece;
			return true;
		}
	}
	else{
		if (r - 1<0 || c - 1 < 0)
			return false;
		else if (A[r - 1][c - 1].status != empty)
			return false;
		else{
			A[r][c].status = empty;
			A[r - 1][c - 1].status = whitePiece;
			return true;

		}
	}
}

//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case empty:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
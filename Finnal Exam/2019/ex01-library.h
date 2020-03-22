#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

#include <iostream>

enum cellColor {bright, dark};
enum cellStatus {empty, whitePiece, blackPiece};
struct cell{
	cellColor color;
	cellStatus status;
};

cell ** createAndInitBoard(int n);
cell ** duplicateBoard(cell ** A, int n);
bool moveRight(cell ** A,int n,int r, int c);
bool moveLeft(cell ** A,int n,int r, int c);

cellColor computeColor(int r,int c);
void printBoard(cell ** A, int n);

#endif /* EX01_LIBRARY_H_ */
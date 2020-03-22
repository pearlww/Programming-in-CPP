#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(void){

  // Matrix representing a picture
  int n = 2;
  int m = 3;
  unsigned int **A = createMatrix(n,m);

  // Setting all values to 255 (white)
  fillWhite(A,n,m);
  // Setting some values in the matrix
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m;j++){
      A[i][j]=i*n+j;
    }
  }
  
  // Printing the matrix
  printMatrix(A,n,m,"original matrix");
  cout << endl;

  //Making the figure brighter
  for(int i=1;i<3;i++){
    lighten(A,n,m);
    printMatrix(A,n,m,"brighter matrix (" 
      + to_string(i)+")");
    cout << endl;
  }

  //Making the figure darker
  for(int i=1;i<4;i++){
    darken(A,n,m);
    printMatrix(A,n,m,"darker matrix (" 
      + to_string(i)+")");
    cout << endl;
  }

  //Deallocating A
  deallocateMatrix(A,n);

  system("pause");
  return 0;
}
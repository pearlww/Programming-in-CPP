//============================================================================
// Name        : live02-enrichingArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : From arrays to vectors - Intuition on why we should use vectors. Ad-hoc code to make arrays more user friendly
//============================================================================

#include <iostream>
using namespace std;

void printEntry(int array[],int i,int size);
int* setEntryValue(int *array,int i,int size, int value);
//Even more difficult:
int* addEntry(int *array,int i,int size, int value);
int* removeEntry(int *array,int i,int size);

int main() {
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


    int size=3;
    int *array = new int[size];
    array[0]=0;
    array[1]=1;
    array[2]=2;
    printEntry(array,1,size);
    printEntry(array,5,size);

    array = setEntryValue(array,2,size,100);
    array = setEntryValue(array,5,size,100);

    for(int i=0;i<5+1;i++){
        cout << array[i] << ' ';
    }

    return 0;

}

void printEntry(int array[],int i,int size){
    if(i<0 || i>=size){
        cout<< "OUT-OF-BOUND-ERROR!\n";
    }
    else{
        cout<< array[i] << "\n";
    }
}

int* setEntryValue(int *array,int i,int size, int value){
    int* arrayTwo = array;
    if(i<0){
        cout<< "OUT-OF-BOUND-ERROR!\n";
    }
    else if(i>=size){
        arrayTwo = new int[i+1];
        for(int j=0;j<i;j++){
            if(j<size){
                arrayTwo[j] = array[j];
            }
            else{
                arrayTwo[j]=0;
            }
        }
    }

    arrayTwo[i]=value;
    return arrayTwo;
}


#include <iostream>
#include <stdlib.h>     /* Library containing functions such as
                           rand (a generator of random numbers) */
#include <string>
using namespace std;


// We declare here an enumeration type called "material"
typedef enum {wood,stone} material;
            // 0     1
// In C++ we can also write the "equivalent" declaration
enum materialTwo {woodTwo,stoneTwo};

// We declare here a record type called "field"
typedef struct {
	int x;
	int y;
	bool isWall;
	material type;
} field;
// As above, we can write
struct fieldTwo {
	int x;
	int y;
	bool isWall;
	material type;
};

// this function translates materials into characters
// in order to display them
char character(material m){
	// Switching is a sort of if_then_else
	// Useful when there many cases.
	//Remember to always break each branch!
	switch(m){
	case wood:
		return ' ';
	case stone:
		return '#';
	default:
		return '?';
	}
}

void printField(field f){
	string typeStr="wood";
	if(f.type == stone){
		typeStr = "stone";
	}
	cout << "Position (" << f.x << "," << f.y << ") is made of " << typeStr <<".";
	if(f.isWall){
		cout << " It contains a wall.";
	}

	cout << "\n";
}

int main(){

	int n = 0;
	int m = 0;

	cout << "character of wood is: '" << character(wood) << "'\n";
	cout << "character of stone is: '" << character(stone)<< "'\n";

	field fieldA;
	fieldA.x=1;
	fieldA.y=1;
	fieldA.isWall=true;
	fieldA.type=wood;

	field fieldB ={
			1, 1, true, wood
	};

	printField(fieldA);
	printField(fieldB);

	cout << "Enter the height of the field: ";
	cin >> n;
	cout << "Enter the width of the field: ";
	cin >> m;

	field **playground = new field*[n];
	for (int i=0; i<n; i++){
		playground[i] = new field[m];
	}
	//or use: field playground[m][n]; 

	// building the playground (stone perimeter, wood inside)
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			// Note here how we access an element of an array
			// with playground[i][j]
			// and how we access the fields of a (field) record
			// with .x, .y, etc.
			playground[i][j].x=i;
			playground[i][j].y=j;
			playground[i][j].isWall= (i==0||i==(n-1)||j==0||j==(m-1)||(rand()%4)==0);
			if (playground[i][j].isWall){
				playground[i][j].type=stone;
			}
			else{
				playground[i][j].type=wood;
			}
		}
	}

	// printing the playground
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << character(playground[i][j].type);
		}
		cout << endl;
	}

	// when memory is dynamically allocated, you have to deallocate it explicitly!
	for (int i=0; i<n; i++){
		delete[] playground[i];
	}
	delete[] playground;
	system("pause");
	return 0;

}

//####
//#  #
//#  #
//# ##
//####

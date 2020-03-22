//============================================================================
// Name        : live05-fileIO.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Example on how to read/write in files
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	string fileName;




	cout << "Which file would you like to read?\n";
	cin >> fileName;

	ifstream infile;
	infile.open(fileName);

	//infile.open(fileName.c_str());
	if(infile.fail()){
		cout << "I could not open the file " << fileName <<"\n";
		cout << "I give you another chance. Which file would you like to read?\n";
		cin >> fileName;
		infile.clear();
		infile.open(fileName);
		if(infile.fail()){
			cout << "I could not open the file " << fileName <<"\n";
			return 1;
		}
	}


	cout <<"\n\nRead using infile >> s;\n\n";

	string s;
	while(!infile.fail()){
		infile >> s;
		if(infile.fail()){
			break;
		}
		else{
			cout << s;
		}

	}

	infile.close();

	cout <<"\n\nRead using int character = infile.get();\n\n";
	infile.open(fileName);
	while(!infile.fail()){
		int character = infile.get();
		if(infile.fail()){
			break;
		}
		else{
			cout << (char)character;
		}

	}

	infile.unget();





	infile.close();

	cout <<"\n\nRead using int character = infile.get();\n\n";
	infile.open(fileName);
	int ch;
	while((ch=infile.get())!=EOF){
		cout << (char)ch;
	}
	infile.close();


	cout <<"\n\nRead using getline(infile,line)\n\n";
	infile.open(fileName);

	ofstream outfile;
	outfile.open("copy.txt");

	string line;
	while(!infile.fail()){
		getline(infile,line);
		if(infile.fail()){
			break;
		}
		else{
			cout << line;
			cout << "\n";
			outfile << line;
			outfile << "\n";
		}
	}
	infile.close();


	/*
	ofstream outfile;
	outfile.open("copy.txt");
	outfile.put(60);
	outfile.put('5');
	 */



	outfile.close();

	return 0;
}

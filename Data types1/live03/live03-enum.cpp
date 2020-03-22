#include <iostream>
#include <string>
using namespace std;

enum direction {
	North, East, South, West
//  0       1       2     3
};

direction TurnRight(direction dir);
direction TurnLeft(direction dir);
string dirToText(direction dir);

int main() {
	direction dir = North;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	bool continueIteration = true;
	while(true){
		char turn;
		cout << "Turn right (r), turn left (l), or quit (q):\n";
		cin >> turn;
		direction oldDir = dir;
		if(turn == 'r'){
			dir = TurnRight(dir);
			//cout << "After turning right from " << oldDir << " I am going towards " << dir << "\n";
			cout << "After turning right from " << dirToText(oldDir) << " I am going towards " << dirToText(dir) << "\n";
		}
		else if(turn == 'l'){
			dir = TurnLeft(dir);
			//cout << "After turning left from " << oldDir << " I am going towards " << dir << "\n";
			cout << "After turning left from " << dirToText(oldDir) << " I am going towards " << dirToText(dir) << "\n";
		}
		else{
			cout << "I quit going towards " << dir << "\n";
			continueIteration=false;
		}
	}

	return 0;
}

/**
 * This moves your direction to the cardinal point on the right of the current direction (dir). E.g., if dir is North, then newDir will be East
 */
direction TurnRight(direction dir){
	int newDir = (dir+1)%4;
	return (direction)newDir;
}

/**
 * This moves your direction to the cardinal point on the left of the current direction (dir).
 * Never forget to use 'break' statements!
 */
direction TurnLeft(direction dir){
	direction newDir;
	switch (dir) {
		case North:
			newDir=West;
			break;
		case West:
			newDir=South;
			break;
		case South:
			newDir=East;
			break;
		case East:
			newDir=North;
			break;
		default:
			break;
	}
	return newDir;
}
/**
 * This returns a string representation of the input direction dir.
 */
string dirToText(direction dir){
	string s = "unknown";
	switch (dir) {
			case North:
				s="North";
				break;
			case West:
				s="West";
				break;
			case South:
				s="South";
				break;
			case East:
				s="East";
				break;
			default:
				break;
		}
	return s;
}

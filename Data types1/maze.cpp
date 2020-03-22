#include <iostream>
#include <string>

using namespace std;

 int n = 12;int m = 16;
 int a = 5; int b = 5;

typedef struct{
	int x, y;
	bool IsWall;
	bool IsMan;
} filed;

//char character(){
//	switch (){
//	case 
//	}
//}
void PrintGround(filed **f){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			f[i][j].x = i;
			f[i][j].y = j;
			f[i][j].IsWall = (i == 0&&j!=3|| i == (n - 1) || j == 0 || j == (m - 1));
			f[i][j].IsMan = (i == a && j == b);

		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (f[i][j].IsWall)
				cout << "*";
			else if (f[i][j].IsMan)
				cout << "O";
			else
				cout << " ";
		}
		cout << endl;
	}
}
int main(){



	filed **playground = new filed*[n];
	for (int i = 0; i < n; i++)
		playground[i] = new filed[m];

	int q = 1;
	while (q){
		PrintGround(playground);
        char c;
		cin >> c;
		if (c == 'l'&& b > 1)
			b--;
		else if (c == 'r'&& b<(m-2))
			b++;
		else if (c == 'u'&& (a>1||(a==1&&b==3)) )
			a--;
		else if (c == 'd'&& a <(n - 2))
			a++;
		else if (c == 'q')
			q = 0;
			
		}

	for (int i = 0; i < n; i++)
		delete[] playground[i];

	delete[] playground;
	system("pause");
	return 0;
}




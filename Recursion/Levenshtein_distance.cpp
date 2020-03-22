#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int levenshtein_distance(string s, string t){
	
	if (s.size() == 0)
		return t.size();
	if (t.size() == 0)
		return s.size();
	else{
		string ss(s.begin() + 1, s.end());
		string tt(t.begin() + 1, t.end());
		int d1 = levenshtein_distance(ss, t);
		int d2 = levenshtein_distance(s, tt);
		int f = 1;
		if (s[0] == t[0])
			f = 0;
		int d3 = levenshtein_distance(ss, tt) + f;
		//int d3 = levenshtein_distance(ss, tt) + (s[0] ^ t[0]);  
		return min(min(d1 + 1, d2 + 1), d3);


	}
}

int main(){
	
	string s, t;
	cin >> s >> t;
	cout <<( s[0] ^ t[0]);  //input red pen,  why output is 2,not 1?
	//cout << levenshtein_distance(s, t) << endl;

	system("pause");
	return 0;
}

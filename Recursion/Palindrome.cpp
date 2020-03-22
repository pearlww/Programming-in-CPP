#include <iostream>
#include <vector>

using namespace std;

bool palindrome(vector<int> &v, int start,int end){
	if (v[start] != v[end])
		return false;
	else if (start==end )
		return true;
	else if (start + 1 == end)
		return true;
	else{ 
		return palindrome(v, start + 1, end - 1);
	}
		
}
int main(){
	int n;
	vector<int> v ;

	while (1){

        cin >> n;
		if (cin.fail())
			break;
		else{		
			v.push_back(n);
		}
			
	}
	if (palindrome(v,0,v.size()-1))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	system("pause");
	return 0;
}
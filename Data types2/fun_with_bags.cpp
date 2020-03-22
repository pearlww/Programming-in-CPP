#include<iostream>
#include<string>
#include<set>

using namespace std;
enum action{add,del,qry,quit,none};

action str2action(string s){
	if (s == "add") return add;
	if (s == "del") return del;
	if (s == "qry") return qry;
	if (s == "quit") return quit;
	return none;
}
struct bag{
	//set<int> bag_set;
	//multiset<int> bag_set;
	multiset<double> bag_set;
};


void search(bag b,double n){

	int x= b.bag_set.count(n);

	if (x != 0 )
		cout << "T";
	else
		cout << "F";
}

//call by reference
void delete_key(bag &b,double n){

     //b.bag_set.erase(n);
	multiset<double>::iterator pos = b.bag_set.find(n);
	if (pos!=b.bag_set.end())
	    b.bag_set.erase(pos);//remove one element with value n
}

//call by reference
void update(bag &b,action s,double n){
	switch (s){
	case add:
		b.bag_set.insert(n);
		break;
	case del:	
		delete_key(b, n);
		break;
	case qry:
		search(b, n);
		break;
	case quit:
		break;
	default:
		break;
	}
}
 
int main(){

	bag my_bag;
	string my_action_str;
	action my_action;
	double num;
	int flag = 1;
	while (flag){
       cin >> my_action_str;
	   my_action = str2action(my_action_str);
	   if (my_action==quit){
		   flag = 0;
		   continue;
	   }
	   else{
		   cin >> num;
		   update(my_bag, my_action, num);
	   }
		   
	}
	system("pause");
	return 0;
}
//============================================================================
// Name        : liveXX-myBag-oop.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MyBag.h"
//using namespace std;


/*
  newBag
  newBag
  add 0 1
  add 1 10
 */

int main(){

    vector<myBag> bags;
    string my_act_str;
    action my_act;
    string object;
    int bag_num;

    while(true){

        // display the contents of the currenty bags
        for(int i=0; i<bags.size(); i++){
            cout << "BAG #" << i << " = ";
            bags[i].display();
        }

        cout << "What's next? (actions = newBag, fuse, add <myBag> <x> , del <myBag> <x>, sortIt <myBag> , makeSet <myBag> , read <myBag>  <file>, flip <myBag> )" << endl;
        cin >> my_act_str;
        my_act=str2action(my_act_str);

        if (my_act == newBag){
            bags.push_back(*new myBag(0));
            continue;
        }

        if (my_act == fuse){
            while(bags.size()>1){
                while(!bags[bags.size()-1].empty()){
                    bags[0].add(bags[bags.size()-1].pick());
                }
                bags.erase(bags.end()-1);
            }
            continue;
        }

        cin >> bag_num;
        // some actions require an extra argument
        if (my_act==add || my_act==del || my_act==read){
            cin >> object;
        }

        // resolve the action
        if(bag_num>=0 && bag_num<bags.size()){
            bags[bag_num].update(my_act,object);
        }

    }

    return 0;

}

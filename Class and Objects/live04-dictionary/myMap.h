#ifndef MYMAP_H_
#define MYMAP_H_

#include<vector>
#include<string>

using namespace std;

#define NOT_FOUND "Entry Not Found"

class myMap{
private:
  vector<string> keys;
  vector<string> entries;
  string name;
  int contains(string key) const;
public:
  myMap(string name);
  ~myMap();
  void insert(string key, string entry);
  string find(string key);
};

#endif /* MYMAP_H_ */

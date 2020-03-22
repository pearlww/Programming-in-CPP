#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <map>
#include <set>
using namespace std;

class MovieEvaluations {
private:
  set<string> movies;
  map<string,double> movieToEvaluation;
public:
  MovieEvaluations();
  bool hasEvaluation(string movie);
  void print();
  bool addEvaluation(string movie, double evaluation);
  bool updateEvaluation(string movie, double newEvaluation);
  string computeVerboseEvaluation(string movie);
};

#endif /* EX03_LIBRARY_H_ */
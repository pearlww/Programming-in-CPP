#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
using namespace std;

class TemperatureScalesConverter {
private:
  vector<double> CTemperatures;
  vector<double> FTemperatures;
public:
  TemperatureScalesConverter();
  void print();
  double convertToF(double CTemperature);
  double convertToC(double FTemperature);
  bool addMeasurement(string scale, double temperature);
};

#endif /* EX03_LIBRARY_H_ */

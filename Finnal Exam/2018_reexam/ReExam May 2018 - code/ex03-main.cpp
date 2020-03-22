#include <iostream>
#include "ex03-library.h"

int main() {
  MovieEvaluations me;

  cout << "\nExecuting addEvaluation(\"Alien\",-2.5);\n";
  me.addEvaluation("Alien",-2.5);
  me.print();

  cout << "\nExecuting addEvaluation(\"Alien\",12.5);\n";
  me.addEvaluation("Alien",12.5);
  me.print();

  cout << "\nExecuting addEvaluation(\"Alien\",7.6);\n";
  me.addEvaluation("Alien",7.6);
  me.print();

  cout << "\nExecuting addEvaluation(\"Alien\",6.6);\n";
  me.addEvaluation("Alien",6.6);
  me.print();

  cout << "\nExecuting updateEvaluation(\"Alien\",6.6);\n";
  me.updateEvaluation("Alien",6.6);
  me.print();

  cout << "\nExecuting updateEvaluation(\"The Wizard of Oz\",8);\n";
  me.addEvaluation("The Wizard of Oz",8);
  me.print();

  cout <<"\n\n";
  cout << "The Godfather is " << me.computeVerboseEvaluation("The Godfather") << "\n";
  cout << "Alien is " << me.computeVerboseEvaluation("Alien") << "\n";
  cout << "The Wizard of Oz is " << me.computeVerboseEvaluation("The Wizard of Oz") << "\n";
  cout << "Pulp Fiction is " << me.computeVerboseEvaluation("Pulp Fiction") << "\n";

  system("pause");
  return 0;
}
#include <iostream>
#include "ExponentialFlow.h"

using namespace std;

ExponentialFlow::ExponentialFlow(System *from = NULL, System *to = NULL, double f = 0.0) {
  source = from;
  target = to;
  factor = f;
}

double ExponentialFlow::getFactor() {
  return factor;
}

void ExponentialFlow::setFactor(double f) {
  factor = f;
}

double ExponentialFlow::execute() {
  return (factor * getSource()->getValue());
}
#include <iostream>
#include "LogisticFlow.h"

using namespace std;

LogisticFlow::LogisticFlow(System *from = NULL, System *to = NULL, double f = 0.0, double v = 0.0) {
  source = from;
  target = to;
  factor = f;
  maxValue = v;
}

double LogisticFlow::getFactor() {
  return factor;
}

double LogisticFlow::getMaxValue() {
  return maxValue;
}

void LogisticFlow::setFactor(double f) {
  factor = f;
}

void LogisticFlow::setMaxValue(double v) {
  maxValue = v;
}

double LogisticFlow::execute() {
  return (factor * getTarget()->getValue() * (1 - (getTarget()->getValue() / maxValue)));
}

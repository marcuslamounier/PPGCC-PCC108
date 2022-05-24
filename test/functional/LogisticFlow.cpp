/**
 * @file LogisticFlow.cpp
 *
 * @brief Implementation of class LogisticFlow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include "LogisticFlow.h"

using namespace std;

LogisticFlow::LogisticFlow() {
  source = NULL;
  target = NULL;
  factor = 0.01;
  maxValue = 70.0;
}

LogisticFlow::LogisticFlow(System *from = NULL, System *to = NULL) {
  source = from;
  target = to;
  factor = 0.01;
  maxValue = 70.0;
}

LogisticFlow::LogisticFlow(System *from = NULL, System *to = NULL, double f = 0.0, double maxV = 0.0) {
  source = from;
  target = to;
  factor = f;
  maxValue = maxV;
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

void LogisticFlow::setMaxValue(double maxV) {
  maxValue = maxV;
}

double LogisticFlow::execute() {
  return (factor * getTarget()->getValue() * (1 - (getTarget()->getValue() / maxValue)));
}

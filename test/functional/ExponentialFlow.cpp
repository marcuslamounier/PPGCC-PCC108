/**
 * @file ExponentialFlow.cpp
 *
 * @brief Implementation of class ExponentialFlow.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include "ExponentialFlow.h"

using namespace std;

ExponentialFlow::ExponentialFlow() {
  source = NULL;
  target = NULL;
  factor = 0.01;
}

ExponentialFlow::ExponentialFlow(System *from, System *to) {
  source = from;
  target = to;
  factor = 0.01;
}

ExponentialFlow::ExponentialFlow(System *from, System *to, double f) {
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

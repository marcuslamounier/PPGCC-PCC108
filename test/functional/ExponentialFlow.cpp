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
  pImpl_ = new FlowBody();
  pImpl_->setSource(NULL);
  pImpl_->setSource(NULL);
  pImpl_->setLastValue(0.0);
  factor = 0.01;
}

ExponentialFlow::ExponentialFlow(System *from, System *to) {
  pImpl_ = new FlowBody(from, to);
  pImpl_->setLastValue(0.0);
  factor = 0.01;
}

ExponentialFlow::ExponentialFlow(System *from, System *to, double f) {
  pImpl_ = new FlowBody(from, to);
  pImpl_->setLastValue(0.0);
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

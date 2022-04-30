/**
 * @file Flow.cpp
 *
 * @brief Implementation of class Flow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include "Flow.h"

using namespace std;

Flow::Flow (const Flow &flow) {
  if (this == &flow) {
    return;
  }
  source = flow.source;
  target = flow.target;
  lastValue = flow.lastValue;
}

Flow& Flow::operator=(const Flow &flow) {
  if (this == &flow) {
    return *this;
  }

  setSource(flow.source);
  setTarget(flow.target);
  setLastValue(flow.lastValue);

  return *this;
}

Flow::Flow(){
  source = NULL;
  target = NULL;
}

Flow::Flow(System *from = NULL, System *to = NULL, double lv = 0.0) {
  source = from;
  target = to;
  lastValue = lv;
}

Flow::~Flow(){}

System* Flow::getSource() {
  return source;
}

System* Flow::getTarget() {
  return target;
}

double Flow::getLastValue() {
  return lastValue;
}

void Flow::setSource(System *s) {
  source = s;
}

void Flow::setTarget(System *s) {
  target = s;
}

void Flow::setLastValue(double v) {
  lastValue = v;
}

void Flow::clearSource() {
  source = NULL;
}

void Flow::clearTarget() {
  target = NULL;
}

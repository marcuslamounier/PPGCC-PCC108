#include "Flow.h"
#include <iostream>

using namespace std;

Flow::Flow (const Flow &flow) {
  if (this == &flow) {
    return;
  }
  origin = NULL;
  target = NULL;
}

Flow& Flow::operator=(const Flow &flow) {
  if (this == &flow) {
    return *this;
  }

  setOrigin(NULL);
  setTarget(NULL);

  return *this;
}

Flow::Flow(){
  origin = NULL;
  target = NULL;
}

Flow::Flow(System *from, System *to) {
  origin = from;
  target = to;
}

Flow::~Flow(){}

System* Flow::getOrigin() {
  return origin;
}

System* Flow::getTarget() {
  return target;
}

void Flow::setOrigin(System *s) {
  origin = s;
}

void Flow::setTarget(System *s) {
  target = s;
}

void Flow::clearOrigin(){
  origin = NULL;
}

void Flow::clearTarget(){
  target = NULL;
}

double Flow::execute(){
  return 0.0;
}
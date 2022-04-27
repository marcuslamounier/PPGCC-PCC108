#include <iostream>
#include "Flow.h"

using namespace std;

Flow::Flow (const Flow &flow) {
  if (this == &flow) {
    return;
  }
  source = NULL;
  target = NULL;
}

Flow& Flow::operator=(const Flow &flow) {
  if (this == &flow) {
    return *this;
  }

  setSource(NULL);
  setTarget(NULL);

  return *this;
}

Flow::Flow(){
  source = NULL;
  target = NULL;
}

Flow::Flow(System *from = NULL, System *to = NULL) {
  source = from;
  target = to;
}

Flow::~Flow(){}

System* Flow::getSource() {
  return source;
}

System* Flow::getTarget() {
  return target;
}

void Flow::setSource(System *s) {
  source = s;
}

void Flow::setTarget(System *s) {
  target = s;
}

void Flow::clearSource() {
  source = NULL;
}

void Flow::clearTarget() {
  target = NULL;
}

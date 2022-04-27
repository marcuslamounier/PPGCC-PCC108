#include <iostream>
#include "LogisticFlow.h"

using namespace std;

LogisticFlow::LogisticFlow(System *from = NULL, System *to = NULL) {
  source = from;
  target = to;
}

double LogisticFlow::execute() {
  return (0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue() / 70)));
}

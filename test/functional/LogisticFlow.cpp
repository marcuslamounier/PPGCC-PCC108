#include <iostream>
#include "ExponentialFlow.h"

using namespace std;

ExponentialFlow::ExponentialFlow(System *from = NULL, System *to = NULL) {
  source = from;
  target = to;
}

double ExponentialFlow::execute() {
  return (0.01 * getSource()->getValue());
}

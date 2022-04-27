#ifndef EXPONENTIAL_FLOW_H
#define EXPONENTIAL_FLOW_H

#include "../../src/Flow.h"

class ExponentialFlow: public Flow {
  public:
    ExponentialFlow(System* from, System *to);
    double execute();
};

#endif

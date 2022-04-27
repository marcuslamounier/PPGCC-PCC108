#ifndef LOGISTIC_FLOW_H
#define LOGISTIC_FLOW_H

#include "../../src/Flow.h"

class LogisticFlow: public Flow {
  public:
    LogisticFlow(System* from, System *to);
    double execute();
};

#endif

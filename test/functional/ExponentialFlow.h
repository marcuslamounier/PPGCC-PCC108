#ifndef EXPONENTIAL_FLOW_H
#define EXPONENTIAL_FLOW_H

#include "../../src/Flow.h"

class ExponentialFlow: public Flow {
  private:
    double factor;
  public:
    ExponentialFlow(System* from, System *to, double f);

    double getFactor();
    void setFactor(double f);

    double execute();
};

#endif

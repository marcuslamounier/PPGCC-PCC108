#ifndef EXPONENTIAL_FLOW_H
#define EXPONENTIAL_FLOW_H

#include "../../src/FlowImplement.h"

class ExponentialFlow: public FlowImplement {
  private:
    double factor;
  public:
    ExponentialFlow();
    ExponentialFlow(System* from, System *to, double f);

    double getFactor();
    void setFactor(double f);

    double execute();
};

#endif

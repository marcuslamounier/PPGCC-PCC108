#ifndef LOGISTIC_FLOW_H
#define LOGISTIC_FLOW_H

#include "../../src/Flow.h"

class LogisticFlow: public Flow {
  private:
    double factor;
    double maxValue;
  public:
    LogisticFlow(System *from, System *to, double f, double v);

    double getFactor();
    double getMaxValue();
    void setFactor(double f);
    void setMaxValue(double v);

    double execute();
};

#endif

#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include "System.h"

using namespace std;

class Flow {
  protected:
    System* source;
    System* target;

  public:
    Flow();
    Flow(System *from, System *to);
    virtual ~Flow();

    System* getSource();
    System* getTarget();
    void setSource(System *s);
    void setTarget(System *s);

    void clearSource();
    void clearTarget();
    virtual double execute() = 0;

  private:
    Flow (const Flow& flow);
    Flow& operator=(const Flow& flow);
};

#endif
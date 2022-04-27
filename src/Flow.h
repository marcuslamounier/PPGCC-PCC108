#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include "System.h"

using namespace std;

class Flow {
  protected:
    System* origin;
    System* target;

  public:
    Flow();
    Flow(System *from = NULL, System *to = NULL);
    virtual ~Flow();

    System* getOrigin();
    System* getTarget();
    void setOrigin(System *s);
    void setTarget(System *s);

    void clearOrigin();
    void clearTarget();
    double execute();

  private:
    Flow (const Flow& flow);
    Flow& operator=(const Flow& flow);
};

#endif

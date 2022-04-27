#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "System.h"
#include "Flow.h"

using namespace std;

class Model {
  protected:
    int time;
    vector<System*> systems;
    vector<Flow*> flows;

  public:
    typedef vector<System*>::iterator iterSystem;
    typedef vector<Flow*>::iterator iterFlow;

    Model();
    Model(int t);
    Model (const Model& model);
    ~Model();

    iterSystem firstSystem();
    iterSystem lastSystem();
    iterFlow firstFlow();
    iterFlow lastFlow();

    int getTime() const;
    void setTime(int t);
    void incrementTime(int inc);
    
    void addSystem(System *s);
    void addFlow(Flow *f);
    void removeSystem(System *s);
    void removeFlow(Flow *f);
    void execute(int start, int final, int incr);

  private:
    Model& operator=(const Model& model);
};

#endif
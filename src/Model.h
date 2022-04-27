#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "System.h"
#include "Flow.h"

using namespace std;

class InterfaceModel {
  public:
    typedef vector<System*>::iterator iterSystem;
    typedef vector<Flow*>::iterator iterFlow;

    virtual iterSystem begSystems() = 0;
    virtual iterSystem endSystems() = 0;
    virtual iterFlow begFlows() = 0;
    virtual iterFlow endFlows() = 0;

    virtual int getTime() const = 0;
    virtual void setTime(int t) = 0;
    virtual void incrementTime(int inc) = 0;

    virtual void addSystem(System *s) = 0;
    virtual void addFlow(Flow *f) = 0;
    virtual void removeSystem(System *s) = 0;
    virtual void removeFlow(Flow *f) = 0;
    virtual void execute(int start, int final, int incr) = 0;
};

class Model: public InterfaceModel {
  protected:
    int time;
    vector<System*> systems;
    vector<Flow*> flows;

  public:
    Model();
    Model(int t);
    ~Model();
    
    Model& operator=(const Model& model);

    iterSystem begSystems();
    iterSystem endSystems();
    iterFlow begFlows();
    iterFlow endFlows();

    int getTime() const;
    void setTime(int t);
    void incrementTime(int inc);
    
    void addSystem(System *s);
    void addFlow(Flow *f);
    void removeSystem(System *s);
    void removeFlow(Flow *f);
    void execute(int start, int final, int incr);

  private:
    Model (const Model& model);
};

#endif
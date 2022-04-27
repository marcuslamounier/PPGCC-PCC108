#include <iostream>
#include <vector>
#include "Model.h"

using namespace std;

Model::Model(){
  time = 0;
}

Model::Model(int t) {
  time = t;
}

Model::Model (const Model& model) {
  if (this == &model) return;
  
  time = model.getTime();
}

Model& Model::operator=(const Model& model) {
  if (this == &model) return *this;

  setTime(model.getTime());
  return *this;
}

Model::~Model(){
  for (Flow* flow : flows) delete (flow);
  flows.clear();

  for (System* sys : systems) delete (sys);
  systems.clear();
}

Model::iterSystem Model::firstSystem() {
  return systems.begin();
}

Model::iterSystem Model::lastSystem() {
  return systems.end();
}

Model::iterFlow Model::firstFlow() {
  return flows.begin();
}

Model::iterFlow Model::lastFlow() {
  return flows.end();
}

int Model::getTime() const {
  return time;
}

void Model::setTime(int t) {
  time = t;
}

void Model::incrementTime(int inc) {
  time += inc;
}

void Model::add(System *s){
  systems.insert(lastSystem(), s);
}

void Model::add(Flow *f){
  flows.insert(lastFlow(), f);
}

void Model::remove(System *s){
  auto i = firstSystem();
  for (System* sys : systems) {
    if (s == sys) {
      systems.erase(i);
      break;
    }
    i++;
  }
};

void Model::remove(Flow *f){
  auto i = lastFlow();
  for (Flow* flow : flows) {
    if (f == flow) {
      flows.erase(i);
      break;
    }
    i++;
  }
};

void Model::execute(int start = 1, int final = 100, int incr = 1) {
  for (int i = start; i <= final; i += incr) {
    for (Flow* flow : flows) {
      double flowValue = flow->execute();

      flow->getSource()->setValue(flow->getSource()->getValue() - flowValue);
      flow->getTarget()->setValue(flow->getTarget()->getValue() + flowValue);
      
      incrementTime(incr);
    }
  }
};

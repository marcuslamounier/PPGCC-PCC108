#include <iostream>
#include <vector>
#include "Model.h"

using namespace std;

Model::Model (const Model& model) {
  if (this == &model) {
    return;
  }
  
  time = model.getTime();
}

Model& Model::operator=(const Model& model) {
  if (this == &model) {
    return *this;
  }

  setTime(model.getTime());

  return *this;
}

Model::Model(){
  time = 100;
}

Model::Model(int t) {
  time = t;
}

Model::~Model(){
  for (Flow* flow : flows) {
    delete (flow);
  }
  flows.clear();

  for (System* sys : systems) {
    delete (sys);
  }
  systems.clear();
}

Model::iterSystem Model::begSystems() {
  return systems.begin();
}

Model::iterSystem Model::endSystems() {
  return systems.end();
}

Model::iterFlow Model::begFlows() {
  return flows.begin();
}

Model::iterFlow Model::endFlows() {
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

void Model::addSystem(System *s){
  systems.insert(endSystems(), s);
}

void Model::addFlow(Flow *f){
  flows.insert(endFlows(), f);
}

void Model::removeSystem(System *s){
  auto i = begSystems();
  for (System* sys : systems) {
    if (s == sys) {
      systems.erase(i);
      break;
    }
    i++;
  }
};

void Model::removeFlow(Flow *f){
  auto i = begFlows();
  for (Flow* flow : flows) {
    if (f == flow) {
      flows.erase(i);
      break;
    }
    i++;
  }
};

// TO-DO execute
void Model::execute(int start = 1, int final = 100, int incr = 1) {
  cout << "executing model";
};

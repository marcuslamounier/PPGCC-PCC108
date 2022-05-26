/**
 * @file ModelImplement.cpp
 *
 * @brief Implementation of class Model
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include <vector>
#include "ModelImplement.h"
#include "SystemImplement.h"
#include "FlowImplement.h"

using namespace std;

Model *ModelImplement::_instance = 0;

ModelImplement::ModelImplement()
{
  time = 0;
}

ModelImplement::ModelImplement(int t)
{
  time = t;
}

ModelImplement::ModelImplement(const Model *model)
{
  if (this == model)
  {
    return;
  }
  time = model->getTime();
}

ModelImplement *ModelImplement::operator=(const Model *model)
{
  if (this == model)
  {
    return this;
  }
  setTime(model->getTime());
  return this;
}

ModelImplement::~ModelImplement()
{
  for (int i = systems.size() - 1; i == 0; i--)
    delete (SystemHandle *)systems[i];
  for (int i = flows.size() - 1; i == 0; i--)
    delete (FlowHandle *)flows[i];
  _instance = 0;
}

Model *ModelImplement::createModel()
{
  if (_instance == 0)
    _instance = new ModelImplement;
  return _instance;
}

void ModelImplement::destroyModel() {
  delete (Model *) _instance;
  _instance = 0;
}

ModelImplement::iteratorSystem ModelImplement::firstSystem()
{
  return systems.begin();
}

ModelImplement::iteratorSystem ModelImplement::lastSystem()
{
  return systems.end();
}

ModelImplement::iteratorFlow ModelImplement::firstFlow()
{
  return flows.begin();
}

ModelImplement::iteratorFlow ModelImplement::lastFlow()
{
  return flows.end();
}

Model *Model::createModel()
{
  return ModelImplement::createModel();
}

System *ModelImplement::createSystem(double v)
{
  System *s = new SystemHandle(v);
  add(s);
  return s;
}

System *ModelImplement::getSystem(int index)
{
  return systems[index];
}

Flow *ModelImplement::getFlow(int index)
{
  return flows[index];
}

int ModelImplement::getTime() const
{
  return time;
}

void ModelImplement::setTime(int t)
{
  time = t;
}

void ModelImplement::incrementTime(int incr)
{
  time += incr;
}

void ModelImplement::add(System *sys)
{
  systems.insert(lastSystem(), sys);
}

void ModelImplement::add(Flow *flow)
{
  flows.insert(lastFlow(), flow);
}

void ModelImplement::remove(System *sys)
{
  auto i = firstSystem();
  for (System *s : systems)
  {
    if (sys == s)
    {
      systems.erase(i);
      break;
    }
    i++;
  }
};

void ModelImplement::remove(Flow *flow)
{
  auto i = firstFlow();
  for (Flow *f : flows)
  {
    if (flow == flow)
    {
      flows.erase(i);
      break;
    }
    i++;
  }
};

void ModelImplement::execute(int start, int final, int incr)
{
  for (int i = start; i <= final; i += incr)
  {
    for (Flow *flow : flows)
    {
      flow->setLastValue(flow->execute());
    }
    for (Flow *flow : flows)
    {
      flow->getSource()->setValue(flow->getSource()->getValue() - flow->getLastValue());
      flow->getTarget()->setValue(flow->getTarget()->getValue() + flow->getLastValue());
    }
    incrementTime(incr);
  }
};

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

using namespace std;

ModelImplement::ModelImplement()
{
  time = 0;
}

ModelImplement::ModelImplement(int t)
{
  time = t;
}

ModelImplement::ModelImplement(const Model &model)
{
  if (this == &model)
  {
    return;
  }
  time = model.getTime();
}

ModelImplement &ModelImplement::operator=(const Model &model)
{
  if (this == &model)
  {
    return *this;
  }
  setTime(model.getTime());
  return *this;
}

ModelImplement::~ModelImplement()
{
  flows.clear();
  systems.clear();
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

void ModelImplement::add(System *s)
{
  systems.insert(lastSystem(), s);
}

void ModelImplement::add(Flow *f)
{
  flows.insert(lastFlow(), f);
}

void ModelImplement::remove(System *s)
{
  auto i = firstSystem();
  for (System *sys : systems)
  {
    if (s == sys)
    {
      systems.erase(i);
      break;
    }
    i++;
  }
};

void ModelImplement::remove(Flow *f)
{
  auto i = firstFlow();
  for (Flow *flow : flows)
  {
    if (f == flow)
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

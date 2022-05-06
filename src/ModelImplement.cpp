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

/// Default constructor for Model.
ModelImplement::ModelImplement()
{
  time = 0;
}

/// Parameter's constructor for System.
/**
 * @param t: start time for Model execution.
 */
ModelImplement::ModelImplement(int t)
{
  time = t;
}

/// Copy constructor for Model.
/**
 * This is a @b private method. So it is not included in the docs.
 * @param model: reference for the Model which will be copied.
 */
ModelImplement::ModelImplement(const Model &model)
{
  if (this == &model)
  {
    return;
  }
  time = model.getTime();
}

/// Override for operator "=".
/**
 * This is a @b private method. So it is not included in the docs.
 * @param model: reference for the Model which will be copied.
 */
ModelImplement &ModelImplement::operator=(const Model &model)
{
  if (this == &model)
  {
    return *this;
  }
  setTime(model.getTime());
  return *this;
}

/// Destructor for Model
ModelImplement::~ModelImplement()
{
  flows.clear();
  systems.clear();
}

/// Returns pointer for the first System in the array.
/**
 * @return iteratorSystem
 */
ModelImplement::iteratorSystem ModelImplement::firstSystem()
{
  return systems.begin();
}

/// Returns pointer for the last System in the array.
/**
 * @return iteratorSystem
 */
ModelImplement::iteratorSystem ModelImplement::lastSystem()
{
  return systems.end();
}

/// Returns pointer for the first Flow in the array.
/**
 * @return iteratorFlow
 */
ModelImplement::iteratorFlow ModelImplement::firstFlow()
{
  return flows.begin();
}

/// Returns pointer for the last Flow in the array.
/**
 * @return iteratorFlow
 */
ModelImplement::iteratorFlow ModelImplement::lastFlow()
{
  return flows.end();
}

/// Returns System pointer for System in index-th position.
/**
 * @return System*
 */
System *ModelImplement::getSystem(int index)
{
  return systems[index];
}

/// Returns Flow pointer for Flow in index-th position.
/**
 * @return Flow*
 */
Flow *ModelImplement::getFlow(int index)
{
  return flows[index];
}

/// Returns the current time in Model execution.
/**
 * @return int
 */
int ModelImplement::getTime() const
{
  return time;
}

/// Updates the current time in Model execution.
/**
 * @param t current time.
 */
void ModelImplement::setTime(int t)
{
  time = t;
}

/// Increments the time in Model execution.
/**
 * @param incr increment step for the Model execution.
 */
void ModelImplement::incrementTime(int incr)
{
  time += incr;
}

/// Adds System to the Model graph.
/**
 * @param s pointer to the System which will be added to the Model.
 */
void ModelImplement::add(System *s)
{
  systems.insert(lastSystem(), s);
}

/// Adds Flow to the Model graph.
/**
 * @param f pointer to the Flow which will be added to the Model.
 */
void ModelImplement::add(Flow *f)
{
  flows.insert(lastFlow(), f);
}

/// Removes System to the Model graph.
/**
 * @param f pointer to the System which will be removed to the Model.
 */
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

/// Removes Flow to the Model graph.
/**
 * @param f pointer to the Flow which will be removed to the Model.
 */
void ModelImplement::remove(Flow *f)
{
  auto i = lastFlow();
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

/// Executes the Model.
/**
 * @param start start time for the Model execution.
 * @param final final time for the Model execution.
 * @param incr increment step for the Model execution.
 */
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

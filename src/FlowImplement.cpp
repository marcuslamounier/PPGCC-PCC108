/**
 * @file FlowImplement.cpp
 *
 * @brief Implementation of class Flow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include "FlowImplement.h"

using namespace std;

FlowImplement::FlowImplement()
{
  source = NULL;
  target = NULL;
  lastValue = 0.0;
}

FlowImplement::FlowImplement(const Flow &flow)
{
  if (this == &flow)
  {
    return;
  }
  source = flow.getSource();
  target = flow.getTarget();
  lastValue = flow.getLastValue();
}

FlowImplement &FlowImplement::operator=(const Flow &flow)
{
  if (this == &flow)
  {
    return *this;
  }

  setSource(flow.getSource());
  setTarget(flow.getTarget());
  setLastValue(flow.getLastValue());

  return *this;
}

FlowImplement::FlowImplement(System *from, System *to, double lv)
{
  source = from;
  target = to;
  lastValue = lv;
}

FlowImplement::~FlowImplement() {}

System *FlowImplement::getSource() const
{
  return source;
}

System *FlowImplement::getTarget() const
{
  return target;
}

double FlowImplement::getLastValue() const
{
  return lastValue;
}

void FlowImplement::setSource(System *s)
{
  source = s;
}

void FlowImplement::setTarget(System *s)
{
  target = s;
}

void FlowImplement::setLastValue(double v)
{
  lastValue = v;
}

void FlowImplement::clearSource()
{
  source = NULL;
}

void FlowImplement::clearTarget()
{
  target = NULL;
}

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

/// Default constructor for Flow.
FlowImplement::FlowImplement()
{
  source = NULL;
  target = NULL;
  lastValue = 0.0;
}

/// Copy constructor for Flow.
/**
 * This is a @b private method. So it is not included in the docs.
 * @param flow: reference for the Flow which will be copied.
 */
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

/// Override for operator "=".
/**
 * This is a @b private method. So it is not included in the docs.
 * @param flow: reference for the Flow which will be copied.
 */
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

/// Parameter's constructor for Flow.
/**
 * @param from: pointer for the source System.
 * @param to: pointer for the target System.
 * @param lv: last value carried by the Flow.
 */
FlowImplement::FlowImplement(System *from, System *to, double lv)
{
  source = from;
  target = to;
  lastValue = lv;
}

/// Destructor for Flow
FlowImplement::~FlowImplement() {}

/// Returns pointer for the source System.
System *FlowImplement::getSource() const
{
  return source;
}

/// Returns pointer for the target System.
System *FlowImplement::getTarget() const
{
  return target;
}

/// Returns the last value carried by Flow.
double FlowImplement::getLastValue() const
{
  return lastValue;
}

/// Updates the source System.
/**
 * @param s pointer for the System which will be the Flow source.
 */
void FlowImplement::setSource(System *s)
{
  source = s;
}

/// Updates the target System.
/**
 * @param s pointer for the System which will be the Flow target.
 */
void FlowImplement::setTarget(System *s)
{
  target = s;
}

/// Updates the last value carried by the Flow.
/**
 * @param v last value carried by the Flow.
 */
void FlowImplement::setLastValue(double v)
{
  lastValue = v;
}

/// Sets NULL for the source System.
void FlowImplement::clearSource()
{
  source = NULL;
}

/// Sets NULL for the target System.
void FlowImplement::clearTarget()
{
  target = NULL;
}

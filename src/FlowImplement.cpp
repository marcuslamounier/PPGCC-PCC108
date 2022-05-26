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

System *FlowBody::getSource() const
{
  return source;
}

System *FlowBody::getTarget() const
{
  return target;
}

double FlowBody::getLastValue() const
{
  return lastValue;
}

void FlowBody::setSource(System *sys)
{
  source = sys;
}

void FlowBody::setTarget(System *sys)
{
  target = sys;
}

void FlowBody::setLastValue(double v)
{
  lastValue = v;
}

void FlowBody::clearSource()
{
  source = NULL;
}

void FlowBody::clearTarget()
{
  source = NULL;
}

FlowHandle::FlowHandle()
{
  pImpl_ = new FlowBody();
  pImpl_->attach();
}

FlowHandle::FlowHandle(System *from, System *to, double lv)
{
  pImpl_ = new FlowBody();
  pImpl_->setSource(from);
  pImpl_->setTarget(to);
  pImpl_->setLastValue(lv);
  pImpl_->attach();
}

System *FlowHandle::getSource() const
{
  return pImpl_->getSource();
}

System *FlowHandle::getTarget() const
{
  return pImpl_->getTarget();
}

double FlowHandle::getLastValue() const
{
  return pImpl_->getLastValue();
}

void FlowHandle::setSource(System *sys)
{
  pImpl_->setSource(sys);
}

void FlowHandle::setTarget(System *sys)
{
  pImpl_->setTarget(sys);
}

void FlowHandle::setLastValue(double v)
{
  pImpl_->setLastValue(v);
}

void FlowHandle::clearSource()
{
  pImpl_->clearSource();
}

void FlowHandle::clearTarget()
{
  pImpl_->clearTarget();
}

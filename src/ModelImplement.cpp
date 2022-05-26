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

Model *ModelBody::_instance = 0;

ModelBody::ModelBody()
{
  time = 0;
}

ModelBody::ModelBody(int t)
{
  time = t;
}

ModelBody::~ModelBody() {
  for (int i = systems.size() - 1; i == 0; i--) {
    delete (SystemHandle *) systems[i];
  }
  for (int i = flows.size() - 1; i == 0; i--) {
    delete (FlowHandle *) flows[i];
  }
  _instance = 0;
}

Model *ModelBody::createModel()
{
  if (_instance == 0)
    _instance = new ModelHandle;
  return _instance;
}

System *ModelBody::createSystem(double v)
{
  System *s = new SystemHandle(v);
  add(s);
  return s;
}

Flow *ModelBody::createFlow()
{
  Flow *f = new FlowHandle();
  add(f);
  return f;
}

Flow *ModelBody::createFlow(System *from, System *to)
{
  Flow *f = new FlowHandle(from, to);
  add(f);
  return f;
}

Model::iteratorSystem ModelBody::firstSystem()
{
  return systems.begin();
}

Model::iteratorSystem ModelBody::lastSystem()
{
  return systems.end();
}

Model::iteratorFlow ModelBody::firstFlow()
{
  return flows.begin();
}

Model::iteratorFlow ModelBody::lastFlow()
{
  return flows.end();
}

System *ModelBody::getSystem(int index)
{
  return systems[index];
}

Flow *ModelBody::getFlow(int index)
{
  return flows[index];
}

int ModelBody::getTime() const
{
  return time;
}

void ModelBody::setTime(int t)
{
  time = t;
}

void ModelBody::incrementTime(int incr)
{
  time += incr;
}

void ModelBody::add(System *sys)
{
  systems.insert(lastSystem(), sys);
}

void ModelBody::add(Flow *flow)
{
  flows.insert(lastFlow(), flow);
}

void ModelBody::remove(System *sys)
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
}

void ModelBody::remove(Flow *flow)
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
}

void ModelBody::execute(int start, int final, int incr)
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
}

ModelHandle::ModelHandle()
{
  pImpl_ = new ModelBody();
  pImpl_->attach();
}

ModelHandle::ModelHandle(int t)
{
  pImpl_ = new ModelBody(t);
  pImpl_->attach();
}

void ModelHandle::add(System *sys) {
  pImpl_->add(sys);
}

void ModelHandle::add(Flow *flow) {
  pImpl_->add(flow);
}

Model *ModelHandle::createModel()
{
  return ModelBody::createModel();
}

System *ModelHandle::createSystem(double v)
{
  return pImpl_->createSystem(v);
}

Flow *ModelHandle::createFlow()
{
  return pImpl_->createFlow();
}

Flow *ModelHandle::createFlow(System *from, System *to)
{
  return pImpl_->createFlow(from, to);
}

Model::iteratorSystem ModelHandle::firstSystem()
{
  return pImpl_->firstSystem();
}

Model::iteratorSystem ModelHandle::lastSystem()
{
  return pImpl_->lastSystem();
}

Model::iteratorFlow ModelHandle::firstFlow()
{
  return pImpl_->firstFlow();
}

Model::iteratorFlow ModelHandle::lastFlow()
{
  return pImpl_->lastFlow();
}

System *ModelHandle::getSystem(int index) {
  return pImpl_->getSystem(index);
}

Flow *ModelHandle::getFlow(int index) {
  return pImpl_->getFlow(index);
}

int ModelHandle::getTime() const {
  return pImpl_->getTime();
}

void ModelHandle::setTime(int t) {
  pImpl_->setTime(t);
}

void ModelHandle::incrementTime(int incr) {
  pImpl_->incrementTime(incr);
}

void ModelHandle::remove(System *sys) {
  pImpl_->remove(sys);
}

void ModelHandle::remove(Flow *flow) {
  pImpl_->remove(flow);
}

void ModelHandle::execute(int start, int final, int incr) {
  pImpl_->execute(start, final, incr);
}

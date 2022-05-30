/**
 * @file unit_Flow.cpp
 *
 * @brief Implementation of unitary tests for the functions of class Flow.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include <assert.h>
#include "unit_Flow.h"
#include "../../src/ModelImplement.h"
#include "../../src/SystemImplement.h"
#include "../functional/ExponentialFlow.h"

using namespace std;

static int x = 1;
void printStep() {
  cout << "test " << x << endl;
  x++;
}

void unit_Flow_constructor()
{
  Flow *f = new ExponentialFlow();
  assert(f != NULL);
  delete (FlowHandle *)f;
}

void unit_Flow_destructor()
{
  static int x = 0;
  class MyFlow: public ExponentialFlow {
    public:
      MyFlow() { x = 0; };
      virtual ~MyFlow() { x = 1; };
  };
  {
    MyFlow myFLow;
  }
  assert(x == 1);
}

void unit_Flow_getSource()
{
  double v = 100.0;
  System *s1 = new SystemHandle(v);
  System *s2 = new SystemHandle(0.0);

  Flow *f = new ExponentialFlow(s1, s2);

  assert(abs(f->getSource()->getValue() - v) < 0.1);

  delete f, s1, s2;
}

void unit_Flow_getTarget()
{
  double v = 100.0;
  System *s1 = new SystemHandle(0.0);
  System *s2 = new SystemHandle(v);

  Flow *f = new ExponentialFlow(s1, s2);

  assert(abs(f->getTarget()->getValue() - v) < 0.1);

  delete (SystemHandle *) s1, s2;
  delete (FlowHandle *) f;
}

void unit_Flow_getLastValue()
{
  Model *m = ModelHandle::createModel();
  System *s1 = m->createSystem(100.0);
  System *s2 = m->createSystem(0.0);
  Flow *f = m->createFlow<ExponentialFlow>(s1, s2);

  m->execute(1, 1, 1);
  assert(abs(s2->getValue() - f->getLastValue()) < 0.1);

  delete (ModelHandle *) m;;
}

void unit_Flow_setSource()
{
  double v = 100.0;
  System *s = new SystemHandle(v);
  Flow *f = new ExponentialFlow();

  f->setSource(s);
  assert(abs(f->getSource()->getValue() - v) < 0.1);

  delete (SystemHandle *) s;
  delete (FlowHandle *) f;
}

void unit_Flow_setTarget()
{
  double v = 100.0;
  System *s = new SystemHandle(v);
  Flow *f = new ExponentialFlow();

  f->setTarget(s);
  assert(abs(f->getTarget()->getValue() - v) < 0.1);

  delete (SystemHandle *) s;
  delete (FlowHandle *) f;
}

void unit_Flow_setLastValue()
{
  Flow *f = new ExponentialFlow();
  double v = 0.5;
  f->setLastValue(v);
  assert(abs(f->getLastValue() - v) < 0.01);

  delete (FlowHandle *) f;
}

void unit_Flow_clearSource()
{
  System *s = new SystemHandle(0.0);
  Flow *f = new ExponentialFlow();
  f->setSource(s);
  assert(f->getSource() == s);

  f->clearSource();
  assert(f->getSource() == NULL);

  delete (SystemHandle *) s;
  delete (FlowHandle *) f;
}

void unit_Flow_clearTarget()
{
  System *s = new SystemHandle(0.0);
  Flow *f = new ExponentialFlow();
  f->setTarget(s);
  assert(f->getTarget() == s);

  f->clearTarget();
  assert(f->getTarget() == NULL);

  delete (SystemHandle *) s;
  delete (FlowHandle *) f;
}

void unit_Flow_execute()
{
  double v = 100.0;
  double factor = 0.01;

  System *s1 = new SystemHandle(v);
  System *s2 = new SystemHandle(0.0);
  Flow *f = new ExponentialFlow(s1, s2, factor);

  assert(abs(f->execute() - (factor * v)) < 0.001);

  delete (SystemHandle *) s1, s2;
  delete (FlowHandle *) f;
}

void run_unit_tests_Flow()
{

  // printStep();
  unit_Flow_constructor();

  // printStep();
  unit_Flow_destructor();

  // printStep();
  unit_Flow_getSource();

  // printStep();
  unit_Flow_getTarget();

  // printStep();
  unit_Flow_getLastValue();

  // printStep();
  unit_Flow_setSource();

  // printStep();
  unit_Flow_setTarget();

  // printStep();
  unit_Flow_setLastValue();

  // printStep();
  unit_Flow_clearSource();

  // printStep();
  unit_Flow_clearTarget();

  // printStep();
  unit_Flow_execute();
}

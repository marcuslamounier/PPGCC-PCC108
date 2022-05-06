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
#include "../../src/FlowImplement.h"
#include "../../src/SystemImplement.h"
#include "../functional/ExponentialFlow.h"

using namespace std;

void unit_Flow_constructor()
{
  Flow *f = new ExponentialFlow();
  assert(f != NULL);
  delete f;
}

void unit_Flow_destructor()
{
  Flow *f = new ExponentialFlow();
  assert(f);

  delete f;
  assert(!f);
}

void unit_Flow_getSource()
{
  double v = 100.0;
  System *s1 = new SystemImplement(v);
  System *s2 = new SystemImplement(0.0);

  Flow *f = new ExponentialFlow(s1, s2, 0.01);

  assert(abs(f->getSource()->getValue() - v) < 0.1);

  delete f, s1, s2;
}

void unit_Flow_getTarget()
{
  double v = 100.0;
  System *s1 = new SystemImplement(0.0);
  System *s2 = new SystemImplement(v);

  Flow *f = new ExponentialFlow(s1, s2, 0.01);

  assert(abs(f->getTarget()->getValue() - v) < 0.1);

  delete f, s1, s2;
}

void unit_Flow_getLastValue()
{
  Model *m = new ModelImplement(0);
  System *s1 = new SystemImplement(100.0);
  System *s2 = new SystemImplement(0.0);
  Flow *f = new ExponentialFlow(s1, s2, 0.01);

  m->add(f);
  m->add(s1);
  m->add(s2);

  m->execute(1, 1, 1);
  assert(abs(s2->getValue() - f->getLastValue()) < 0.1);

  delete f, s1, s2, m;
}

void unit_Flow_setSource()
{
  double v = 100.0;
  System *s = new SystemImplement(v);
  Flow *f = new ExponentialFlow();

  f->setSource(s);
  assert(abs(f->getSource()->getValue() - v) < 0.1);

  delete f, s;
}

void unit_Flow_setTarget()
{
  double v = 100.0;
  System *s = new SystemImplement(v);
  Flow *f = new ExponentialFlow();

  f->setTarget(s);
  assert(abs(f->getTarget()->getValue() - v) < 0.1);

  delete f, s;
}

void unit_Flow_setLastValue()
{
  Flow *f = new ExponentialFlow();
  double v = 0.5;
  f->setLastValue(v);
  assert(abs(f->getLastValue() - v) < 0.01);

  delete f;
}

void unit_Flow_clearSource()
{
  System *s = new SystemImplement(0.0);
  Flow *f = new ExponentialFlow();
  f->setSource(s);
  assert(f->getSource() == s);

  f->clearSource();
  assert(f->getSource() == NULL);

  delete f, s;
}

void unit_Flow_clearTarget()
{
  System *s = new SystemImplement(0.0);
  Flow *f = new ExponentialFlow();
  f->setTarget(s);
  assert(f->getTarget() == s);

  f->clearTarget();
  assert(f->getTarget() == NULL);

  delete f, s;
}

void unit_Flow_execute()
{
  double v = 100.0;
  double factor = 0.01;

  System *s1 = new SystemImplement(v);
  System *s2 = new SystemImplement(0.0);
  Flow *f = new ExponentialFlow(s1, s2, factor);

  assert(abs(f->execute() - (factor * v)) < 0.001);

  delete f, s1, s2;
}

void run_unit_tests_Flow()
{
  unit_Flow_constructor();
  // unit_Flow_destructor();
  unit_Flow_getSource();
  unit_Flow_getTarget();
  unit_Flow_getLastValue();
  unit_Flow_setSource();
  unit_Flow_setTarget();
  unit_Flow_setLastValue();
  unit_Flow_clearSource();
  unit_Flow_clearTarget();
  unit_Flow_execute();
}

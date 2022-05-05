#include <iostream>
#include <assert.h>
#include "unit_Model.h"
#include "../../src/Model.h"
#include "../functional/ExponentialFlow.h"

using namespace std;

void unit_Model_constructor()
{
  Model *m = new Model();
  assert(m != NULL);

  delete m;
}

void unit_Model_destructor()
{
  Model *m = new Model();
  assert(m);

  delete m;
  assert(!m);
}

void unit_Model_getSystem() {
  Model *m = new Model();
  System *s = new System(0.0);
  m->add(s);

  assert(m->getSystem(0) == s);

  delete s, m;
}

void unit_Model_getFlow() {
  Model *m = new Model();
  Flow *f = new ExponentialFlow();
  m->add(f);

  assert(m->getFlow(0) == f);

  delete f, m;
}

void unit_Model_getTime()
{
  int t = 0;

  Model *m = new Model(t);
  assert(m->getTime() == t);

  delete m;
}

void unit_Model_setTime()
{
  int t = 1;

  Model *m = new Model();
  m->setTime(t);
  assert(m->getTime() == t);

  delete m;
}

void unit_Model_incrementTime()
{
  int incr = 2;
  int t = 0;

  Model *m = new Model(t);
  m->incrementTime();
  // 1 is the default increment
  assert(m->getTime() == t + 1);
  // if passed first test, increment value default incr
  t = t + 1;

  m->incrementTime(incr);
  assert(m->getTime() == t + incr);

  delete m;
}

void unit_Model_add()
{
  Model *m = new Model();

  System *s = new System(100.0);
  ExponentialFlow *f = new ExponentialFlow();

  m->add(s);
  m->add(f);

  assert(m->getSystem(0) == s);
  assert(m->getFlow(0) == f);

  delete f, s, m;
}

void unit_Model_remove()
{
  Model *m = new Model();

  System *s = new System(100);
  ExponentialFlow *f = new ExponentialFlow();

  m->add(s);
  m->add(f);

  m->remove(s);
  assert(m->getSystem(0) != s);

  m->remove(f);
  assert(m->getFlow(0) != f);

  delete f, s, m;
}

void unit_Model_execute()
{
  Model *m = new Model(0);

  System *s1 = new System(100);
  System *s2 = new System(0);
  Flow *f = new ExponentialFlow(s1, s2, 0.01);

  m->add(f);
  m->add(s1);
  m->add(s2);

  m->execute(1, 100, 1);

  assert(abs(s1->getValue() - 36.6032) < 0.0001);
  assert(abs(s2->getValue() - 63.3968) < 0.0001);
  assert(m->getTime() - 100 == 0);

  delete f, s1, s2, m;
}

void run_unit_tests_Model()
{
  unit_Model_constructor();
  // unit_Model_destructor();
  unit_Model_getSystem();
  unit_Model_getFlow();
  unit_Model_getTime();
  unit_Model_setTime();
  unit_Model_incrementTime();
  unit_Model_add();
  // unit_Model_remove();
  unit_Model_execute();
}

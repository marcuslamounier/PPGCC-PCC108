#include <iostream>
#include <assert.h>
#include "unit_Model.h"
#include "../../src/ModelImplement.h"
#include "../../src/SystemImplement.h"
#include "../functional/ExponentialFlow.h"

using namespace std;

void unit_Model_constructor()
{
  Model *m = new ModelImplement();
  assert(m != NULL);

  delete m;
}

void unit_Model_destructor()
{
  Model *m = new ModelImplement();
  m->~Model();
  delete m;
}

void unit_Model_getSystemImplement() {
  Model *m = new ModelImplement();
  System *s = new SystemImplement(0.0);
  m->add(s);

  assert(m->getSystem(0) == s);

  delete s, m;
}

void unit_Model_getFlow() {
  Model *m = new ModelImplement();
  Flow *f = new ExponentialFlow();
  m->add(f);

  assert(m->getFlow(0) == f);

  delete f, m;
}

void unit_Model_getTime()
{
  int t = 0;

  Model *m = new ModelImplement(t);
  assert(m->getTime() == t);

  delete m;
}

void unit_Model_setTime()
{
  int t = 1;

  Model *m = new ModelImplement();
  m->setTime(t);
  assert(m->getTime() == t);

  delete m;
}

void unit_Model_incrementTime()
{
  int incr = 2;
  int t = 0;

  Model *m = new ModelImplement(t);
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
  Model *m = new ModelImplement();

  System *s = new SystemImplement(100.0);
  ExponentialFlow *f = new ExponentialFlow();

  m->add(s);
  m->add(f);

  assert(m->getSystem(0) == s);
  assert(m->getFlow(0) == f);

  delete f, s, m;
}

void unit_Model_remove()
{
  Model *m = new ModelImplement();

  System *s = new SystemImplement(100);
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
  Model *m = new ModelImplement(0);

  System *s1 = new SystemImplement(100);
  System *s2 = new SystemImplement(0);
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
  unit_Model_getSystemImplement();
  unit_Model_getFlow();
  unit_Model_getTime();
  unit_Model_setTime();
  unit_Model_incrementTime();
  unit_Model_add();
  // unit_Model_remove();
  unit_Model_execute();
}

/**
 * @file unit_Model.cpp
 *
 * @brief Implementation of unitary tests for the functions of class Model.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

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
  static int x = 0;
  class MyModel: public ModelImplement {
    public:
      MyModel() { x = 0; };
      virtual ~MyModel() { x = 1; };
  };
  {
    MyModel myModel;
  }
  assert(x == 1);
}

void unit_Model_getSystemImplement()
{
  Model *m = new ModelImplement();
  System *s = new SystemImplement(0.0);
  m->add(s);

  assert(m->getSystem(0) == s);

  delete s, m;
}

void unit_Model_getFlow()
{
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
  assert(m->getTime() == t + 1);

  t = t + 1;
  m->incrementTime(incr);
  assert(m->getTime() == t + incr);

  delete m;
}

void unit_Model_add()
{
  Model *m = new ModelImplement();

  System *s = new SystemImplement(100.0);
  Flow *f = new ExponentialFlow();

  m->add(s);
  m->add(f);

  bool foundSystem = false;
  for (Model::iteratorSystem it = m->firstSystem(); it != m->lastSystem(); it++)
  {
    foundSystem = (*it == s);
  }
  assert(foundSystem);

  bool foundFlow = false;
  for (Model::iteratorFlow it = m->firstFlow(); it != m->lastFlow(); it++)
  {
    foundFlow = (*it == f);
  }
  assert(foundFlow);

  delete f, s, m;
}

void unit_Model_remove()
{
  Model *m = new ModelImplement();

  System *s = new SystemImplement(100);
  m->add(s);

  ExponentialFlow *f = new ExponentialFlow();
  m->add(f);

  bool foundSystem, foundFlow;

  m->remove(s);
  if (m->firstSystem() == m->lastSystem())
    foundSystem = false;
  else
  {
    for (Model::iteratorSystem it = m->firstSystem(); it != m->lastSystem(); it++)
    {
      foundSystem = (*it == s);
    }
  }
  assert(!foundSystem);

  m->remove(f);
  if (m->firstFlow() == m->lastFlow())
    foundFlow = false;
  else
  {
    for (Model::iteratorFlow it = m->firstFlow(); it != m->lastFlow(); it++)
    {
      foundFlow = (*it == f);
    }
  }
  assert(!foundFlow);

  delete f, s, m;
}

void unit_Model_execute()
{
  Model *m = new ModelImplement(0);
  int duration = 100;

  m->execute(1, duration, 1);
  assert(m->getTime() == duration);

  delete m;
}

void run_unit_tests_Model()
{
  unit_Model_constructor();
  unit_Model_destructor();
  unit_Model_getSystemImplement();
  unit_Model_getFlow();
  unit_Model_getTime();
  unit_Model_setTime();
  unit_Model_incrementTime();
  unit_Model_add();
  unit_Model_remove();
  unit_Model_execute();
}

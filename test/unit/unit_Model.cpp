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
#include "../../src/FlowImplement.h"
#include "../functional/ExponentialFlow.h"

using namespace std;

static int x = 1;
void printStep() {
  cout << "test " << x << endl;
  x++;
}

void unit_Model_constructor()
{
  Model *m = Model::createModel();
  assert(m != NULL);

  delete (Model *) m;
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

void unit_Model_createModel() {
  Model *m = Model::createModel();
  int t0 = 0;
  assert(m->getTime() == t0);

  int incr = 2;
  m->incrementTime(incr);
  assert(m->getTime() == t0 + incr);

  delete (Model *) m;
}

void unit_Model_createSystem() {
  Model *m = Model::createModel();

  double v0 = 100.0;
  m->createSystem(v0);
  assert(abs(m->getSystem(0)->getValue() - v0) < 0.0001);

  delete (Model *) m;
}

void unit_Model_createFlow() {
  Model *m = Model::createModel();
  double v0 = 100.0;
  m->createSystem(v0);
  m->createSystem(10.0);
  m->createFlow<ExponentialFlow>(
      m->getSystem(0),
      m->getSystem(1));
  assert(abs(m->getFlow(0)->getSource()->getValue() - v0) < 0.0001);

  delete (Model *) m;
}

void unit_Model_getSystemImplement()
{
  Model *m = Model::createModel();
  System *s = m->createSystem(0.0);

  assert(m->getSystem(0) == s);

  delete (Model *) m;
}

void unit_Model_getFlow()
{
  Model *m = Model::createModel();
  Flow *f = m->createFlow<ExponentialFlow>();

  assert(m->getFlow(0) == f);

  delete (Model *) m;
}

void unit_Model_getTime()
{
  int t = 0;

  Model *m = Model::createModel();
  m->setTime(t);
  assert(m->getTime() == t);

  delete (Model *) m;
}

void unit_Model_setTime()
{
  int t = 1;

  Model *m = Model::createModel();
  m->setTime(t);
  assert(m->getTime() == t);

  delete (Model *) m;
}

void unit_Model_incrementTime()
{
  int incr = 2;
  int t = 0;

  Model *m = Model::createModel();
  m->setTime(t);
  m->incrementTime();
  assert(m->getTime() == t + 1);

  t = t + 1;
  m->incrementTime(incr);
  assert(m->getTime() == t + incr);

  delete m;
}

void unit_Model_add()
{
  Model *m = Model::createModel();
  System *s = m->createSystem(100.0);
  Flow *f = m->createFlow<ExponentialFlow>();

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

  delete (Model *) m;
}

void unit_Model_remove()
{
  Model *m = Model::createModel();
  System *s = m->createSystem(100.0);
  Flow *f = m->createFlow<ExponentialFlow>();

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

  delete (Model *) m;
}

void unit_Model_execute()
{
  Model *m = Model::createModel();
  int duration = 100;

  m->execute(1, duration, 1);
  assert(m->getTime() == duration);

  delete (Model *) m;
}

void run_unit_tests_Model()
{
  // printStep();
  unit_Model_constructor();

  // printStep();
  unit_Model_destructor();
  
  // printStep();
  unit_Model_getSystemImplement();
  
  // printStep();
  unit_Model_getFlow();
  
  // printStep();
  unit_Model_getTime();
  
  // printStep();
  unit_Model_setTime();
  
  // printStep();
  unit_Model_incrementTime();
  
  // printStep();
  unit_Model_add();
  
  // printStep();
  unit_Model_remove();
  
  // printStep();
  unit_Model_execute();
}

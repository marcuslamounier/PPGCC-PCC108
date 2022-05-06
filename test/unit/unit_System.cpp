#include <iostream>
#include <assert.h>
#include "unit_System.h"
#include "../../src/SystemImplement.h"
#include "../functional/ExponentialFlow.h"

using namespace std;

void unit_System_constructor()
{
  System *s = new SystemImplement(0.0);
  assert(s != NULL);
  delete s;
}

void unit_System_destructor()
{
  System *s = new SystemImplement(0.0);
  assert(s);

  delete s;
  assert(s == NULL);
}

void unit_System_getValue()
{
  double v = 100.0;
  System *s = new SystemImplement(v);
  assert(abs(s->getValue() - v) < 0.01);
  delete s;
}

void unit_System_setValue()
{
  double v = 100.0;
  System *s = new SystemImplement(0.0);
  s->setValue(v);
  assert(abs(s->getValue() - v) < 0.01);
  delete s;
}

void run_unit_tests_System()
{
  unit_System_constructor();
  // unit_System_destructor();
  unit_System_getValue();
  unit_System_setValue();
}

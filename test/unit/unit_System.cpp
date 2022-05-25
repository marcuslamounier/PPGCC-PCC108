/**
 * @file unit_System.cpp
 *
 * @brief Implementation of unitary tests for the functions of class System.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include <assert.h>
#include "unit_System.h"
#include "../../src/SystemImplement.h"
#include "../functional/ExponentialFlow.h"

using namespace std;

void unit_System_constructor()
{
  System *s = new SystemHandle(0.0);
  assert(s != NULL);
  delete s;
}

void unit_System_destructor()
{
  static int x = 0;
  class MySystem: public SystemHandle {
    public:
      MySystem() { x = 0; };
      virtual ~MySystem() { x = 1; };
  };
  {
    MySystem mySystem;
  }
  assert(x == 1);
}

void unit_System_getValue()
{
  double v = 100.0;
  System *s = new SystemHandle(v);
  assert(abs(s->getValue() - v) < 0.01);
  delete s;
}

void unit_System_setValue()
{
  double v = 100.0;
  System *s = new SystemHandle(0.0);
  s->setValue(v);
  assert(abs(s->getValue() - v) < 0.01);
  delete s;
}

void run_unit_tests_System()
{
  unit_System_constructor();
  unit_System_destructor();
  unit_System_getValue();
  unit_System_setValue();
}

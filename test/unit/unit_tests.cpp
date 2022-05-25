/**
 * @file unit_tests.cpp
 *
 * @brief Implementation of unitary tests for all the classes.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include <assert.h>
#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

using namespace std;

void run_unit_tests_globals()
{
  cout << "Phase 1 - System tests" << endl;
  run_unit_tests_System();
  cout << GREEN << "OK!" << RESET << endl;

  cout << "Phase 2 - Flow tests" << endl;
  run_unit_tests_Flow();
  cout << GREEN << "OK!" << RESET << endl;

  cout << "Phase 3 - Model tests" << endl;
  run_unit_tests_Model();
  cout << GREEN << "OK!" << RESET << endl;
}

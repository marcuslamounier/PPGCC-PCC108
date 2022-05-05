#include <iostream>
#include <assert.h>
#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

using namespace std;

void run_unit_tests_globals()
{
  cout << "System tests" << endl;
  run_unit_tests_System();
  cout << GREEN << "OK!" << RESET << endl;

  cout << "Flow tests" << endl;
  run_unit_tests_Flow();
  cout << GREEN << "OK!" << RESET << endl;

  cout << "Model tests" << endl;
  run_unit_tests_Model();
  cout << GREEN << "OK!" << RESET << endl;
}

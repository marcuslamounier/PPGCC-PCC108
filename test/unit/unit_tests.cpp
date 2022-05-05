#include <iostream>
#include <assert.h>
#include "unit_Model.h"
#include "unit_Flow.h"
#include "unit_System.h"

void run_unit_tests_globals()
{
  run_unit_tests_System();
  run_unit_tests_Flow();
  run_unit_tests_Model();
}

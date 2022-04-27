#include <iostream>
#include <assert.h>
#include "functional_tests.h"
#include "../../src/Model.h"
#include "../../src/System.h"
#include "ExponentialFlow.h"

using namespace std;

void exponentialFuncTest() {
  cout << "Test 1 - Exponential flow" << endl;

  System* pop1 = new System(100);
  System* pop2 = new System(0);
  ExponentialFlow* expFlow = new ExponentialFlow(pop1, pop2);
  Model* expModel = new Model(0);
  
  expModel->add(pop1);
  expModel->add(pop2);
  expModel->add(expFlow);

  assert(abs(pop1->getValue() - 100.0) < 0.0001);
  assert(abs(pop2->getValue() - 0.0) < 0.0001);
  assert(abs(expModel->getTime() - 0.0) < 0.0001);

  expModel->execute(1, 100, 1);

  assert(abs(pop1->getValue() - 36.6032) < 0.0001);
  assert(abs(pop2->getValue() - 63.3968) < 0.0001);
  assert(expModel->getTime() - 100 == 0);

  delete (expModel);

  cout << GREEN << "OK!"<< RESET << endl;
}
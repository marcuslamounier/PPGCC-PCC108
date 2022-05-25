/**
 * @file functional_tests.cpp
 *
 * @brief Implementation of functional tests for the test
 * scenarios identified together with the customer.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include <assert.h>
#include "functional_tests.h"
#include "../../src/ModelImplement.h"
#include "../../src/SystemImplement.h"
#include "ExponentialFlow.h"
#include "LogisticFlow.h"

using namespace std;

void exponentialFuncTest()
{
  cout << "Test 1 - Exponential flow" << endl;

  Model *expModel = Model::createModel();
  System *pop1 = expModel->createSystem(100.0);
  System *pop2 = expModel->createSystem(0.0);
  expModel->createFlow<ExponentialFlow>(pop1, pop2);

  assert(abs(pop1->getValue() - 100.0) < 0.0001);
  assert(abs(pop2->getValue() - 0.0) < 0.0001);
  assert(expModel->getTime() - 0 == 0);

  expModel->execute(1, 100, 1);

  assert(abs(pop1->getValue() - 36.6032) < 0.0001);
  assert(abs(pop2->getValue() - 63.3968) < 0.0001);
  assert(expModel->getTime() == 100);

  delete (ModelImplement *)expModel;

  cout << GREEN << "OK!" << RESET << endl;
}

void logisticFuncTest()
{
  cout << "Test 2 - Logistic flow" << endl;

  Model *logModel = Model::createModel();
  System *p1 = logModel->createSystem(100.0);
  System *p2 = logModel->createSystem(10.0);
  logModel->createFlow<LogisticFlow>(p1, p2);

  assert(abs(p1->getValue() - 100.0) < 0.0001);
  assert(abs(p2->getValue() - 10.0) < 0.0001);
  assert(logModel->getTime() == 0);

  logModel->execute(1, 100, 1);

  assert(abs(p1->getValue() - 88.2167) < 0.0001);
  assert(abs(p2->getValue() - 21.7833) < 0.0001);
  assert(logModel->getTime() == 100);

  delete (ModelImplement *)logModel;

  cout << GREEN << "OK!" << RESET << endl;
}

void complexFuncTest()
{
  cout << "Test 3 - Complex model flow" << endl;

  Model *complexModel = Model::createModel();

  System *Q1 = complexModel->createSystem(100);
  System *Q2 = complexModel->createSystem(0);
  System *Q3 = complexModel->createSystem(100);
  System *Q4 = complexModel->createSystem(0);
  System *Q5 = complexModel->createSystem(0);

  complexModel->createFlow<ExponentialFlow>(Q1, Q2);
  complexModel->createFlow<ExponentialFlow>(Q1, Q3);
  complexModel->createFlow<ExponentialFlow>(Q2, Q5);
  complexModel->createFlow<ExponentialFlow>(Q2, Q3);
  complexModel->createFlow<ExponentialFlow>(Q3, Q4);
  complexModel->createFlow<ExponentialFlow>(Q4, Q1);

  assert(abs(Q1->getValue() - 100.0) < 0.0001);
  assert(abs(Q2->getValue() - 0.0) < 0.0001);
  assert(abs(Q3->getValue() - 100.0) < 0.0001);
  assert(abs(Q4->getValue() - 0.0) < 0.0001);
  assert(abs(Q5->getValue() - 0.0) < 0.0001);
  assert(complexModel->getTime() == 0);

  complexModel->execute(1, 100, 1);

  assert(abs(Q1->getValue() - 31.8513) < 0.0001);
  assert(abs(Q2->getValue() - 18.4003) < 0.0001);
  assert(abs(Q3->getValue() - 77.1143) < 0.0001);
  assert(abs(Q4->getValue() - 56.1728) < 0.0001);
  assert(abs(Q5->getValue() - 16.4612) < 0.0001);
  assert(complexModel->getTime() == 100);

  delete (ModelImplement *)complexModel;

  cout << GREEN << "OK!" << RESET << endl;
}

void run_functional_tests_globals()
{
  exponentialFuncTest();
  logisticFuncTest();
  complexFuncTest();
}
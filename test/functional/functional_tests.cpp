#include <iostream>
#include <assert.h>
#include "functional_tests.h"
#include "../../src/Model.h"
#include "../../src/System.h"
#include "ExponentialFlow.h"
#include "LogisticFlow.h"

using namespace std;

void exponentialFuncTest()
{
  cout << "Test 1 - Exponential flow" << endl;

  System *pop1 = new System(100);
  System *pop2 = new System(0);
  ExponentialFlow *exponencial = new ExponentialFlow(pop1, pop2, 0.01);
  Model *expModel = new Model(0);

  expModel->add(pop1);
  expModel->add(pop2);
  expModel->add(exponencial);

  assert(abs(pop1->getValue() - 100.0) < 0.0001);
  assert(abs(pop2->getValue() - 0.0) < 0.0001);
  assert(expModel->getTime() - 0 == 0);

  expModel->execute(1, 100, 1);

  assert(abs(pop1->getValue() - 36.6032) < 0.0001);
  assert(abs(pop2->getValue() - 63.3968) < 0.0001);
  assert(expModel->getTime() - 100 == 0);

  delete (expModel);

  cout << GREEN << "OK!" << RESET << endl;
}

void logisticFuncTest()
{
  cout << "Test 2 - Logistic flow" << endl;

  System *p1 = new System(100);
  System *p2 = new System(10);
  LogisticFlow *logistica = new LogisticFlow(p1, p2, 0.01, 70.0);
  Model *logModel = new Model(0);

  logModel->add(p1);
  logModel->add(p2);
  logModel->add(logistica);

  assert(abs(p1->getValue() - 100.0) < 0.0001);
  assert(abs(p2->getValue() - 10.0) < 0.0001);
  assert(logModel->getTime() == 0);

  logModel->execute(1, 100, 1);

  assert(abs(p1->getValue() - 88.2167) < 0.0001);
  assert(abs(p2->getValue() - 21.7833) < 0.0001);
  assert(logModel->getTime() - 100 == 0);

  delete (logModel);

  cout << GREEN << "OK!" << RESET << endl;
}

void complexFuncTest()
{
  cout << "Test 3 - Complex model flow" << endl;

  System *Q1 = new System(100);
  System *Q2 = new System(0);
  System *Q3 = new System(100);
  System *Q4 = new System(0);
  System *Q5 = new System(0);

  ExponentialFlow *f = new ExponentialFlow(Q1, Q2, 0.01);
  ExponentialFlow *g = new ExponentialFlow(Q1, Q3, 0.01);
  ExponentialFlow *r = new ExponentialFlow(Q2, Q5, 0.01);
  ExponentialFlow *t = new ExponentialFlow(Q2, Q3, 0.01);
  ExponentialFlow *u = new ExponentialFlow(Q3, Q4, 0.01);
  ExponentialFlow *v = new ExponentialFlow(Q4, Q1, 0.01);

  Model *complexModel = new Model(0);

  complexModel->add(Q1);
  complexModel->add(Q2);
  complexModel->add(Q3);
  complexModel->add(Q4);
  complexModel->add(Q5);

  complexModel->add(f);
  complexModel->add(g);
  complexModel->add(r);
  complexModel->add(t);
  complexModel->add(u);
  complexModel->add(v);

  assert(abs(Q1->getValue() - 100.0) < 0.0001);
  assert(abs(Q2->getValue() - 0.0) < 0.0001);
  assert(abs(Q3->getValue() - 100.0) < 0.0001);
  assert(abs(Q4->getValue() - 0.0) < 0.0001);
  assert(abs(Q5->getValue() - 0.0) < 0.0001);
  assert(complexModel->getTime() == 0);

  complexModel->execute(1, 100, 1);

  // cout << "Q1 " << Q1->getValue() << endl;
  // cout << "Q2 " << Q2->getValue() << endl;
  // cout << "Q3 " << Q3->getValue() << endl;
  // cout << "Q4 " << Q4->getValue() << endl;
  // cout << "Q5 " << Q5->getValue() << endl;

  assert(abs(Q1->getValue() - 31.8513) < 0.0001);
  assert(abs(Q2->getValue() - 18.4003) < 0.0001);
  assert(abs(Q3->getValue() - 77.1143) < 0.0001);
  assert(abs(Q4->getValue() - 56.1728) < 0.0001);
  assert(abs(Q5->getValue() - 16.4612) < 0.0001);
  assert(complexModel->getTime() - 100 == 0);

  delete (complexModel);

  cout << GREEN << "OK!" << RESET << endl;
}

void run_functional_tests_globals()
{
  exponentialFuncTest();
  logisticFuncTest();
  complexFuncTest();
}
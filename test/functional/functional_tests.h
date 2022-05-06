/**
 * @file functional_tests.h
 *
 * @brief Declaration of functional tests for the test
 * scenarios identified together with the customer.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef FUNCTIONAL_TEST
#define FUNCTIONAL_TEST

#define RESET "\033[0m"  /* Escape sequence to reset color output to default. */
#define GREEN "\033[32m" /* Escape sequence to a green color output. */

/// Tests the exponential model provided by the customer.
/**
 * @test exponential model provided by the customer.
 * 
 * The purpose of the test is to create a model, a flow which runs an
 * exponential equation between two systems and to give, finally, the same
 * result than the model provided by the customer.
 */
void exponentialFuncTest();

/// Tests the logistic model provided by the customer.
/**
 * @test logistic model provided by the customer.
 * 
 * The purpose of the test is to create a model, a flow which runs a
 * logistic equation between two systems and to give, finally, the same
 * result than the model provided by the customer.
 */
void logisticFuncTest();

/// Tests the complex model provided by the customer.
/**
 * @test complex model provided by the customer.
 * 
 * The purpose of the test is to create a model, some flows which run
 * exponential equations between two systems and to give, finally, the same
 * result than the model provided by the customer.
 */
void complexFuncTest();

/// Global call for all functional tests.
void run_functional_tests_globals();

#endif

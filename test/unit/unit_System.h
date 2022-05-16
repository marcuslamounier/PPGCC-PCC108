/**
 * @file unit_System.h
 *
 * @brief Declaration of unitary tests for the methods of class System.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/// Tests the System constructors.
/**
 * @test System constructors.
 * 
 * The purpose of the test is to verify if the Systems are correctly created.
 */
void unit_System_constructor();

/// Tests the System destructors.
/**
 * @test System destructors.
 * 
 * The purpose of the test is to verify if the Systems are correctly destructed.
 */
void unit_System_destructor();

/// Tests getter for stored value in System.
/**
 * @test getter for stored value in System.
 * 
 * The purpose of the test is to verify if the stored value in System is
 * correctly returned.
 */
void unit_System_getValue();

/// Tests setter for stored value in System.
/**
 * @test setter for stored value in System.
 * 
 * The purpose of the test is to verify if the stored value in System is
 * correctly updated.
 */
void unit_System_setValue();

/// Global call for unitary tests for the methods of class System.
/**
 * @test methods of class System.
 *
 * The purpose of the test is to execute all the methods of class System and
 * get the results expected by the customer.
 */
void run_unit_tests_System();

#endif
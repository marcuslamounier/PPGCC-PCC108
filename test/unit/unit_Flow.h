/**
 * @file unit_Flow.h
 *
 * @brief Declaration of unitary tests for the methods of class Flow.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/// Tests the Flow constructors.
/**
 * @test Flow constructors.
 *
 * The purpose of the test is to verify if the Flows are correctly created.
 */
void unit_Flow_constructor();

/// Tests the Flow destructors.
/**
 * @test Flow destructors.
 *
 * The purpose of the test is to verify if the Flows are correctly destructed.
 */
void unit_Flow_destructor();

/// Tests the source System* getter.
/**
 * @test source System* getter.
 *
 * The purpose of the test is to verify if the pointer for the source System
 * is correctly returned.
 */
void unit_Flow_getSource();

/// Tests the target System* getter.
/**
 * @test target System* getter.
 *
 * The purpose of the test is to verify if the pointer for the target System
 * is correctly returned.
 */
void unit_Flow_getTarget();

/// Tests lastValue getter.
/**
 * @test lastValue getter.
 *
 * The purpose of the test is to verify if the last value stored in Flow is
 * correctly returned.
 */
void unit_Flow_getLastValue();

/// Tests the source System* setter.
/**
 * @test source System* setter.
 *
 * The purpose of the test is to verify if the pointer for the source System
 * is correctly updated.
 */
void unit_Flow_setSource();

/// Tests the target System* setter.
/**
 * @test target System* setter.
 *
 * The purpose of the test is to verify if the pointer for the target System
 * is correctly updated.
 */
void unit_Flow_setTarget();

/// Tests the lastValue setter.
/**
 * @test lastValue setter.
 *
 * The purpose of the test is to verify if the last value stored in Flow is
 * correctly updated.
 */
void unit_Flow_setLastValue();

/// Tests the source System* cleaner.
/**
 * @test source System* cleaner.
 *
 * The purpose of the test is to verify if the pointer for the source System
 * is correctly disassociated.
 */
void unit_Flow_clearSource();

/// Tests the target System* cleaner.
/**
 * @test target System* cleaner.
 *
 * The purpose of the test is to verify if the pointer for the target System
 * is correctly disassociated.
 */
void unit_Flow_clearTarget();

/// Tests the equation execution.
/**
 * @test equation execution.
 *
 * The purpose of the test is to verify if the algebraic equations are being
 * correctly executed.
 */
void unit_Flow_execute();

/// Global call for unitary tests for the methods of class Flow.
/**
 * @test methods of class Flow.
 *
 * The purpose of the test is to execute all the methods of class Flow and
 * get the results expected by the customer.
 */
void run_unit_tests_Flow();

#endif
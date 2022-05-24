/**
 * @file unit_Model.h
 *
 * @brief Declaration of unitary tests for the methods of class Model.
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/// Tests the Model constructors.
/**
 * @test Model constructors.
 * 
 * The purpose of the test is to verify if the Models are correctly created.
 */
void unit_Model_constructor();

/// Tests the Model destructors.
/**
 * @test Model destructors.
 * 
 * The purpose of the test is to verify if the Models are correctly destructed.
 */
void unit_Model_destructor();

/**
 * @brief Tests the model creators.
 * @test Model creators.
 * 
 * The purpose of the test is to verify if the Models are correctly created.
 */
void unit_Model_createModel();

/**
 * @brief Tests the system creators.
 * @test System creators.
 * 
 * The purpose of the test is to verify if the Systems are correctly created.
 */
void unit_Model_createSystem();

/**
 * @brief Tests the flow creators.
 * @test Flow creators.
 * 
 * The purpose of the test is to verify if the Flows are correctly created.
 */
void unit_Model_createFlow();

/// Tests the System* getter.
/**
 * @test System* getter.
 * 
 * The purpose of the test is to verify if the pointer for a System is correctly
 * returned.
 */
void unit_Model_getSystem();

/// Tests the Flow* getter.
/**
 * @test Flow* getter.
 * 
 * The purpose of the test is to verify if the pointer for a Flow is correctly
 * returned.
 */
void unit_Model_getFlow();

/// Tests the current time getter.
/**
 * @test current time getter.
 * 
 * The purpose of the test is to verify if the current time is correctly returned.
 */
void unit_Model_getTime();

/// Tests the current time setter.
/**
 * @test current time setter.
 * 
 * The purpose of the test is to verify if the current time is correctly updated.
 */
void unit_Model_setTime();

/// Tests the current time incrementer.
/**
 * @test current time setter.
 * 
 * The purpose of the test is to verify if the current time is correctly
 * incremented.
 */
void unit_Model_incrementTime();

/// Tests the Flow* and System* associators.
/**
 * @test the Flow* and System* associators.
 * 
 * The purpose of the test is to verify if the Flows and Systems are correctly
 * associated to Model.
 */
void unit_Model_add();

/// Tests the Flow* and System* disassociators.
/**
 * @test the Flow* and System* disassociators.
 * 
 * The purpose of the test is to verify if the Flows and Systems are correctly
 * disassociated to Model.
 */
void unit_Model_remove();

/// Tests the Model execution.
/**
 * @test the Model execution.
 * 
 * The purpose of the test if the model is and its associated equations are
 * correctly executed.
 */
void unit_Model_execute();

/// Global call for unitary tests for the methods of class Model.
/**
 * @test methods of class Model.
 *
 * The purpose of the test is to execute all the methods of class Model and
 * get the results expected by the customer.
 */
void run_unit_tests_Model();

#endif
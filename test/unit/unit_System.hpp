#ifndef _UNIT_SYSTEM_H_
#define _UNIT_SYSTEM_H_


#include "../../src/SystemImpl.hpp"

/**
 * @brief A unitary test for asserting the default constructor of SystemImpl.
*/
void unit_System_constructor_default();

/**
 * @brief A unitary test for asserting the constructor of SystemImpl with the name parameter.
*/
void unit_System_constructor_with_name();

/**
 * @brief A unitary test for asserting the constructor of SystemImpl with name and value parameters..
*/
void unit_System_constructor_with_name_value();

/**
 * @brief A unitary test for asserting the copy constructor of SystemImpl.
*/
void unit_system_copy_constructor();

/**
 * @brief A unitary test for asserting the destructor of SystemImpl.
*/
void unit_System_destructor();

/**
 * @brief A unitary test for asserting the getName method.
*/
void unit_System_getName();

/**
 * @brief A unitary test for asserting the setName method.
*/
void unit_System_setName();

/**
 * @brief A unitary test for asserting the getValue method.
*/
void unit_System_getValue();

/**
 * @brief A unitary test for asserting the setValue method.
*/
void unit_System_setValue();


/**
 * @brief A unitary test for asserting the overload of the assignment(=) operator.
*/
void unit_System_assignOverload();

void run_unit_test_System();

#endif
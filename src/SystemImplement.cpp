/**
 * @file SystemImplement.cpp
 *
 * @brief Implementation of class Model
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#include <iostream>
#include "SystemImplement.h"

using namespace std;

/// Default constructor for System.
SystemImplement::SystemImplement()
{
  value = 0.0;
}

/// Copy constructor for System.
/**
 * @param sys: reference for the System which will be copied.
 */
SystemImplement::SystemImplement(const System &sys)
{
  if (this == &sys)
  {
    return;
  }
  value = sys.getValue();
}

/// Override for operator "=".
/**
 * @param sys: reference for the System which will be copied.
 */
SystemImplement &SystemImplement::operator=(const System &sys)
{
  if (this == &sys)
  {
    return *this;
  }
  setValue(sys.getValue());
  return *this;
}

/// Parameter's constructor for System.
/**
 * @param v: value stored in the System.
 */
SystemImplement::SystemImplement(double v)
{
  value = v;
}

/// Destructor for System
SystemImplement::~SystemImplement() = default;

/// Returns the value stored in the System.
double SystemImplement::getValue() const
{
  return value;
}

/// Updates the value stored in the System.
/**
 * @param v current value stored in the System.
 */
void SystemImplement::setValue(double v)
{
  value = v;
}

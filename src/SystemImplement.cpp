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

SystemImplement::SystemImplement()
{
  value = 0.0;
}

SystemImplement::SystemImplement(const System &sys)
{
  if (this == &sys)
  {
    return;
  }
  value = sys.getValue();
}

SystemImplement &SystemImplement::operator=(const System &sys)
{
  if (this == &sys)
  {
    return *this;
  }
  setValue(sys.getValue());
  return *this;
}

SystemImplement::SystemImplement(double v)
{
  value = v;
}

SystemImplement::~SystemImplement(){}

double SystemImplement::getValue() const
{
  return value;
}

void SystemImplement::setValue(double v)
{
  value = v;
}

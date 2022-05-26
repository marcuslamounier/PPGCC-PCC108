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

double SystemBody::getValue() const
{
  return value;
}

void SystemBody::setValue(double v)
{
  value = v;
}

SystemHandle::SystemHandle()
{
  pImpl_ = new SystemBody();
  pImpl_->attach();
};

SystemHandle::SystemHandle(double v)
{
  pImpl_ = new SystemBody();
  pImpl_->setValue(v);
  pImpl_->attach();
};

void SystemHandle::setValue(double v)
{
  pImpl_->setValue(v);
}

double SystemHandle::getValue() const
{
  return pImpl_->getValue();
}

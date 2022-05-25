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

// SystemHandle(const SystemHandle *sys) {}

// SystemHandle &operator=(const SystemHandle &hd);
// {
//   if (this != &hd)
//   {
//     hd.pImpl_->attach();
//     pImpl_->detach();
//     pImpl_ = hd.pImpl_;
//   }
//   return *this;
// }

void SystemHandle::setValue(double v)
{
  pImpl_->setValue(v);
}

double SystemHandle::getValue() const
{
  return pImpl_->getValue();
}

/**
 * @file System.cpp
 *
 * @brief Implementation of class Model
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */


#include <iostream>
#include "System.h"

using namespace std;

System::System (const System& sys) {
  if (this == &sys) {
    return;
  }
  value = sys.getValue();
}

System& System::operator=(const System& sys) {
  if (this == &sys) {
    return *this;
  }
  setValue(sys.getValue());
  return *this;
}

System::System(){
  value = 0;
}

System::System(double v) {
  value = v;
}

System::~System(){}

double System::getValue() const {
  return value;
}

void System::setValue(double v) {
  value = v;
}

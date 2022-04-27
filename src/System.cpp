#include <iostream>
#include "System.h"

using namespace std;

System::System (const System& sys) {
  if (this == &sys) {
    return;
  }
  value = sys.getValue();
}

// // TO-DO

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

// TO-DO

System::~System(){}

double System::getValue() const {
  return value;
}

void System::setValue(double v) {
  value = v;
}

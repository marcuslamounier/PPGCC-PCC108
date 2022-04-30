/**
 * @file Flow.h
 *
 * @brief Declaration of class Flow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include "System.h"

using namespace std;

/**
 * @class Flow
 *
 * @brief This is the class Flow.
 *
 * The class Flow is used for carrying energy from one system to another.
 */

class Flow
{
protected:
  /// Pointer for the source System
  System *source;
  /// Pointer for the target System
  System *target;
  /// Last value carried by the Flow
  double lastValue;

public:
  /// Default constructor for Flow.
  Flow();
  /// Parameter's constructor for Flow.
  /**
   * @param from: pointer for the source System.
   * @param to: pointer for the target System.
   * @param lv: last value carried by the Flow.
   */
  Flow(System *from, System *to, double lv);
  /// Virtual destructor for Flow
  virtual ~Flow();

  /// Returns pointer for the source System.
  System *getSource();
  /// Returns pointer for the target System.
  System *getTarget();
  /// Returns the last value carried by Flow.
  double getLastValue();
  /// Updates the source System.
  /**
   * @param s pointer for the System which will be the Flow source.
   */
  void setSource(System *s);
  /// Updates the target System.
  /**
   * @param s pointer for the System which will be the Flow target.
   */
  void setTarget(System *s);
  /// Updates the last value carried by the Flow.
  /**
   * @param v last value carried by the Flow.
   */
  void setLastValue(double v);

  /// Sets NULL for the source System.
  void clearSource();
  /// Sets NULL for the target System.
  void clearTarget();
  /// Virtual method unimplemented for executing the Flow.
  /**
   * This is a @e required method for all the subclasses derived from Flow.
   * It needs to be implemented.
   */
  virtual double execute() = 0;

private:
  /// Copy constructor for Flow.
  /**
   * This is a @b private method. So it is not included in the docs.
   * @param flow: reference for the Flow which will be copied.
   */
  Flow(const Flow &flow);
  /// Override for operator "=".
  /**
   * This is a @b private method. So it is not included in the docs.
   * @param flow: reference for the Flow which will be copied.
   */
  Flow &operator=(const Flow &flow);
};

#endif

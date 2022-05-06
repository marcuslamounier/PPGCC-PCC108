/**
 * @file Flow.h
 *
 * @brief Interface for class Flow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef FLOW_H
#define FLOW_H

/**
 * @interface Flow
 *
 * @brief Interface for class Flow.
 *
 * The class Flow is used for carrying energy from one system to another.
 */

#include "System.h"

class Flow
{
public:
  /// Virtual destructor for Flow
  virtual ~Flow() {}

  /// Returns pointer for the source System.
  /**
   * @return pointer for the source System.
   */
  virtual System *getSource() const = 0;

  /// Returns pointer for the target System.
  /**
   * @return pointer for the target System.
   */
  virtual System *getTarget() const = 0;

  /// Returns the last value carried by Flow.
  /**
   * @return the last value carried by Flow.
   */
  virtual double getLastValue() const = 0;

  /// Updates the source System.
  /**
   * @param s pointer for the System which will be the Flow source.
   */
  virtual void setSource(System *s) = 0;

  /// Updates the target System.
  /**
   * @param s pointer for the System which will be the Flow target.
   */
  virtual void setTarget(System *s) = 0;

  /// Updates the last value carried by the Flow.
  /**
   * @param v last value carried by the Flow.
   */
  virtual void setLastValue(double v) = 0;

  /// Sets NULL for the source System.
  virtual void clearSource() = 0;

  /// Sets NULL for the target System.
  virtual void clearTarget() = 0;

  /// Virtual method unimplemented for executing the Flow.
  /**
   * This is a @e required method for all the subclasses derived from Flow.
   * It needs to be implemented.
   * @return the momentary flow value.
   */
  virtual double execute() = 0;
};

#endif

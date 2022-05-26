/**
 * @file FlowImplement.h
 *
 * @brief Implementation class for class Flow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef FLOW_IMPLEMENT_H
#define FLOW_IMPLEMENT_H

#include "Flow.h"
#include "BridgeTemplate.h"

/**
 * @class FlowImplement
 *
 * @brief Implementation class for class Flow.
 *
 * The class Flow is used for carrying energy from one system to another.
 */

class FlowBody : public Body
{
protected:
  /// Pointer for the source System
  System *source;

  /// Pointer for the target System
  System *target;

  /// Last value carried by the Flow
  double lastValue;

public:
  FlowBody();
  FlowBody(System *from, System *to);
  FlowBody(System *from, System *to, double lv);

  /// Returns pointer for the source System.
  /**
   * @return pointer for the source System.
   */
  System *getSource() const;

  /// Returns pointer for the target System.
  /**
   * @return pointer for the target System.
   */
  System *getTarget() const;

  /// Returns the last value carried by Flow.
  /**
   * @return the last value carried by Flow.
   */
  double getLastValue() const;

  /// Updates the source System.
  /**
   * @param s pointer for the System which will be the Flow source.
   */
  void setSource(System *sys);

  /// Updates the target System.
  /**
   * @param s pointer for the System which will be the Flow target.
   */
  void setTarget(System *sys);

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
   * @return the momentary flow value.
   */
  double execute();
  // virtual double execute() = 0;
};

class FlowHandle : public Flow, public Handle<FlowBody>
{

public:
  /// Default constructor for Flow.
  FlowHandle();

  /// Parameter's constructor for Flow.
  /**
   * @param from: pointer for the source System.
   * @param to: pointer for the target System.
   */
  FlowHandle(System *from, System *to);

  /// Parameter's constructor for Flow.
  /**
   * @param from: pointer for the source System.
   * @param to: pointer for the target System.
   * @param lv: last value carried by the Flow.
   */
  FlowHandle(System *from, System *to, double lv);

  /// Returns pointer for the source System.
  /**
   * @return pointer for the source System.
   */
  System *getSource() const;

  /// Returns pointer for the target System.
  /**
   * @return pointer for the target System.
   */
  System *getTarget() const;

  /// Returns the last value carried by Flow.
  /**
   * @return the last value carried by Flow.
   */
  double getLastValue() const;

  /// Updates the source System.
  /**
   * @param s pointer for the System which will be the Flow source.
   */
  void setSource(System *sys);

  /// Updates the target System.
  /**
   * @param s pointer for the System which will be the Flow target.
   */
  void setTarget(System *sys);

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
   * @return the momentary flow value.
   */
  double execute();
  // virtual double execute() = 0;
};

#endif

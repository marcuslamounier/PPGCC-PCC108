/**
 * @file ExponentialFlow.h
 *
 * @brief Declaration for class ExponentialFlow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef EXPONENTIAL_FLOW_H
#define EXPONENTIAL_FLOW_H

#include "../../src/FlowImplement.h"

/**
 * @class ExponentialFlow
 *
 * @brief class ExponentialFlow
 *
 * The class ExponentialFlow is used for carrying energy from one system to
 * another by a rate provided by an exponential equation.
 */

class ExponentialFlow : public FlowHandle
{
private:
  /// Factor of exponential flow transfer rate.
  double factor;

public:
  /// Default constructor for ExponentialFlow.
  ExponentialFlow();

  /// Parameter's constructor for ExponentialFlow.
  /**
   * @param from: pointer for the source System.
   * @param to: pointer for the target System.
   */
  ExponentialFlow(System *from, System *to);

  /// Parameter's constructor for ExponentialFlow.
  /**
   * @param from: pointer for the source System.
   * @param to: pointer for the target System.
   * @param f: factor of exponential flow transfer rate.
   */
  ExponentialFlow(System *from, System *to, double f);

  /// Returns the factor of exponential flow transfer rate.
  /**
   * @return the factor of exponential flow transfer rate.
   */
  double getFactor();

  /// Updates the factor of exponential flow transfer rate.
  /**
   * @param f factor which will be the exponential flow transfer rate.
   */
  void setFactor(double f);

  /// Returns the momentary flow value.
  /**
   * @return the momentary flow value.
   */
  double execute();
};

#endif

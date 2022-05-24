/**
 * @file LogisticFlow.h
 *
 * @brief Declaration for class LogisticFlow
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef LOGISTIC_FLOW_H
#define LOGISTIC_FLOW_H

#include "../../src/FlowImplement.h"

/**
 * @class LogisticFlow
 *
 * @brief class LogisticFlow.
 *
 * The class LogisticFlow is used for carrying energy from one system to another
 * by a rate provided by a logistic equation.
 */

class LogisticFlow : public FlowImplement
{
private:
  /// Factor of logistic flow transfer rate.
  double factor;

  /// Maximum flow transfer rate.
  double maxValue;

public:
  /// Default constructor for ExponentialFlow.
  LogisticFlow();

  /// Parameter's constructor for LogisticFlow.
  /**
   * @param from: pointer for the source System.
   * @param to: pointer for the target System.
   */
  LogisticFlow(System *from, System *to);

  /// Parameter's constructor for LogisticFlow.
  /**
   * @param from: pointer for the source System.
   * @param to: pointer for the target System.
   * @param f: factor of logistic flow transfer rate.
   * @param maxV: maximum flow transfer rate.
   */
  LogisticFlow(System *from, System *to, double f, double maxV);

  /// Returns the factor of logistic flow transfer rate.
  /**
   * @return the factor of logistic flow transfer rate.
   */
  double getFactor();

  /// Returns the maximum flow transfer rate.
  /**
   * @return the maximum flow transfer rate.
   */
  double getMaxValue();

  /// Updates the factor of logistic flow transfer rate.
  /**
   * @param f factor which will be the logistic flow transfer rate.
   */
  void setFactor(double f);

  /// Updates the maximum flow transfer rate.
  /**
   * @param f factor which will be the maximum flow transfer rate.
   */
  void setMaxValue(double maxV);

  /// Returns the momentary flow value.
  /**
   * @return the momentary flow value.
   */
  double execute();
};

#endif

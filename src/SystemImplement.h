/**
 * @file SystemImplement.h
 *
 * @brief Implementation class for class System
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include "System.h"
#include "BridgeTemplate.h"

/**
 * @class SystemImplement
 *
 * @brief Implementation class for class System.
 *
 * The class System will hold the energy.
 */

class SystemBody: public Body
{
protected:
  /// Value stored in the System.
  double value;

public:
  /// Returns the value stored in the System.
  /**
   * @return the value stored in the System.
   */
  double getValue() const;

  /// Updates the value stored in the System.
  /**
   * @param v current value stored in the System.
   */
  void setValue(double v);
};

class SystemHandle : public System, public Handle<SystemBody>
{
public:
  /// Default constructor for System.
  SystemHandle();

  /// Parameter's constructor for System.
  /**
   * @param v: value stored in the System.
   */
  SystemHandle(double v);

  /// Returns the value stored in the System.
  /**
   * @return the value stored in the System.
   */
  double getValue() const;
  
  /// Updates the value stored in the System.
  /**
   * @param v current value stored in the System.
   */
  void setValue(double v);
};

#endif

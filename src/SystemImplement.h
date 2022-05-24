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

/**
 * @class SystemImplement
 *
 * @brief Implementation class for class System.
 *
 * The class System will hold the energy.
 */

class SystemImplement : public System
{
protected:
  /// Value stored in the System.
  double value;

public:
  /// Default constructor for System.
  SystemImplement();

  /// Parameter's constructor for System.
  /**
   * @param v: value stored in the System.
   */
  SystemImplement(double v);

  /// Virtual destructor for System
  virtual ~SystemImplement();

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

private:
  /// Copy constructor for System.
  /**
   * @param sys: reference for the System which will be copied.
   */
  SystemImplement(const System &sys);

  /// Overloads for operator "=".
  /**
   * @param sys: reference for the System which will be copied.
   */
  SystemImplement &operator=(const System &sys);
};

#endif

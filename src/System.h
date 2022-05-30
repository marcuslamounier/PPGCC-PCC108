/**
 * @file System.h
 *
 * @brief Interface for class System
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef SYSTEM_IMPLEMENT_H
#define SYSTEM_IMPLEMENT_H

/**
 * @interface System
 *
 * @brief Interface for class System.
 *
 * The class System will hold the energy.
 */

class System
{
public:
  /// Virtual destructor for Flow
  virtual ~System() = default;

  /// Returns the value stored in the System.
  /**
   * @return the value stored in the System.
   */
  virtual double getValue() const = 0;

  /// Updates the value stored in the System.
  /**
   * @param v current value stored in the System.
   */
  virtual void setValue(double v) = 0;
};

#endif

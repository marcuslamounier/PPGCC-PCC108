/**
 * @file System.h
 *
 * @brief Declaration of class System
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef SYSTEM_H
#define SYSTEM_H

/**
 * @class System
 *
 * @brief This is the class System.
 *
 * The class System will hold the energy.
 */

class System
{
protected:
  /// Value stored in the System.
  double value;

public:
  /// Default constructor for System.
  System();
  /// Parameter's constructor for System.
  /**
   * @param v: value stored in the System.
   */
  System(double v = 0.0);
  /// Copy constructor for System.
  /**
   * @param sys: reference for the System which will be copied.
   */
  System(const System &sys);
  /// Virtual destructor for System
  virtual ~System();

  /// Override for operator "=".
  /**
   * @param sys: reference for the System which will be copied.
   */
  System &operator=(const System &sys);

  /// Returns the value stored in the System.
  double getValue() const;
  /// Updates the value stored in the System.
  /**
   * @param v current value stored in the System.
   */
  void setValue(double v);
};

#endif

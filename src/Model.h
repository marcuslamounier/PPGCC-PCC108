/**
 * @file Model.h
 *
 * @brief Interface for class Model
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef MODEL_H
#define MODEL_H

/**
 * @interface Model
 *
 * @brief Interface for class Model.
 *
 * The class Model is the program's main class.
 */

#include <vector>
#include "System.h"
#include "Flow.h"

using namespace std;

class Model
{
public:
  /// Iterator for array of System pointers.
  typedef vector<System *>::iterator iteratorSystem;

  /// Iterator for array of Flow pointers.
  typedef vector<Flow *>::iterator iteratorFlow;

  /// Virtual destructor for Model
  virtual ~Model() {}

  /// Returns pointer for the first System in the array.
  /**
   * @return pointer for the first System in the array.
   */
  virtual iteratorSystem firstSystem() = 0;

  /// Returns pointer for the last System in the array.
  /**
   * @return pointer for the last System in the array.
   */
  virtual iteratorSystem lastSystem() = 0;

  /// Returns pointer for the first Flow in the array.
  /**
   * @return pointer for the first Flow in the array.
   */
  virtual iteratorFlow firstFlow() = 0;

  /// Returns pointer for the last Flow in the array.
  /**
   * @return pointer for the last Flow in the array.
   */
  virtual iteratorFlow lastFlow() = 0;

  /// Returns System pointer for System in index-th position.
  /**
   * @return System pointer for System in index-th position.
   */
  virtual System *getSystem(int index) = 0;

  /// Returns Flow pointer for Flow in index-th position.
  /**
   * @return Flow pointer for Flow in index-th position.
   */
  virtual Flow *getFlow(int index) = 0;

  /// Returns current time in Model execution.
  /**
   * @return current time in Model execution.
   */
  virtual int getTime() const = 0;

  /// Updates current time in Model execution.
  /**
   * @param t current time.
   */
  virtual void setTime(int t) = 0;

  /// Increments the time in Model execution.
  /**
   * @param incr increment step for the Model execution.
   */
  virtual void incrementTime(int incr = 1) = 0;

  /// Adds System to the Model graph.
  /**
   * @param s pointer to the System which will be added to the Model.
   */
  virtual void add(System *s) = 0;

  /// Adds Flow to the Model graph.
  /**
   * @param f pointer to the Flow which will be added to the Model.
   */
  virtual void add(Flow *f) = 0;

  /// Removes System to the Model graph.
  /**
   * @param f pointer to the System which will be removed to the Model.
   */
  virtual void remove(System *s) = 0;

  /// Removes Flow to the Model graph.
  /**
   * @param f pointer to the Flow which will be removed to the Model.
   */
  virtual void remove(Flow *f) = 0;

  /// Executes the Model.
  /**
   * @param start start time for the Model execution.
   * @param final final time for the Model execution.
   * @param incr increment step for the Model execution.
   */
  virtual void execute(int start, int final, int incr) = 0;
};

#endif

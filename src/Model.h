/**
 * @file Model.h
 *
 * @brief Declaration of class Model
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef MODEL_H
#define MODEL_H

/**
 * @class Model
 *
 * @brief This is the class Model.
 *
 * The class Model is the program's main class.
 */

#include <vector>
#include "System.h"
#include "Flow.h"

using namespace std;

class Model
{
protected:
  /// Actual time which the model execution is positioned.
  int time;
  /// Array of System pointers for systems.
  vector<System *> systems;
  /// Array of Flow pointers for flows.
  vector<Flow *> flows;

public:
  /// Iterator for array of System pointers.
  typedef vector<System *>::iterator iterSystem;
  /// Iterator for array of Flow pointers.
  typedef vector<Flow *>::iterator iterFlow;

  /// Default constructor for Model.
  Model();
  /// Parameter's constructor for System.
  /**
   * @param t: start time for Model execution.
   */
  Model(int t);
  /// Virtual destructor for Model
  ~Model();

  /// Returns pointer for the first System in the array.
  iterSystem firstSystem();
  /// Returns pointer for the last System in the array.
  iterSystem lastSystem();
  /// Returns pointer for the first Flow in the array.
  iterFlow firstFlow();
  /// Returns pointer for the last Flow in the array.
  iterFlow lastFlow();

  /// Returns the current time in Model execution.
  int getTime() const;
  /// Updates the current time in Model execution.
  /**
   * @param t current time.
   */
  void setTime(int t);
  /// Increments the time in Model execution.
  /**
   * @param incr increment step for the Model execution.
   */
  void incrementTime(int incr);

  /// Adds System to the Model graph.
  /**
   * @param s pointer to the System which will be added to the Model.
   */
  void add(System *s);
  /// Adds Flow to the Model graph.
  /**
   * @param f pointer to the Flow which will be added to the Model.
   */
  void add(Flow *f);
  /// Removes System to the Model graph.
  /**
   * @param f pointer to the System which will be removed to the Model.
   */
  void remove(System *s);
  /// Removes Flow to the Model graph.
  /**
   * @param f pointer to the Flow which will be removed to the Model.
   */
  void remove(Flow *f);
  /// Executes the Model.
  /**
   * @param start start time for the Model execution.
   * @param final final time for the Model execution.
   * @param incr increment step for the Model execution.
   */
  void execute(int start, int final, int incr);

private:
  /// Copy constructor for Model.
  /**
   * This is a @b private method. So it is not included in the docs.
   * @param model: reference for the Model which will be copied.
   */
  Model(const Model &model);
  /// Override for operator "=".
  /**
   * This is a @b private method. So it is not included in the docs.
   * @param model: reference for the Model which will be copied.
   */
  Model &operator=(const Model &model);
};

#endif

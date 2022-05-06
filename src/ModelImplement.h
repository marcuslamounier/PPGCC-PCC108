/**
 * @file ModelImplement.h
 *
 * @brief Declaration for class Model
 *
 * @author Marcus V. Lamounier Quadros
 * Contact: marcus.quadros@ufop.edu.br
 *
 */

#ifndef MODEL_IMPLEMENT_H
#define MODEL_IMPLEMENT_H

#include "Model.h"

/**
 * @class Model
 *
 * @brief This is the class Model.
 *
 * The class Model is the program's main class.
 */

class ModelImplement : public Model
{
protected:
  /// Actual time which the model execution is positioned.
  int time;

  /// Array of System pointers for systems.
  vector<System *> systems;

  /// Array of Flow pointers for flows.
  vector<Flow *> flows;
  
public:
  /// Default constructor for Model.
  ModelImplement();

  /// Parameter's constructor for System.
  /**
   * @param t: start time for Model execution.
   */
  ModelImplement(int t);

  /// Virtual destructor for Model
  virtual ~ModelImplement();

  /// Returns pointer for the first System in the array.
  /**
   * @return iteratorSystem
   */
  iteratorSystem firstSystem();

  /// Returns pointer for the last System in the array.
  /**
   * @return iteratorSystem
   */
  iteratorSystem lastSystem();

  /// Returns pointer for the first Flow in the array.
  /**
   * @return iteratorFlow
   */
  iteratorFlow firstFlow();

  /// Returns pointer for the last Flow in the array.
  /**
   * @return iteratorFlow
   */
  iteratorFlow lastFlow();

  /// Returns System pointer for System in index-th position.
  /**
   * @return System*
   */
  System *getSystem(int index);

  /// Returns Flow pointer for Flow in index-th position.
  /**
   * @return Flow*
   */
  Flow *getFlow(int index);

  /// Returns the current time in Model execution.
  /**
   * @return int
   */
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
  void incrementTime(int incr = 1);

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
  void execute(int start = 1, int final = 100, int incr = 1);

private:
  /// Copy constructor for Model.
  /**
   * This is a @b private method. So it is not included in the docs.
   * @param model: reference for the Model which will be copied.
   */
  ModelImplement(const Model &model);

  /// Override for operator "=".
  /**
   * This is a @b private method. So it is not included in the docs.
   * @param model: reference for the Model which will be copied.
   */
  ModelImplement &operator=(const Model &model);

};

#endif

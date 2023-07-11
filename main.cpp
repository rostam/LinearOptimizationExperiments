#include "ortools/linear_solver/linear_solver.h"
#include "ortools/linear_solver/linear_solver.pb.h"

namespace operations_research {
void RunLinearExample() {
  MPSolver solver("LinearExample", MPSolver::GLOP_LINEAR_PROGRAMMING);

  const double infinity = solver.infinity();
  // Create the variables x and y.
  MPVariable* const x = solver.MakeNumVar(0.0, infinity, "x");
  MPVariable* const y = solver.MakeNumVar(0.0, infinity, "y");

  // Create the objective function, 3 * x + y.
  MPObjective* const objective = solver.MutableObjective();
  objective->SetCoefficient(x, 3);
  objective->SetCoefficient(y, 1);
  objective->SetMaximization();

  // Call the solver and display the results.
  solver.Solve();
  LOG(INFO) << "Solution:";
  LOG(INFO) << "Objective value = " << objective->Value();
  LOG(INFO) << "x = " << x->solution_value();
  LOG(INFO) << "y = " << y->solution_value();
}
}  // namespace operations_research

int main() {
  operations_research::RunLinearExample();
  return EXIT_SUCCESS;
}

#ifndef A1_MAZE_SRC_MODEL_MAZE_SOLVER_H_

#define A1_MAZE_SRC_MODEL_MAZE_SOLVER_H_

#include <iostream>
#include <vector>

#include "maze_data.h"

namespace s21 {

class MazeSolver {
 public:
  using path_value = std::vector<std::vector<int>>;
  MazeSolver() : maze_(nullptr) {}

  void SetMaze(const MazeData& data);

  std::vector<Point> SolveMaze(const Point& start, const Point& end);

  std::vector<Point> BuildPath(const path_value& wave, const Point& end);

 private:
  void PrepareVector(path_value& wave, size_t rows, size_t cols);
  void WaveStep(path_value& wave, size_t i, size_t j, unsigned count);

  const MazeData* maze_;
};

}  // namespace s21

#endif

#ifndef A1_MAZE_SRC_MODEL_MAZE_GENERATOR_H_

#define A1_MAZE_SRC_MODEL_MAZE_GENERATOR_H_

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "maze_data.h"

namespace s21 {

class MazeGenerator {
 public:
  using return_type = std::pair<const Matrix&, const Matrix&>;
  MazeGenerator() = default;

  MazeData GenerateMaze(size_t rows, size_t columns);

 private:
  void ClearLine();
  void FillCells();

  void SetRightBorders(MazeData& maze, size_t row_number);
  void SetBottomBorders(MazeData& maze, size_t row_number);

  void ClearBottomSets(MazeData& maze, size_t row_number);

  void RemovedClosedAreas(MazeData& maze, size_t row_number);

  bool RandomizeBorderStatus();
  void CombineSets(int replaced_set, int new_set);
  bool IsUniqueSet(MazeData& maze, int set, size_t row_number);

  std::vector<int> line_;
  int set_;

  const int kEmpty = 0;
};

}  // namespace s21

#endif

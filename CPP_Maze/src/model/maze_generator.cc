#include "maze_generator.h"

namespace s21 {

MazeData MazeGenerator::GenerateMaze(size_t rows, size_t columns) {
  MazeData maze;
  maze.is_correct = true;
  maze.SetSize(rows, columns);
  line_.resize(columns);
  ClearLine();
  for (size_t i = 0; i < rows; i++) {
    FillCells();
    SetRightBorders(maze, i);
    SetBottomBorders(maze, i);
    if (i < rows - 1) {
      ClearBottomSets(maze, i);
    } else {
      RemovedClosedAreas(maze, i);
    }
  }
  return maze;
}

bool MazeGenerator::RandomizeBorderStatus() {
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_int_distribution<int> dist(0, 1);
  return static_cast<bool>(dist(engine));
}

void MazeGenerator::ClearLine() {
  set_ = 1;
  for (size_t i = 0; i < line_.size(); i++) {
    line_[i] = kEmpty;
  }
}

void MazeGenerator::FillCells() {
  for (size_t i = 0; i < line_.size(); i++) {
    if (line_[i] == kEmpty) {
      line_[i] = set_;
      set_++;
    }
  }
}

void MazeGenerator::SetRightBorders(MazeData& maze, size_t row_number) {
  for (size_t i = 0; i < line_.size() - 1; i++) {
    bool status = RandomizeBorderStatus();
    if (status || line_[i] == line_[i + 1]) {
      maze.right_borders(row_number, i) = true;
    } else {
      CombineSets(line_[i + 1], line_[i]);
    }
  }
  maze.right_borders(row_number, line_.size() - 1) = true;
}

void MazeGenerator::SetBottomBorders(MazeData& maze, size_t row_number) {
  for (size_t i = 0; i < line_.size(); i++) {
    bool status = RandomizeBorderStatus();
    if (row_number == maze.bottom_borders.GetRows() - 1 ||
        (status && !IsUniqueSet(maze, line_[i], row_number))) {
      maze.bottom_borders(row_number, i) = true;
    }
  }
}

bool MazeGenerator::IsUniqueSet(MazeData& maze, int set, size_t row_number) {
  size_t count = 0;
  for (size_t i = 0; i < line_.size() && count <= 1; i++) {
    if (line_[i] == set && !maze.bottom_borders(row_number, i)) {
      count++;
    }
  }
  return count == 1;
}

void MazeGenerator::CombineSets(int replaced_set, int new_set) {
  for (size_t i = 0; i < line_.size(); i++) {
    if (line_[i] == replaced_set) {
      line_[i] = new_set;
    }
  }
}

void MazeGenerator::ClearBottomSets(MazeData& maze, size_t row_number) {
  for (size_t i = 0; i < line_.size(); i++) {
    if (maze.bottom_borders(row_number, i)) {
      line_[i] = kEmpty;
    }
  }
}

void MazeGenerator::RemovedClosedAreas(MazeData& maze, size_t row_number) {
  for (size_t i = 0; i < line_.size() - 1; i++) {
    if (line_[i] != line_[i + 1] && maze.right_borders(row_number, i)) {
      maze.right_borders(row_number, i) = false;
      CombineSets(line_[i + 1], line_[i]);
    }
  }
}
}  // namespace s21
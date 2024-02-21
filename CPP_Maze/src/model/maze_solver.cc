#include "maze_solver.h"

namespace s21 {

void MazeSolver::SetMaze(const MazeData& data) { maze_ = &data; }

std::vector<Point> MazeSolver::SolveMaze(const Point& start, const Point& end) {
  std::vector<Point> empty;
  if (maze_ != nullptr && maze_->is_correct && start != end) {
    path_value wave;
    PrepareVector(wave, maze_->right_borders.GetRows(),
                  maze_->right_borders.GetColumns());
    unsigned count = 1;
    wave[start.row_number].at(start.col_number) = count;
    count++;
    WaveStep(wave, start.row_number, start.col_number, count);
    if (wave[end.row_number][end.col_number] == 0) {
      return empty;
    }
    return BuildPath(wave, end);
  }
  return empty;
}

std::vector<Point> MazeSolver::BuildPath(const path_value& wave,
                                         const Point& end) {
  std::vector<Point> result;
  result.reserve(wave[end.row_number][end.col_number]);
  size_t i = end.row_number;
  size_t j = end.col_number;
  result.push_back(Point(i, j));
  while (wave[i][j] != 1) {
    if (j > 0 && wave[i][j - 1] < wave[i][j] &&
        !maze_->right_borders(i, j - 1)) {
      j--;
    } else if (j + 1 < wave[i].size() && wave[i][j + 1] < wave[i][j] &&
               !maze_->right_borders(i, j)) {
      j++;
    } else if (i > 0 && wave[i - 1][j] < wave[i][j] &&
               !maze_->bottom_borders(i - 1, j)) {
      i--;
    } else if (i + 1 < wave.size() && wave[i + 1][j] < wave[i][j] &&
               !maze_->bottom_borders(i, j)) {
      i++;
    }
    Point tmp(i, j);
    result.push_back(tmp);
  }
  return result;
}

void MazeSolver::PrepareVector(path_value& wave, size_t rows, size_t cols) {
  wave.resize(rows);
  for (size_t i = 0; i < rows; i++) {
    wave[i].resize(cols);
  }
}

void MazeSolver::WaveStep(path_value& wave, size_t i, size_t j,
                          unsigned count) {
  if (j > 0 && !maze_->right_borders(i, j - 1) && wave[i].at(j - 1) == 0) {
    wave[i].at(j - 1) = count;
    WaveStep(wave, i, j - 1, count + 1);
  }
  if (i > 0 && !maze_->bottom_borders(i - 1, j) && wave[i - 1].at(j) == 0) {
    wave[i - 1].at(j) = count;
    WaveStep(wave, i - 1, j, count + 1);
  }
  if (i + 1 < maze_->bottom_borders.GetRows() && !maze_->bottom_borders(i, j) &&
      wave[i + 1].at(j) == 0) {
    wave[i + 1].at(j) = count;
    WaveStep(wave, i + 1, j, count + 1);
  }
  if (j + 1 < maze_->bottom_borders.GetColumns() &&
      !maze_->right_borders(i, j) && wave[i].at(j + 1) == 0) {
    wave[i].at(j + 1) = count;
    WaveStep(wave, i, j + 1, count + 1);
  }
}
}  // namespace s21

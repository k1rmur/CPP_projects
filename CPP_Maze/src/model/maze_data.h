#ifndef A1_MAZE_SRC_MODEL_MAZE_DATA_H_

#define A1_MAZE_SRC_MODEL_MAZE_DATA_H_

#include "../modules/matrix.h"

namespace s21 {

struct Point {
  size_t row_number;
  size_t col_number;

  Point() {
    row_number = 0;
    col_number = 0;
  }

  Point(size_t i, size_t j) {
    row_number = i;
    col_number = j;
  }

  void SetPoint(size_t i, size_t j) {
    row_number = i;
    col_number = j;
  }

  void Reset() {
    row_number = 0;
    col_number = 0;
  }

  bool operator==(const Point& other) const {
    return row_number == other.row_number && col_number == other.col_number;
  }

  bool operator!=(const Point& other) const { return !(*this == other); }
};

struct MazeData {
  Matrix right_borders;
  Matrix bottom_borders;
  bool is_correct;

  void SetSize(size_t rows, size_t columns) {
    right_borders.SetColumns(columns);
    right_borders.SetRows(rows);

    bottom_borders.SetColumns(columns);
    bottom_borders.SetRows(rows);
  }
};
}  // namespace s21
#endif

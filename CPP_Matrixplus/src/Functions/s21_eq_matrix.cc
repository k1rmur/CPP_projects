#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) noexcept {
  bool res = true;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-07) {
          res = false;
        }
      }
    }
  } else {
    res = false;
  }
  return res;
}
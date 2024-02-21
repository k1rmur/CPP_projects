#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix new_matrix(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      new_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return new_matrix;
}
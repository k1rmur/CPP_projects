#include "s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix &other) {
  S21Matrix tmp(rows_, other.cols_);
  if (cols_ == other.rows_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        tmp(i, j) = 0;
        for (int k = 0; k < other.rows_; k++) {
          tmp(i, j) += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    *this = std::move(tmp);
  } else {
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix");
  }
}
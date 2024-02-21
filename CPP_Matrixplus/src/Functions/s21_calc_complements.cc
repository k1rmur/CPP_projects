#include "s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result_(cols_, rows_);
  if (cols_ == rows_) {
    result_ = this->FindComplements();
  } else {
    throw std::invalid_argument("The matrix is not square");
  }
  return result_;
}

S21Matrix S21Matrix::FindComplements() noexcept {
  S21Matrix result(rows_, cols_);
  if (cols_ == 1 && rows_ == cols_) {
    result.matrix_[0][0] = matrix_[0][0];
  } else {
    if (cols_ == rows_) {
      S21Matrix tmp(rows_, cols_);
      for (int r = 0; r < rows_; r++) {
        for (int c = 0; c < cols_; c++) {
          FindMinor(&tmp, *this, c, r);
          result.matrix_[r][c] = FindDet(tmp.matrix_, rows_ - 1, cols_ - 1);
        }
      }
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          result.matrix_[i][j] *= pow(-1, i + j);
        }
      }
    }
  }
  return result;
}

void S21Matrix::FindMinor(S21Matrix *tmp, const S21Matrix &A, int c,
                          int r) noexcept {
  int i2 = 0;
  for (int i = 0; i < A.rows_; i++) {
    if (i == r) {
      continue;
    } else {
      int j2 = 0;
      for (int j = 0; j < A.cols_; j++) {
        if (j != c) {
          tmp->matrix_[i2][j2] = A.matrix_[i][j];
          j2++;
        }
      }
      i2++;
    }
  }
}
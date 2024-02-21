#include "s21_matrix_oop.h"

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int num) noexcept {
  if (num > 0) {
    S21Matrix tmp(num, cols_);
    if (num > rows_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          tmp(i, j) = matrix_[i][j];
        }
      }
      *this = std::move(tmp);
    } else if (rows_ > num) {
      for (int i = 0; i < num; i++) {
        for (int j = 0; j < cols_; j++) {
          tmp(i, j) = matrix_[i][j];
        }
      }
      *this = std::move(tmp);
    }
  }
}

void S21Matrix::SetCols(int num) noexcept {
  if (num > 0) {
    S21Matrix tmp(rows_, num);
    if (num > cols_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          tmp(i, j) = matrix_[i][j];
        }
      }
      *this = std::move(tmp);
    } else if (rows_ > num) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < num; j++) {
          tmp(i, j) = matrix_[i][j];
        }
      }
      *this = std::move(tmp);
    }
  }
}
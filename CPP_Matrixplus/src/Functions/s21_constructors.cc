#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {  // Basic constructor that initialises a matrix 3x3
  matrix_ = new double *[3];
  for (int i = 0; i < 3; i++) {
    matrix_[i] = new double[3]();
  }
  rows_ = 3;
  cols_ = 3;
}

S21Matrix::S21Matrix(int rows, int cols)
    : rows_{rows}, cols_{cols} {  // Parametrized constructor
  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new double *[rows];
    for (int i = 0; i < rows; i++) {
      matrix_[i] = new double[cols]();
    }
  } else {
    throw std::invalid_argument("Rows or Columns < 1");
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) {  // Copy constructor
  matrix_ = new double *[other.rows_];
  for (int i = 0; i < other.rows_; i++) {
    matrix_[i] = new double[other.cols_]();
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {  // Move constructor
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {  // Destructor
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

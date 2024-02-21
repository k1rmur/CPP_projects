#include "s21_matrix_oop.h"

S21Matrix &S21Matrix::operator=(
    const S21Matrix &other) noexcept {  // Copy assignment
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
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
  return *this;
}

S21Matrix &S21Matrix::operator=(
    S21Matrix &&other) noexcept {  // Move assignment
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.cols_ = 0;
  other.rows_ = 0;
  return *this;
}

S21Matrix &S21Matrix::operator*(const S21Matrix &other) noexcept {
  MulMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept {
  bool res = EqMatrix(other);
  return res;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) noexcept {
  this->MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) noexcept {
  this->MulNumber(num);
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) noexcept {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) noexcept {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-(const S21Matrix &other) noexcept {
  this->SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator+(const S21Matrix &other) noexcept {
  this->SumMatrix(other);
  return *this;
}

double &S21Matrix::operator()(int i, int j) noexcept { return matrix_[i][j]; }

S21Matrix operator*(const double num, const S21Matrix &other) noexcept {
  S21Matrix new_matrix(other.rows_, other.cols_);
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      new_matrix.matrix_[i][j] = other.matrix_[i][j];
    }
  }
  new_matrix.MulNumber(num);
  return new_matrix;
}

S21Matrix operator*(const S21Matrix &other, const double num) noexcept {
  S21Matrix new_matrix(other.rows_, other.cols_);
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      new_matrix.matrix_[i][j] = other.matrix_[i][j];
    }
  }
  new_matrix.MulNumber(num);
  return new_matrix;
}

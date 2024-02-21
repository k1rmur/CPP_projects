#include "matrix.h"

namespace s21 {

Matrix::Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new bool *[rows_];
  for (size_t i = 0; i < rows_; i++) {
    try {
      matrix_[i] = new bool[cols_]();
    } catch (...) {
      for (size_t j = 0; j < i; j++) {
        delete[] matrix_[i];
      }
      delete[] matrix_;
      throw;
    }
  }
}

Matrix::~Matrix() {
  for (size_t i = 0; i < rows_; i++) {
    delete[] matrix_[i];
    matrix_[i] = nullptr;
  }
  delete[] matrix_;
  matrix_ = nullptr;
  cols_ = 0;
  rows_ = 0;
}

Matrix::Matrix(size_t row, size_t col) : rows_(row), cols_(col) {
  if (rows_ == 0 || cols_ == 0) {
    throw std::length_error(
        "Error: The number of rows and columns must be greater than zero!");
  }
  matrix_ = new bool *[rows_];
  for (size_t i = 0; i < rows_; i++) {
    try {
      matrix_[i] = new bool[cols_]();
    } catch (...) {
      for (size_t j = 0; j < i; j++) {
        delete[] matrix_[i];
      }
      delete[] matrix_;
      throw;
    }
  }
}

Matrix::Matrix(const Matrix &other) : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new bool *[rows_];
  for (size_t i = 0; i < rows_; i++) {
    try {
      matrix_[i] = new bool[cols_]();
    } catch (...) {
      for (size_t j = 0; j < i; j++) {
        delete[] matrix_[i];
      }
      delete[] matrix_;
      throw;
    }
    std::memcpy(this->matrix_[i], other.matrix_[i], cols_ * sizeof(bool));
  }
}

Matrix::Matrix(Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
  if (this != &other) {
    for (size_t i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

Matrix &Matrix::operator=(const Matrix &other) {
  if (this != &other) {
    Matrix tmp(other);
    *this = std::move(tmp);
  }
  return *this;
}

void Matrix::Fill(bool value) {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; i < cols_; i++) {
      matrix_[i][j] = value;
    }
  }
}

size_t Matrix::GetRows() const noexcept { return rows_; }

size_t Matrix::GetColumns() const noexcept { return cols_; }

void Matrix::SetRows(size_t row) {
  if (rows_ != row) {
    if (row == 0) {
      throw std::length_error("Error: Rows must be > 0");
    }
    bool **new_matrix = new bool *[row];
    for (size_t i = rows_; i < row; i++) {
      try {
        new_matrix[i] = new bool[cols_]();
      } catch (...) {
        for (size_t j = rows_; j < i; j++) {
          delete[] new_matrix[j];
          delete[] new_matrix;
          throw;
        }
      }
    }
    for (size_t i = 0; i < rows_; i++) {
      if (i < row) {
        new_matrix[i] = matrix_[i];
      } else {
        delete[] matrix_[i];
      }
      matrix_[i] = nullptr;
    }
    delete[] matrix_;
    matrix_ = new_matrix;
    rows_ = row;
  }
}

void Matrix::SetColumns(size_t column) {
  Matrix newMatrix(rows_, column);
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < column && j < cols_; j++) {
      newMatrix.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(newMatrix);
}

bool Matrix::EqMatrix(const Matrix &other) const noexcept {
  bool res = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    res = false;
  } else {
    for (size_t i = 0; i < rows_ && res; i++) {
      for (size_t j = 0; j < cols_ && res; j++) {
        if (matrix_[i][j] != other.matrix_[i][j]) {
          res = false;
        }
      }
    }
  }
  return res;
}

bool Matrix::operator==(const Matrix &other) const noexcept {
  return EqMatrix(other);
}

bool &Matrix::operator()(size_t i, size_t j) {
  if (i >= rows_ || j >= cols_) {
    throw std::out_of_range("Error: Index out of bounds");
  } else {
    return matrix_[i][j];
  }
}

const bool &Matrix::operator()(size_t i, size_t j) const {
  if (i >= rows_ || j >= cols_) {
    throw std::out_of_range("Error: Index out of bounds");
  } else {
    return matrix_[i][j];
  }
}
}  // namespace s21

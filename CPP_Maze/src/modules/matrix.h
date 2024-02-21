#ifndef A1_MAZE_SRC_MODULES_MATRIX_H_

#define A1_MAZE_SRC_MODULES_MATRIX_H_

#include <cmath>
#include <cstring>
#include <stdexcept>

namespace s21 {
class Matrix {
 public:
  Matrix();
  Matrix(size_t rows, size_t cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other) noexcept;

  ~Matrix();

  size_t GetRows() const noexcept;
  size_t GetColumns() const noexcept;

  void Fill(bool value);

  void SetRows(size_t row);
  void SetColumns(size_t column);

  bool EqMatrix(const Matrix& other) const noexcept;

  Matrix& operator=(Matrix&& other) noexcept;
  Matrix& operator=(const Matrix& other);

  bool operator==(const Matrix& other) const noexcept;

  bool& operator()(size_t i, size_t j);
  const bool& operator()(size_t i, size_t j) const;

 private:
  size_t rows_ = 0;
  size_t cols_ = 0;
  bool** matrix_ = nullptr;
};
}  // namespace s21
#endif

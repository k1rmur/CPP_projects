#ifndef S21_MATRIX_HPP
#define S21_MATRIX_HPP
#include <cmath>
#include <cstring>
#include <iostream>

class S21Matrix {
 public:
  // constructors and destructor
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  // getters and setters
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int num) noexcept;
  void SetCols(int num) noexcept;

  // matrix operations
  bool EqMatrix(const S21Matrix &other) noexcept;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators
  S21Matrix &operator=(const S21Matrix &other) noexcept;
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  S21Matrix &operator*(const S21Matrix &other) noexcept;
  S21Matrix &operator*=(const S21Matrix &other) noexcept;
  S21Matrix &operator*=(const double num) noexcept;
  S21Matrix &operator+=(const S21Matrix &other) noexcept;
  S21Matrix &operator-=(const S21Matrix &other) noexcept;
  S21Matrix &operator-(const S21Matrix &other) noexcept;
  S21Matrix &operator+(const S21Matrix &other) noexcept;
  double &operator()(const int i, const int j) noexcept;
  bool operator==(const S21Matrix &other) noexcept;
  friend S21Matrix operator*(const S21Matrix &other, const double num) noexcept;
  friend S21Matrix operator*(const double num, const S21Matrix &other) noexcept;

  // another funcs
  double FindDet(double **matrix, int n, int m) noexcept;
  S21Matrix FindComplements() noexcept;
  void FindMinor(S21Matrix *tmp, const S21Matrix &A, int c, int r) noexcept;

 private:
  int rows_, cols_;  // Rows and columns
  double **matrix_;  // Pointer to the memory where the matrix is allocated
};

#endif
#include "s21_matrix_oop.h"

double S21Matrix::Determinant() {
  double d = 0;
  if (rows_ == cols_) {
    d = FindDet(matrix_, rows_, cols_);
  } else {
    throw std::invalid_argument("The matrix is not square");
  }
  return d;
}

double S21Matrix::FindDet(double **matrix, int n, int m) noexcept {
  double d = 0;
  if (n == 1) {
    d = matrix[0][0];
  } else if (n == 2) {
    d = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    for (int k = 0; k < n; k++) {
      double **ma =
          (double **)malloc(n * n * sizeof(double) + m * sizeof(double *));
      double *ptr = (double *)(ma + m);
      for (int i = 0; i < m; i++) {
        ma[i] = ptr + n * i;
      }
      for (int i = 1; i < n; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
          if (j == k) continue;
          ma[i - 1][t] = matrix[i][j];
          t++;
        }
      }
      d += pow(-1, k + 2) * matrix[0][k] * FindDet(ma, n - 1, m - 1);
      free(ma);
    }
  }
  return d;
}
#include "s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix tmp_1(rows_, cols_);
  double det = 0;
  if (rows_ == 1 && cols_ == 1 && matrix_[0][0] != 0) {
    tmp_1.matrix_[0][0] = 1 / matrix_[0][0];
  } else {
    det = this->Determinant();
    if (det == 0) {
      throw std::logic_error("Matrix determinant is 0");
    }
    if (fabs(det) > 1e-06 && det != 0) {
      tmp_1 = this->CalcComplements();
      tmp_1 = tmp_1.Transpose();
      tmp_1.MulNumber(1.0 / det);
    }
  }
  return tmp_1;
}
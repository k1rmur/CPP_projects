#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(ConstructorsSuite, TestCase1) {
  S21Matrix matrica;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_EQ(matrica(i, j), 0);
    }
  }
}

TEST(ConstructorsSuite, TestCase2) {
  S21Matrix matrica(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(matrica(i, j), 0);
    }
  }
}

TEST(ConstructorsSuite, TestCase3) {
  S21Matrix matrica(2, 2);
  matrica(0, 0) = 12.1;
  matrica(0, 1) = 223.1;
  matrica(1, 0) = 2.13;
  matrica(1, 1) = 2.11;
  S21Matrix tmp(2, 2);
  tmp = matrica;
  ASSERT_DOUBLE_EQ(tmp(0, 0), 12.1);
  ASSERT_DOUBLE_EQ(tmp(0, 1), 223.1);
  ASSERT_DOUBLE_EQ(tmp(1, 0), 2.13);
  ASSERT_DOUBLE_EQ(tmp(1, 1), 2.11);
}

TEST(ConstructorsSuite, TestCase4) {
  S21Matrix matrica(2, 2);
  matrica(0, 0) = 12.1;
  matrica(0, 1) = 223.1;
  matrica(1, 0) = 2.13;
  matrica(1, 1) = 2.11;
  S21Matrix tmp(std::move(matrica));
  ASSERT_EQ(matrica.GetCols(), 0);
  ASSERT_EQ(matrica.GetRows(), 0);
  ASSERT_DOUBLE_EQ(tmp(0, 0), 12.1);
  ASSERT_DOUBLE_EQ(tmp(0, 1), 223.1);
  ASSERT_DOUBLE_EQ(tmp(1, 0), 2.13);
  ASSERT_DOUBLE_EQ(tmp(1, 1), 2.11);
}

TEST(ConstructorsSuite, TestCase5) {
  S21Matrix matrica(2, 2);
  matrica(0, 0) = 12.1;
  matrica(0, 1) = 223.1;
  matrica(1, 0) = 2.13;
  matrica(1, 1) = 2.11;
  S21Matrix tmp(matrica);
  ASSERT_DOUBLE_EQ(tmp(0, 0), 12.1);
  ASSERT_DOUBLE_EQ(tmp(0, 1), 223.1);
  ASSERT_DOUBLE_EQ(tmp(1, 0), 2.13);
  ASSERT_DOUBLE_EQ(tmp(1, 1), 2.11);
}

TEST(ConstructorsSuite, TestCase6) {
  ASSERT_THROW(S21Matrix matrica(-2, 10), std::invalid_argument);
}

TEST(EqMatrix, TestCase1) {
  bool res = 0;
  S21Matrix matrica(3, 3);
  matrica(0, 0) = 12.1;
  matrica(0, 1) = 223.1;
  matrica(0, 2) = 243.1;
  matrica(1, 0) = 2.13;
  matrica(1, 1) = 2.11;
  matrica(1, 2) = 12.1;
  matrica(2, 0) = 2.1;
  matrica(2, 1) = 24.1;
  matrica(2, 2) = 2.1;
  S21Matrix matrica2(3, 3);
  matrica2(0, 0) = 12.1;
  matrica2(0, 1) = 223.1;
  matrica2(0, 2) = 243.1;
  matrica2(1, 0) = 2.13;
  matrica2(1, 1) = 2.11;
  matrica2(1, 2) = 12.1;
  matrica2(2, 0) = 2.1;
  matrica2(2, 1) = 24.1;
  matrica2(2, 2) = 2.1;
  res = matrica.EqMatrix(matrica2);
  ASSERT_DOUBLE_EQ(res, 1);
}

TEST(EqMatrix, TestCase2) {
  bool res = 0;
  S21Matrix matrica(3, 3);
  matrica(0, 0) = 12.1;
  matrica(0, 1) = 223.1;
  matrica(0, 2) = 243.1;
  matrica(1, 0) = 2.13;
  matrica(1, 1) = 2.11;
  matrica(1, 2) = 12.1;
  matrica(2, 0) = 2.1;
  S21Matrix matrica2(3, 3);
  matrica2(0, 0) = 12.1;
  matrica2(0, 1) = 223.1;
  matrica2(1, 1) = 2.11;
  matrica2(1, 2) = 12.1;
  matrica2(2, 0) = 2.1;
  matrica2(2, 1) = 24.1;
  matrica2(2, 2) = 2.1;
  res = matrica.EqMatrix(matrica2);
  ASSERT_DOUBLE_EQ(res, 0);
}

TEST(EqMatrix, TestCase3) {
  bool res = 0;
  S21Matrix matrica(1, 1);
  matrica(0, 0) = 12.1111;
  S21Matrix matrica2(3, 3);
  matrica2(0, 0) = 12.11112;
  res = matrica.EqMatrix(matrica2);
  ASSERT_DOUBLE_EQ(res, 0);
}

TEST(EqMatrix, TestCase4) {
  bool res = 0;
  S21Matrix matrica(10, 10);
  S21Matrix matrica2(4, 3);
  res = matrica.EqMatrix(matrica2);
  ASSERT_DOUBLE_EQ(res, 0);
}

TEST(EqMatrix, TestCase5) {
  bool res = 0;
  S21Matrix matrica(10, 10);
  S21Matrix matrica2(10, 10);
  res = matrica.EqMatrix(matrica2);
  ASSERT_DOUBLE_EQ(res, 1);
}

TEST(SumMatrix, TestCase1) {
  S21Matrix tmp(3, 3);
  S21Matrix matrica(3, 3);
  S21Matrix matrica2(3, 3);
  matrica(0, 0) = 12;
  matrica(0, 1) = 21;
  matrica(0, 2) = 24;
  matrica(1, 0) = 213;
  matrica(1, 1) = 11;
  matrica(1, 2) = 12.1;
  matrica(2, 0) = 2.1;
  matrica(2, 1) = 24.1;
  matrica(2, 2) = 2.1;
  matrica2(0, 0) = 125.1;
  matrica2(0, 1) = 2.1;
  matrica2(0, 2) = 93.1;
  matrica2(1, 0) = 1.13;
  matrica2(1, 1) = 1.11;
  matrica2(1, 2) = 12.14;
  matrica2(2, 0) = 2.2;
  matrica2(2, 1) = 13;
  matrica2(2, 2) = 23;
  tmp = matrica;
  matrica.SumMatrix(matrica2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp(i, j) += matrica2(i, j);
      ASSERT_DOUBLE_EQ(tmp(i, j), matrica(i, j));
    }
  }
}

TEST(SumMatrix, TestCase2) {
  S21Matrix matrica(3, 2);
  S21Matrix matrica2(3, 3);
  matrica(0, 0) = 12;
  matrica(0, 1) = 21;
  ASSERT_THROW(matrica.SumMatrix(matrica2), std::invalid_argument);
}

TEST(SumMatrix, TestCase3) {
  S21Matrix tmp(2, 2);
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 12;
  matrica(0, 1) = 21;
  matrica(1, 0) = 213;
  matrica(1, 1) = 11;
  tmp = matrica;
  matrica.SumMatrix(matrica2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tmp(i, j) += matrica2(i, j);
      ASSERT_DOUBLE_EQ(tmp(i, j), matrica(i, j));
    }
  }
}

TEST(SumMatrix, TestCase4) {
  S21Matrix matrica(3, 3);
  S21Matrix matrica2(3, 3);
  matrica.SumMatrix(matrica2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrica(i, j), 0);
    }
  }
}

TEST(SumMatrix, TestCase5) {
  S21Matrix matrica;
  S21Matrix matrica2;
  matrica(0, 0) = 10;
  matrica(0, 1) = 10;
  matrica(1, 0) = 10;
  matrica(1, 1) = 10;
  matrica.SumMatrix(matrica2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(matrica(i, j), 10);
    }
  }
}

TEST(SubMatrix, TestCase1) {
  S21Matrix tmp(3, 3);
  S21Matrix matrica(3, 3);
  S21Matrix matrica2(3, 3);
  matrica2(0, 0) = 1;
  matrica2(0, 1) = 2;
  matrica2(0, 2) = 2;
  matrica2(1, 0) = 3;
  matrica2(1, 1) = 11;
  matrica2(1, 2) = 1.11234;
  matrica2(2, 0) = 1;
  matrica2(2, 1) = 1;
  matrica2(2, 2) = 11;
  matrica(0, 0) = 125.111;
  matrica(0, 1) = 12.1;
  matrica(0, 2) = 93.1;
  matrica(1, 0) = 21.13;
  matrica(1, 1) = 16.11;
  matrica(1, 2) = 12.11234;
  matrica(2, 0) = 20.22;
  matrica(2, 1) = 132;
  matrica(2, 2) = 238;
  tmp(0, 0) = 124.111;
  tmp(0, 1) = 10.1;
  tmp(0, 2) = 91.1;
  tmp(1, 0) = 18.13;
  tmp(1, 1) = 5.11;
  tmp(1, 2) = 11;
  tmp(2, 0) = 19.22;
  tmp(2, 1) = 131;
  tmp(2, 2) = 227;
  matrica.SubMatrix(matrica2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(tmp(i, j), matrica(i, j));
    }
  }
}

TEST(SubMatrix, TestCase2) {
  S21Matrix matrica(3, 2);
  S21Matrix matrica2(3, 3);
  matrica2(0, 0) = 12;
  matrica2(0, 1) = 21;
  matrica2(0, 2) = 24;
  matrica2(1, 0) = 213;
  matrica2(1, 1) = 11;
  matrica2(1, 2) = 12.1;
  matrica2(2, 0) = 2.1;
  matrica2(2, 1) = 24.1;
  matrica2(2, 2) = 2.1;
  matrica(0, 0) = 125.1;
  ASSERT_THROW(matrica.SubMatrix(matrica2), std::invalid_argument);
}

TEST(SubMatrix, TestCase3) {
  S21Matrix matrica(4, 4);
  S21Matrix matrica2(4, 4);
  double test[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      test[i][j] = i + j + 2 - (i - j + j * j + 4);
      matrica(i, j) = i + j + 2;
      matrica2(i, j) = i - j + j * j + 4;
    }
  }
  matrica.SubMatrix(matrica2);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(test[i][j], matrica(i, j));
    }
  }
}

TEST(SubMatrix, TestCase4) {
  S21Matrix matrica(10, 3);
  S21Matrix matrica2(10, 3);
  double test[10][3];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 3; j++) {
      test[i][j] = i + j + 2 * i - (i - j + j * j + 3 * i);
      matrica(i, j) = i + j + 2 * i;
      matrica2(i, j) = i - j + j * j + 3 * i;
    }
  }
  matrica.SubMatrix(matrica2);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(test[i][j], matrica(i, j));
    }
  }
}

TEST(SubMatrix, TestCase5) {
  S21Matrix matrica(3, 30);
  S21Matrix matrica2(3, 30);
  double test[3][30];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 30; j++) {
      test[i][j] = i * 0.1 + j * 0.24 + 8.88 - (j * 0.95 + i * 0.65);
      matrica(i, j) = i * 0.1 + j * 0.24 + 8.88;
      matrica2(i, j) = j * 0.95 + i * 0.65;
    }
  }
  matrica.SubMatrix(matrica2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 30; j++) {
      ASSERT_EQ(test[i][j], matrica(i, j));
    }
  }
}

TEST(MulNumber, TestCase1) {
  S21Matrix matrica(1, 1);
  double num = 3;
  matrica(0, 0) = 111;
  matrica.MulNumber(num);
  ASSERT_DOUBLE_EQ(matrica(0, 0), 333);
}

TEST(MulNumber, TestCase2) {
  S21Matrix matrica(3, 3);
  double test[3][3];
  double num = 33.3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test[i][j] = ((j + 9) * 0.77 + 1.1) * num;
      matrica(i, j) = (j + 9) * 0.77 + 1.1;
    }
  }
  matrica.MulNumber(num);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(matrica(i, j), test[i][j]);
    }
  }
}

TEST(MulNumber, TestCase3) {
  S21Matrix matrica(30, 3);
  double test[30][3];
  double num = 0.999;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 3; j++) {
      test[i][j] = ((j + 9.1) * 0.1111 + 1.11111) * num;
      matrica(i, j) = (j + 9.1) * 0.1111 + 1.11111;
    }
  }
  matrica.MulNumber(num);
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(matrica(i, j), test[i][j]);
    }
  }
}

TEST(MulNumber, TestCase4) {
  S21Matrix matrica(30, 31);
  double test[30][31];
  double num = 123.456;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 31; j++) {
      test[i][j] = (num * i + num * j) * num;
      matrica(i, j) = num * i + num * j;
    }
  }
  matrica.MulNumber(num);
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 31; j++) {
      ASSERT_EQ(matrica(i, j), test[i][j]);
    }
  }
}

TEST(MulMatrix, TestCase1) {
  S21Matrix matrica(30, 21);
  S21Matrix matrica2(30, 21);
  ASSERT_THROW(matrica.MulMatrix(matrica2), std::invalid_argument);
}

TEST(MulMatrix, TestCase2) {
  double result[3][3];
  S21Matrix matrica(3, 3);
  S21Matrix matrica2(3, 3);
  matrica(0, 0) = 12;
  matrica(0, 1) = 21;
  matrica(0, 2) = 24;
  matrica(1, 0) = 213;
  matrica(1, 1) = 11;
  matrica(1, 2) = 12.1;
  matrica(2, 0) = 2.1;
  matrica(2, 1) = 24.1;
  matrica(2, 2) = 2.1;
  matrica2(0, 0) = 125.1;
  matrica2(0, 1) = 2.1;
  matrica2(0, 2) = 93.1;
  matrica2(1, 0) = 1.13;
  matrica2(1, 1) = 1.11;
  matrica2(1, 2) = 12.14;
  matrica2(2, 0) = 2.2;
  matrica2(2, 1) = 13;
  matrica2(2, 2) = 23;
  result[0][0] = 1577.73;
  result[0][1] = 360.51;
  result[0][2] = 1924.14;
  result[1][0] = 26685.35;
  result[1][1] = 616.81;
  result[1][2] = 20242.14;
  result[2][0] = 294.563;
  result[2][1] = 58.461;
  result[2][2] = 536.384;
  matrica.MulMatrix(matrica2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrica(i, j), result[i][j]);
    }
  }
}

TEST(MulMatrix, TestCase3) {
  double result[3][3];
  S21Matrix matrica(3, 3);
  S21Matrix matrica2(3, 3);
  matrica(0, 0) = 1;
  matrica(0, 1) = 1;
  matrica(0, 2) = 4;
  matrica(1, 0) = 23;
  matrica(1, 1) = 1;
  matrica(1, 2) = 1.1;
  matrica(2, 0) = 21;
  matrica(2, 1) = 241;
  matrica(2, 2) = 21;
  matrica2(0, 0) = 15.1;
  matrica2(0, 1) = 21;
  matrica2(0, 2) = 931;
  matrica2(1, 0) = 113;
  matrica2(1, 1) = 1.1;
  matrica2(1, 2) = 1211;
  matrica2(2, 0) = 2;
  matrica2(2, 1) = 3;
  matrica2(2, 2) = 3;
  result[0][0] = 136.1;
  result[0][1] = 34.1;
  result[0][2] = 2154;
  result[1][0] = 462.5;
  result[1][1] = 487.4;
  result[1][2] = 22627.3;
  result[2][0] = 27592.1;
  result[2][1] = 769.1;
  result[2][2] = 311465;
  matrica.MulMatrix(matrica2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrica(i, j), result[i][j]);
    }
  }
}

TEST(MulMatrix, TestCase4) {
  S21Matrix matrica(1, 2);
  S21Matrix matrica2(2, 1);
  matrica(0, 0) = 10;
  matrica(0, 1) = 11;
  matrica2(0, 0) = 20;
  matrica2(1, 0) = 60;
  matrica.MulMatrix(matrica2);
  ASSERT_DOUBLE_EQ(matrica(0, 0), 860);
}

TEST(MulMatrix, TestCase5) {
  double result[2][2];
  S21Matrix matrica(2, 4);
  S21Matrix matrica2(4, 2);
  matrica2(0, 0) = 1;
  matrica2(0, 1) = 2;
  matrica2(1, 0) = 3;
  matrica2(1, 1) = 4;
  matrica2(2, 0) = 5;
  matrica2(2, 1) = 6;
  matrica2(3, 0) = 7;
  matrica2(3, 1) = 8;
  matrica(0, 0) = 1;
  matrica(0, 1) = 2;
  matrica(0, 2) = 3;
  matrica(0, 3) = 4;
  matrica(1, 0) = 5;
  matrica(1, 1) = 6;
  matrica(1, 2) = 7;
  matrica(1, 3) = 8;
  result[0][0] = 50;
  result[0][1] = 60;
  result[1][0] = 114;
  result[1][1] = 140;
  matrica.MulMatrix(matrica2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(matrica(i, j), result[i][j]);
    }
  }
}

TEST(Transpose, TestCase1) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;
  S21Matrix result(2, 2);
  result = tmp.Transpose();
  S21Matrix check(2, 2);
  check(0, 0) = 1;
  check(0, 1) = 3;
  check(1, 0) = 2;
  check(1, 1) = 4;
  ASSERT_EQ(check(0, 0), result(0, 0));
  ASSERT_EQ(check(0, 1), result(0, 1));
  ASSERT_EQ(check(1, 0), result(1, 0));
  ASSERT_EQ(check(1, 1), result(1, 1));
}

TEST(Transpose, TestCase2) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;
  S21Matrix result(3, 3);
  result = tmp.Transpose();
  S21Matrix check(3, 3);
  check(0, 0) = 1;
  check(0, 1) = 4;
  check(0, 2) = 7;
  check(1, 0) = 2;
  check(1, 1) = 5;
  check(1, 2) = 8;
  check(2, 0) = 3;
  check(2, 1) = 6;
  check(2, 2) = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(check(i, j), result(i, j));
    }
  }
}

TEST(Transpose, TestCase3) {
  S21Matrix tmp(3, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  S21Matrix result = tmp.Transpose();
  S21Matrix check(2, 3);
  check(0, 0) = 1;
  check(0, 1) = 4;
  check(0, 2) = 7;
  check(1, 0) = 2;
  check(1, 1) = 5;
  check(1, 2) = 8;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(check(i, j), result(i, j));
    }
  }
}

TEST(CalcComplements, TestCase1) {
  S21Matrix matrica(4, 3);
  ASSERT_THROW(matrica.CalcComplements(), std::invalid_argument);
}

TEST(CalcComplements, TestCase2) {
  S21Matrix matrica(4, 4);
  S21Matrix result(4, 4);
  S21Matrix check(4, 4);
  matrica(0, 0) = 112.0;
  matrica(0, 1) = 243.0;
  matrica(0, 2) = 3.0;
  matrica(0, 3) = -8.0;
  matrica(1, 0) = 47.0;
  matrica(1, 1) = 51.0;
  matrica(1, 2) = -66.0;
  matrica(1, 3) = 99.0;
  matrica(2, 0) = -74.0;
  matrica(2, 1) = 85.0;
  matrica(2, 2) = 97.0;
  matrica(2, 3) = 63.0;
  matrica(3, 0) = -13.0;
  matrica(3, 1) = 79.0;
  matrica(3, 2) = -99.0;
  matrica(3, 3) = -121.0;
  check = matrica.CalcComplements();
  result(0, 0) = -2879514.0;
  result(0, 1) = -1236631.0;
  result(0, 2) = -1685096.0;
  result(0, 3) = 880697.0;
  result(1, 0) = 1162090.0;
  result(1, 1) = -714015.0;
  result(1, 2) = 4046255.0;
  result(1, 3) = -3901600.0;
  result(2, 0) = 4362897.0;
  result(2, 1) = -2049432.0;
  result(2, 2) = -532912.0;
  result(2, 3) = -1370781.0;
  result(3, 0) = 3412773.0;
  result(3, 1) = -1569493.0;
  result(3, 2) = 3144517.0;
  result(3, 3) = 1284666.0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(check(i, j), result(i, j));
    }
  }
}

TEST(CalcComplements, TestCase3) {
  S21Matrix matrica(4, 4);
  S21Matrix result(4, 4);
  S21Matrix check(4, 4);
  matrica(0, 0) = -1.0;
  matrica(0, 1) = 2.0;
  matrica(0, 2) = 7.0;
  matrica(0, 3) = 9.0;
  matrica(1, 0) = 1.0;
  matrica(1, 1) = 0.0;
  matrica(1, 2) = 0.0;
  matrica(1, 3) = 0.0;
  matrica(2, 0) = 47.0;
  matrica(2, 1) = 13.0;
  matrica(2, 2) = 17.0;
  matrica(2, 3) = 21.0;
  matrica(3, 0) = 22.0;
  matrica(3, 1) = 7.0;
  matrica(3, 2) = 1.0;
  matrica(3, 3) = 3.0;
  check = matrica.CalcComplements();
  result(0, 0) = 0.0;
  result(0, 1) = -30.0;
  result(0, 2) = -108.0;
  result(0, 3) = 106.0;
  result(1, 0) = 138.0;
  result(1, 1) = -726.0;
  result(1, 2) = -1137;
  result(1, 3) = 1061.0;
  result(2, 0) = 0.0;
  result(2, 1) = 12.0;
  result(2, 2) = 57.0;
  result(2, 3) = -47.0;
  result(3, 0) = 0.0;
  result(3, 1) = 6.0;
  result(3, 2) = -75.0;
  result(3, 3) = 57.0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_DOUBLE_EQ(check(i, j), result(i, j));
    }
  }
}

TEST(CalcComplements, TestCase4) {
  S21Matrix matrica(1, 1);
  S21Matrix result(1, 1);
  S21Matrix check(1, 1);
  matrica(0, 0) = 999.111;
  check = matrica.CalcComplements();
  result(0, 0) = 999.111;
  ASSERT_DOUBLE_EQ(check(0, 0), result(0, 0));
}

TEST(Determinant, TestCase1) {
  S21Matrix matrica(2, 3);
  ASSERT_THROW(matrica.Determinant(), std::invalid_argument);
}

TEST(Determinant, TestCase2) {
  S21Matrix matrica(1, 1);
  matrica(0, 0) = 55;
  double det = matrica.Determinant();
  ASSERT_EQ(55, det);
}

TEST(Determinant, TestCase3) {
  S21Matrix matrica(3, 3);
  matrica(0, 0) = 1.0;
  matrica(0, 1) = -77.0;
  matrica(0, 2) = 1.0;
  matrica(1, 0) = 2.0;
  matrica(1, 1) = 77.0;
  matrica(1, 2) = 8.0;
  matrica(2, 0) = -1.5;
  matrica(2, 1) = 11.0;
  matrica(2, 2) = 32.0;
  double det = matrica.Determinant();
  ASSERT_DOUBLE_EQ(8365.5, det);
}

TEST(Determinant, TestCase4) {
  S21Matrix matrica(3, 3);
  matrica(0, 0) = 1.1;
  matrica(0, 1) = 1.0;
  matrica(0, 2) = 2.0;
  matrica(1, 0) = 3.0;
  matrica(1, 1) = 1.0;
  matrica(1, 2) = 2.0;
  matrica(2, 0) = 3.0;
  matrica(2, 1) = 100.0;
  matrica(2, 2) = 122.0;
  double det = matrica.Determinant();
  ASSERT_DOUBLE_EQ(148.2, det);
}

TEST(Determinant, TestCase5) {
  S21Matrix matrica(4, 4);
  matrica(0, 0) = -1.1;
  matrica(0, 1) = 2.2;
  matrica(0, 2) = 7.3;
  matrica(0, 3) = 9.4;
  matrica(1, 0) = 1.5;
  matrica(1, 1) = 0.6;
  matrica(1, 2) = 0.7;
  matrica(1, 3) = 0.8;
  matrica(2, 0) = 47.9;
  matrica(2, 1) = 13.1;
  matrica(2, 2) = 17.2;
  matrica(2, 3) = 21.3;
  matrica(3, 0) = 22.4;
  matrica(3, 1) = 7.5;
  matrica(3, 2) = 1.6;
  matrica(3, 3) = 3.7;
  double det = matrica.Determinant();
  ASSERT_DOUBLE_EQ(-197.355, det);
}

TEST(InverseMatrix, TestCase1) {
  S21Matrix matrica(3, 3);
  matrica(0, 0) = 1;
  matrica(0, 1) = 2;
  matrica(0, 2) = 3;
  matrica(1, 0) = 4;
  matrica(1, 1) = 5;
  matrica(1, 2) = 6;
  matrica(2, 0) = 7;
  matrica(2, 1) = 8;
  matrica(2, 2) = 9;
  ASSERT_THROW(matrica.InverseMatrix(), std::logic_error);
}

TEST(InverseMatrix, TestCase2) {
  S21Matrix matrica(3, 4);
  ASSERT_THROW(matrica.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrix, TestCase3) {
  S21Matrix matrica(3, 3);
  S21Matrix result(3, 3);
  matrica(0, 0) = 1;
  matrica(0, 1) = 5;
  matrica(0, 2) = 3;
  matrica(1, 0) = 2;
  matrica(1, 1) = 5;
  matrica(1, 2) = 9;
  matrica(2, 0) = 6;
  matrica(2, 1) = 8;
  matrica(2, 2) = 10;
  result(0, 0) = (-11.0 / 53.0);
  result(0, 1) = (-13.0 / 53.0);
  result(0, 2) = (15.0 / 53.0);
  result(1, 0) = (17.0 / 53.0);
  result(1, 1) = (-4.0 / 53.0);
  result(1, 2) = (-3.0 / 106.0);
  result(2, 0) = (-7.0 / 53.0);
  result(2, 1) = (11.0 / 53.0);
  result(2, 2) = (-5.0 / 106.0);
  S21Matrix check(3, 3);
  check = matrica.InverseMatrix();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(check(i, j), result(i, j));
    }
  }
}

TEST(InverseMatrix, TestCase4) {
  S21Matrix matrica(4, 4);
  S21Matrix result(4, 4);
  matrica(0, 0) = -1.0;
  matrica(0, 1) = 2.0;
  matrica(0, 2) = 7.0;
  matrica(0, 3) = 9.0;
  matrica(1, 0) = 1.0;
  matrica(1, 1) = 0.0;
  matrica(1, 2) = 0.0;
  matrica(1, 3) = 0.0;
  matrica(2, 0) = 47.0;
  matrica(2, 1) = 13.0;
  matrica(2, 2) = 17.0;
  matrica(2, 3) = 21.0;
  matrica(3, 0) = 22.0;
  matrica(3, 1) = 7.0;
  matrica(3, 2) = 1.0;
  matrica(3, 3) = 3.0;
  result(0, 0) = 0.0;
  result(0, 1) = 1.0;
  result(0, 2) = 0.0;
  result(0, 3) = 0.0;
  result(1, 0) = (-5.0 / 23.0);
  result(1, 1) = (-121.0 / 23.0);
  result(1, 2) = (2.0 / 23.0);
  result(1, 3) = (1.0 / 23.0);
  result(2, 0) = (-18.0 / 23.0);
  result(2, 1) = (-379.0 / 46.0);
  result(2, 2) = (19.0 / 46.0);
  result(2, 3) = (-25.0 / 46.0);
  result(3, 0) = (53.0 / 69.0);
  result(3, 1) = (1061.0 / 138.0);
  result(3, 2) = (-47.0 / 138.0);
  result(3, 3) = (19.0 / 46.0);
  S21Matrix check(4, 4);
  check = matrica.InverseMatrix();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_DOUBLE_EQ(check(i, j), result(i, j));
    }
  }
}

TEST(InverseMatrix, TestCase5) {
  S21Matrix matrica(2, 2);
  S21Matrix result(2, 2);
  matrica(0, 0) = 0.333;
  matrica(0, 1) = -15.2;
  matrica(1, 0) = 12.52521;
  matrica(1, 1) = 52.22;
  result(0, 0) = (13055000.0 / 51943113.0);
  result(0, 1) = (3800000.0 / 51943113.0);
  result(1, 0) = (-695845.0 / 11542914.0);
  result(1, 1) = (9250.0 / 5771457.0);
  S21Matrix check(2, 2);
  check = matrica.InverseMatrix();
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(check(i, j), result(i, j));
    }
  }
}

TEST(InverseMatrix, TestCase6) {
  S21Matrix matrica(1, 1);
  S21Matrix check(1, 1);
  matrica(0, 0) = 55;
  check = matrica.InverseMatrix();
  ASSERT_DOUBLE_EQ(check(0, 0), (1.0 / 55.0));
}

TEST(CheckOperations, TestCase1) {
  S21Matrix check(1, 1);
  S21Matrix matrica(1, 1);
  S21Matrix matrica2(1, 1);
  matrica(0, 0) = 1;
  matrica2(0, 0) = 1;
  check = matrica + matrica2;
  ASSERT_DOUBLE_EQ(check(0, 0), 2);
}

TEST(CheckOperations, TestCase2) {
  S21Matrix check(2, 2);
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 10;
  matrica(0, 1) = 11;
  matrica(1, 0) = 12;
  matrica(1, 1) = 13;
  matrica2(0, 0) = 11.1;
  matrica2(0, 1) = 15.1;
  matrica2(1, 0) = 16.1;
  matrica2(1, 1) = 17.1;
  check = matrica + matrica2;
  ASSERT_DOUBLE_EQ(check(0, 0), 21.1);
  ASSERT_DOUBLE_EQ(check(0, 1), 26.1);
  ASSERT_DOUBLE_EQ(check(1, 0), 28.1);
  ASSERT_DOUBLE_EQ(check(1, 1), 30.1);
}

TEST(CheckOperations, TestCase3) {
  S21Matrix check(1, 1);
  S21Matrix matrica(1, 1);
  S21Matrix matrica2(1, 1);
  matrica(0, 0) = 1;
  matrica2(0, 0) = 1;
  check = matrica - matrica2;
  ASSERT_DOUBLE_EQ(check(0, 0), 0);
}

TEST(CheckOperations, TestCase4) {
  S21Matrix check(2, 2);
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 10;
  matrica(0, 1) = 11;
  matrica(1, 0) = 12;
  matrica(1, 1) = 13;
  matrica2(0, 0) = 11.1;
  matrica2(0, 1) = 15.2;
  matrica2(1, 0) = 16.3;
  matrica2(1, 1) = 17.4;
  check = matrica - matrica2;
  ASSERT_DOUBLE_EQ(check(0, 0), -1.1);
  ASSERT_DOUBLE_EQ(check(0, 1), -4.2);
  ASSERT_DOUBLE_EQ(check(1, 0), -4.3);
  ASSERT_DOUBLE_EQ(check(1, 1), -4.4);
}

TEST(CheckOperations, TestCase5) {
  S21Matrix check(1, 1);
  S21Matrix matrica(1, 1);
  S21Matrix matrica2(1, 1);
  matrica(0, 0) = 3;
  matrica2(0, 0) = 2;
  check = matrica * matrica2;
  ASSERT_DOUBLE_EQ(check(0, 0), 6);
}

TEST(CheckOperations, TestCase6) {
  S21Matrix check(2, 2);
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 10;
  matrica(0, 1) = 11;
  matrica(1, 0) = 12;
  matrica(1, 1) = 13;
  matrica2(0, 0) = 11.1;
  matrica2(0, 1) = 15.2;
  matrica2(1, 0) = 16.3;
  matrica2(1, 1) = 17.4;
  check = matrica * matrica2;
  ASSERT_DOUBLE_EQ(check(0, 0), 290.3);
  ASSERT_DOUBLE_EQ(check(0, 1), 343.4);
  ASSERT_DOUBLE_EQ(check(1, 0), 345.1);
  ASSERT_DOUBLE_EQ(check(1, 1), 408.6);
}

TEST(CheckOperations, TestCase7) {
  S21Matrix check(1, 1);
  S21Matrix matrica(1, 1);
  matrica(0, 0) = 3;
  check = matrica * 120;
  ASSERT_DOUBLE_EQ(check(0, 0), 360);
}

TEST(CheckOperations, TestCase8) {
  S21Matrix check(2, 2);
  S21Matrix matrica(2, 2);
  matrica(0, 0) = 10;
  matrica(0, 1) = 11;
  matrica(1, 0) = 12;
  matrica(1, 1) = 13;
  check = 5 * matrica;
  ASSERT_DOUBLE_EQ(check(0, 0), 50);
  ASSERT_DOUBLE_EQ(check(0, 1), 55);
  ASSERT_DOUBLE_EQ(check(1, 0), 60);
  ASSERT_DOUBLE_EQ(check(1, 1), 65);
}

TEST(CheckOperations, TestCase9) {
  S21Matrix matrica(1, 1);
  S21Matrix matrica2(1, 1);
  matrica(0, 0) = 3;
  bool check = matrica2 == matrica;
  ASSERT_EQ(check, 0);
}

TEST(CheckOperations, TestCase10) {
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 11.1;
  matrica(0, 1) = 15.2;
  matrica(1, 0) = 16.3;
  matrica(1, 1) = 17.4;
  matrica2(0, 0) = 11.1;
  matrica2(0, 1) = 15.2;
  matrica2(1, 0) = 16.3;
  matrica2(1, 1) = 17.4;
  bool check = matrica == matrica2;
  ASSERT_EQ(check, 1);
}

TEST(CheckOperations, TestCase11) {
  S21Matrix matrica(1, 1);
  matrica(0, 0) = 3;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 3);
}

TEST(CheckOperations, TestCase12) {
  S21Matrix matrica(2, 2);
  matrica(0, 0) = 10;
  matrica(0, 1) = 11;
  matrica(1, 0) = 12;
  matrica(1, 1) = 13;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 10);
  ASSERT_DOUBLE_EQ(matrica(0, 1), 11);
  ASSERT_DOUBLE_EQ(matrica(1, 0), 12);
  ASSERT_DOUBLE_EQ(matrica(1, 1), 13);
}

TEST(CheckOperations, TestCase13) {
  S21Matrix matrica(1, 1);
  S21Matrix matrica2(1, 1);
  matrica(0, 0) = 3;
  matrica2(0, 0) = 7;
  matrica += matrica2;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 10);
}

TEST(CheckOperations, TestCase14) {
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 10;
  matrica(0, 1) = 11;
  matrica(1, 0) = 12;
  matrica(1, 1) = 13;
  matrica2(0, 0) = 11.1;
  matrica2(0, 1) = 15.2;
  matrica2(1, 0) = 16.3;
  matrica2(1, 1) = 17.4;
  matrica += matrica2;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 21.1);
  ASSERT_DOUBLE_EQ(matrica(0, 1), 26.2);
  ASSERT_DOUBLE_EQ(matrica(1, 0), 28.3);
  ASSERT_DOUBLE_EQ(matrica(1, 1), 30.4);
}

TEST(CheckOperations, TestCase15) {
  S21Matrix matrica(1, 1);
  S21Matrix matrica2(1, 1);
  matrica(0, 0) = 10;
  matrica2(0, 0) = 7;
  matrica -= matrica2;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 3);
}

TEST(CheckOperations, TestCase16) {
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 51.1;
  matrica(0, 1) = 32.2;
  matrica(1, 0) = 26.3;
  matrica(1, 1) = 20.4;
  matrica2(0, 0) = 11.1;
  matrica2(0, 1) = 15.2;
  matrica2(1, 0) = 16.3;
  matrica2(1, 1) = 17.4;
  matrica -= matrica2;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 40);
  ASSERT_DOUBLE_EQ(matrica(0, 1), 17);
  ASSERT_DOUBLE_EQ(matrica(1, 0), 10);
  ASSERT_DOUBLE_EQ(matrica(1, 1), 3);
}

TEST(CheckOperations, TestCase17) {
  S21Matrix matrica(1, 1);
  S21Matrix matrica2(1, 1);
  matrica(0, 0) = 10;
  matrica2(0, 0) = 7;
  matrica *= matrica2;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 70);
}

TEST(CheckOperations, TestCase18) {
  S21Matrix matrica(2, 2);
  S21Matrix matrica2(2, 2);
  matrica(0, 0) = 51.1;
  matrica(0, 1) = 32.2;
  matrica(1, 0) = 26.3;
  matrica(1, 1) = 20.4;
  matrica2(0, 0) = 11.1;
  matrica2(0, 1) = 15.2;
  matrica2(1, 0) = 16.3;
  matrica2(1, 1) = 17.4;
  matrica *= matrica2;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 1092.07);
  ASSERT_DOUBLE_EQ(matrica(0, 1), 1337);
  ASSERT_DOUBLE_EQ(matrica(1, 0), 624.45);
  ASSERT_DOUBLE_EQ(matrica(1, 1), 754.72);
}

TEST(CheckOperations, TestCase19) {
  S21Matrix matrica(1, 1);
  matrica(0, 0) = 10;
  matrica *= 23;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 230);
}

TEST(CheckOperations, TestCase20) {
  S21Matrix matrica(2, 2);
  matrica(0, 0) = 51.1;
  matrica(0, 1) = 32.2;
  matrica(1, 0) = 26.3;
  matrica(1, 1) = 20.4;
  matrica = matrica * 10.0;
  ASSERT_DOUBLE_EQ(matrica(0, 0), 511);
  ASSERT_DOUBLE_EQ(matrica(0, 1), 322);
  ASSERT_DOUBLE_EQ(matrica(1, 0), 263);
  ASSERT_DOUBLE_EQ(matrica(1, 1), 204);
}

TEST(CheckOperations, TestCase21) {
  S21Matrix matrica(1, 1);
  matrica.SetCols(10);
  ASSERT_DOUBLE_EQ(matrica.GetCols(), 10);
}

TEST(CheckOperations, TestCase22) {
  S21Matrix matrica(10, 10);
  matrica.SetCols(5);
  ASSERT_DOUBLE_EQ(matrica.GetCols(), 5);
}

TEST(CheckOperations, TestCase23) {
  S21Matrix matrica(1, 1);
  matrica.SetRows(10);
  ASSERT_DOUBLE_EQ(matrica.GetRows(), 10);
}

TEST(CheckOperations, TestCase24) {
  S21Matrix matrica(10, 10);
  matrica.SetRows(5);
  ASSERT_DOUBLE_EQ(matrica.GetRows(), 5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
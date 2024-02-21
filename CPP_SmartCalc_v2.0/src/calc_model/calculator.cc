#include "calculator.h"

double s21::Calculator::PerformCalculation(
    const std::stack<s21::Data> &converted_input, double x) {
  std::stack<s21::Data> input = converted_input;
  array result{};
  int index = -1;
  while (!input.empty()) {
    s21::Data elem = input.top();
    if (elem.GetType() == kX || elem.GetType() == kNumber) {
      index++;
      result[index] = elem.GetType() != kX ? elem.GetValue() : x;
    } else if (!UnaryFuncArithmetic(elem, result, index)) {
      BinaryFuncArithmetic(elem, result, index);
    }
    input.pop();
  }
  if (!std::isfinite(result[index])) {
    throw s21::CalculationError("Error: Calculation error");
  }
  return result[index];
}

bool s21::Calculator::UnaryFuncArithmetic(s21::Data &elem, array &result,
                                          int &index) {
  bool check = true;
  if (elem.GetType() == kUnaryMinus) {
    result[index] *= -1;
  } else if (elem.GetType() == kUnaryPlus) {
    result[index] *= 1;
  } else if (elem.GetType() == kLn) {
    if (result[index] > 0) {
      result[index] = log(result[index]);
    } else {
      throw s21::CalculationError("Error: Calculation error");
    }
  } else if (elem.GetType() == kLog) {
    if (result[index] > 0) {
      result[index] = log10(result[index]);
    } else {
      throw s21::CalculationError("Error: Calculation error");
    }
  } else if (elem.GetType() == kSqrt) {
    if (result[index] >= 0) {
      result[index] = sqrt(result[index]);
    } else {
      throw s21::CalculationError("Error: Calculation error");
    }
  } else if (elem.GetType() == kSin) {
    result[index] = sin(result[index]);
  } else if (elem.GetType() == kCos) {
    result[index] = cos(result[index]);
  } else if (elem.GetType() == kTan) {
    result[index] = tan(result[index]);
  } else if (elem.GetType() == kAsin) {
    if (fabs(result[index]) <= 1) {
      result[index] = asin(result[index]);
    } else {
      throw s21::CalculationError("Error: Calculation error");
    }
  } else if (elem.GetType() == kAcos) {
    if (fabs(result[index] <= 1)) {
      result[index] = acos(result[index]);
    } else {
      throw s21::CalculationError("Error: Calculation error");
    }
  } else if (elem.GetType() == kAtan) {
    result[index] = atan(result[index]);
  } else {
    check = false;
  }
  return check;
}

void s21::Calculator::BinaryFuncArithmetic(s21::Data &elem, array &result,
                                           int &index) {
  if (elem.GetType() == kMod) {
    if (result[index] != 0) {
      result[index - 1] = fmod(result[index - 1], result[index]);
    } else {
      throw s21::CalculationError("Error: Div by zero");
    }
  } else if (elem.GetType() == kBinaryMinus) {
    result[index - 1] -= result[index];
  } else if (elem.GetType() == kPow) {
    result[index - 1] = pow(result[index - 1], result[index]);
  } else if (elem.GetType() == kBinaryPlus) {
    result[index - 1] += result[index];
  } else if (elem.GetType() == kMult) {
    result[index - 1] *= result[index];
  } else if (elem.GetType() == kDiv) {
    if (result[index] != 0) {
      result[index - 1] /= result[index];
    } else {
      throw s21::CalculationError("Error: Div by zero");
    }
  }
  index--;
}
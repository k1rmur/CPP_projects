#include "parser.h"

std::stack<s21::Data> s21::Parser::ParseString(const std::string& str) {
  std::stack<s21::Data> result;
  for (size_t i = 0; i < str.size(); i++) {
    if (IsDigit(str[i])) {
      result.push(ConvertNumberToString(str, i));
    } else if (str[i] == 'x') {
      if (i == 0 || (i > 0 && (!IsDigit(str[i - 1]) && str[i - 1] != ')' &&
                               str[i - 1] != 'x'))) {
        s21::Data tmp(0, 0, kX);
        result.push(tmp);
      } else {
        throw s21::InputError("Error: Wrong input");
      }
    } else {
      s21::Data tmp = CheckAlgebraicSigns(str, i);
      if (tmp.GetType() == kUnknown) {
        if (str[i] == '(' || str[i] == ')') {
          result.push(CheckMatchingBracket(str, i));
        } else {
          tmp = CheckMathLexeme(str, i);
          if (tmp.GetType() == kUnknown) {
            tmp = CheckTrigonometricLexeme(str, i);
            if (tmp.GetType() == kUnknown) {
              if (str[i] != '\0' && str[i] != 'd') {
                throw s21::InputError("Error: Wrong input");
              }
            }
          }
          result.push(tmp);
        }
      } else {
        result.push(tmp);
      }
    }
  }
  return result;
}

s21::Data s21::Parser::CheckAlgebraicSigns(const std::string& str,
                                           size_t index) {
  s21::Data res;
  if (str[index] == '+') {
    if ((index == 0 && index != size(str) - 1) ||
        (index != 0 && str[index - 1] == '(')) {
      res.SetPriority(1);
      res.SetType(kUnaryPlus);
    } else if (index != 0 && index != size(str) - 1 && str[index + 1] != ')' &&
               str[index - 1] != '-' && str[index - 1] != '+') {
      res.SetPriority(1);
      res.SetType(kBinaryPlus);
    } else {
      throw s21::InputError("Error: Wrong input");
    }
  } else if (str[index] == '-') {
    if ((index == 0 && index != size(str) - 1) ||
        (index != 0 && str[index - 1] == '(')) {
      res.SetPriority(1);
      res.SetType(kUnaryMinus);
    } else if (index != 0 && index != size(str) - 1 && str[index + 1] != ')' &&
               str[index - 1] != '+' && str[index - 1] != '-') {
      res.SetPriority(1);
      res.SetType(kBinaryMinus);
    } else {
      throw s21::InputError("Error: Wrong input");
    }
  } else if (str[index] == '^') {
    if (index != 0 && index != size(str) - 1 &&
        (str[index - 1] == ')' || IsDigit(str[index - 1]) ||
         str[index - 1] == 'x')) {
      res.SetPriority(3);
      res.SetType(kPow);
    } else {
      throw s21::InputError("Error: Wrong input");
    }
  } else if (str[index] == '*' || str[index] == '/') {
    if (index != 0 && index != size(str) - 1 &&
        (str[index - 1] == ')' || IsDigit(str[index - 1]) ||
         str[index - 1] == 'x')) {
      res.SetPriority(2);
      str[index] == '*' ? res.SetType(kMult) : res.SetType(kDiv);
    } else {
      throw s21::InputError("Error: Wrong input");
    }
  }
  return res;
}

s21::Data s21::Parser::CheckMathLexeme(const std::string& str, size_t& index) {
  s21::Data res;
  if (str[index] == 's' && index != size(str) - 5) {
    if (str[index + 1] == 'q' && str[index + 2] == 'r' &&
        str[index + 3] == 't' && str[index + 4] == '(') {
      res.SetPriority(4);
      res.SetType(kSqrt);
      index += 3;
    }
  }
  if (str[index] == 'l') {
    if (index != size(str) - 2 && str[index + 1] == 'n' &&
        str[index + 2] == '(') {
      res.SetPriority(4);
      res.SetType(kLn);
      index++;
    } else if (index != size(str) - 3 && str[index + 1] == 'o' &&
               str[index + 2] == 'g' && str[index + 3] == '(') {
      res.SetPriority(4);
      res.SetType(kLog);
      index += 2;
    } else {
      throw s21::InputError("Error: Wrong input");
    }
  }
  if (str[index] == 'm' && index != size(str) - 3) {
    if (index != 0 && str[index + 1] == 'o' && str[index + 2] == 'd' &&
        (str[index + 3] == 'x' || IsDigit(str[index + 3]))) {
      res.SetPriority(3);
      res.SetType(kMod);
      index += 2;
    } else {
      throw s21::InputError("Error: Wrong input");
    }
  }
  return res;
}

s21::Data s21::Parser::CheckTrigonometricLexeme(const std::string& str,
                                                size_t& index) {
  s21::Data res;
  if (str[index] == 'a' && index != size(str) - 5) {
    res.SetPriority(4);
    if (str[index + 1] == 'c' && str[index + 2] == 'o' &&
        str[index + 3] == 's' && str[index + 4] == '(') {
      res.SetType(kAcos);
      index += 3;
    } else if (str[index + 1] == 's' && str[index + 2] == 'i' &&
               str[index + 3] == 'n' && str[index + 4] == '(') {
      res.SetType(kAsin);
      index += 3;
    } else if (str[index + 1] == 't' && str[index + 2] == 'a' &&
               str[index + 3] == 'n' && str[index + 4] == '(') {
      res.SetType(kAtan);
      index += 3;
    }
  } else if (str[index] == 'c' && index != size(str) - 4) {
    res.SetPriority(4);
    if (str[index + 1] == 'o' && str[index + 2] == 's' &&
        str[index + 3] == '(') {
      res.SetType(kCos);
      index += 2;
    }
  } else if (str[index] == 's' && index != size(str) - 4) {
    res.SetPriority(4);
    if (str[index + 1] == 'i' && str[index + 2] == 'n' &&
        str[index + 3] == '(') {
      res.SetType(kSin);
      index += 2;
    }
  } else if (str[index] == 't' && index != size(str) - 4) {
    res.SetPriority(4);
    if (str[index + 1] == 'a' && str[index + 2] == 'n' &&
        str[index + 3] == '(') {
      res.SetType(kTan);
      index += 2;
    }
  }
  return res;
}

s21::Data s21::Parser::CheckMatchingBracket(const std::string& str,
                                            size_t index) {
  int brackets_count = 0;
  s21::OperationType type = kLeftBracket;
  if (str[index] == ')') {
    type = kRightBracket;
  }
  s21::Data result(0, -1, type);
  if (str[index] == '(') {
    if (index >= 1 && (str[index - 1] == 'x' || IsDigit(str[index - 1]))) {
      throw s21::InputError("Error: Wrong input");
    }
    index++;
    for (; str[index] != '\0' && brackets_count != 1; index++) {
      if (str[index] == '(') {
        brackets_count--;
      } else if (str[index] == ')') {
        brackets_count++;
        if (str[index - 1] == '(') {
          throw s21::InputError("Error: Wrong input");
        }
      }
    }
  } else if (str[index] == ')') {
    if (index == 0) {
      throw s21::InputError("Error: Wrong input");
    }
    index--;
    for (; brackets_count != 1; index--) {
      if (str[index] == ')') {
        brackets_count--;
      } else if (str[index] == '(') {
        brackets_count++;
        if (str[index + 1] == ')') {
          throw s21::InputError("Error: Wrong input");
        }
      }
      if (index == 0) {
        break;
      }
    }
  }
  if (brackets_count != 1) {
    throw s21::InputError("Error: Wrong input");
  }
  return result;
}

s21::Data s21::Parser::ConvertNumberToString(const std::string& str,
                                             size_t& index) {
  if (index > 0 && (str[index - 1] == 'x' || str[index - 1] == ')')) {
    throw s21::InputError("Error: Wrong input");
  }
  std::string num = CheckNumber(str, index, 1);
  double exp = 0;
  if (str[index] == 'e') {
    index++;
    int sign = 1;
    if (str[index] == '-') {
      sign = -1;
    } else if (str[index] != '+') {
      throw s21::InputError("Error: Wrong input");
    }
    index++;
    if (!IsDigit(str[index])) {
      throw s21::InputError("Error: Wrong input");
    }
    exp = ConvertStringToDouble(CheckNumber(str, index, 0)) * sign;
  }
  index--;
  double res = ConvertStringToDouble(num);
  res = res * pow(10, exp);
  s21::Data tmp(res, 0, kNumber);
  return tmp;
}

double s21::Parser::ConvertStringToDouble(const std::string& str) {
  bool isDot = false;
  double count = 0;
  double res = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == '.') {
      isDot = true;
      count = 0;
    } else {
      res = res * 10 + (str[i] - '0');
      count++;
    }
  }
  if (isDot) {
    res /= pow(10, count);
  }
  return res;
}

std::string s21::Parser::CheckNumber(const std::string& str, size_t& index,
                                     size_t max_dot_count) {
  std::string num = "";
  size_t dot_count = 0;
  for (;; index++) {
    if ((IsDigit(str[index]) || str[index] == '.') && str[index] != '\0') {
      num.push_back(str[index]);
      if (str[index] == '.') {
        dot_count++;
      }
    } else {
      if (!num.empty() &&
          (num[num.size() - 1] == '.' || dot_count > max_dot_count ||
           (num.size() > 1 && num[0] == '0' && num[1] != '.'))) {
        throw s21::InputError("Error: Wrong input");
      } else {
        break;
      }
    }
  }
  return num;
}

bool s21::Parser::IsDigit(char c) { return c >= 48 && c <= 57; }
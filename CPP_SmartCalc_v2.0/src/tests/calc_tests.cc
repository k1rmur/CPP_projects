#include <gtest/gtest.h>

#include "../calc_model/calc_model.h"
#include "../calc_controller/calc_controller.h"


TEST(TestModelCalculation, Test_1) {
  s21::CalcModel m;
  std::string input = "+(-sqrt(0.16+2)/2)";
  m.SetInputString(input);
  ASSERT_EQ(m.GetAnswer(),-sqrt(0.16+2)/2);
}

TEST(TestModelCalculation, Test_2) {
  s21::CalcModel m;
  std::string input = "+ln(5.23)+sqrt(9-0.02)*atan(0.51)";
  double x = 3.15;
  double ans = log(5.23)+sqrt(9-0.02)*atan(0.51);
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_3) {
  s21::CalcModel m;
  std::string input = "+xmod2+244";
  int x = 3;
  double ans = fmod(x,2)+244;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_4) {
  s21::CalcModel m;
  std::string input = "tan(asin(acos(0.98)))";
  double ans = tan(asin(acos(0.98)));
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_5) {
  s21::CalcModel m;
  std::string input = "ln(5.23+cos(0.33-asin(sqrt(0.44))))";
  double ans = log(5.23+cos(0.33-asin(sqrt(0.44))));
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_6) {
  s21::CalcModel m;
  std::string input = "-0e+2";
  double ans = -0e+2;
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_7) {
  s21::CalcModel m;
  std::string input = "333e-4+44*4";
  double ans = 333e-4+44*4;
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_8) {
  s21::CalcModel m;
  std::string input = "(xmod44)/3.33+acos((cos(-0.33)-0.001*sqrt(11e-3)))";
  int x = 3;
  double ans = (fmod(x,44))/3.33+acos((cos(-0.33)-0.001*sqrt(11e-3)));
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_9) {
  s21::CalcModel m;
  std::string input = "cos(1)^11-asin(0.99)-atan(2)";
  int x = 3;
  double ans = pow(cos(1),11)-asin(0.99)-atan(2);
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_10) {
  s21::CalcModel m;
  std::string input = "x^(2^(2^2))";
  int x = 2;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),65536.0);
}

TEST(TestModelCalculation, Test_11) {
  s21::CalcModel m;
  std::string input = "1.5^1.5^1.5^1.5";
  m.SetInputString(input);
  ASSERT_NEAR(m.GetAnswer(),3.929234958, 1e-7);
}

TEST(TestModelCalculation, Test_12) {
  s21::CalcModel m;
  std::string input = "xmod2+244";
  int x = 3;
  double ans = fmod(x,2)+244;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_DOUBLE_EQ(m.GetAnswer(),ans);
}

TEST(TestModelCalculation, Test_13) {
  s21::CalcModel m;
  std::string input = "5.11*x-sqrt(9-0.02)*atan(0.511)+x/2";
  double x = 1.45;
  double ans = 5.11*x-sqrt(9-0.02)*atan(0.511)+x/2;
  char buff_check[111] = "";
  std::sprintf(buff_check, "%.7f", ans);
  std::string check = buff_check;
  m.SetX(x);
  m.SetInputString(input);

  ASSERT_EQ(m.GetStringAnswer(),check);
}

TEST(TestModelCalculation, Test_14) {
  s21::CalcModel m;
  std::string input = "6.611-sqrt(cos(0.99-sqrt(1.111+2e-3)))*acos(0.511)^2";
  double ans = 6.611-sqrt(cos(0.99-sqrt(1.111+2e-3)))*pow(acos(0.511),2);
  char buff_check[111] = "";
  std::sprintf(buff_check, "%.7f", ans);
  std::string check = buff_check;
  m.SetInputString(input);

  ASSERT_EQ(m.GetStringAnswer(),check);
}

TEST(TestModelCalculation, Test_15) {
  s21::CalcModel m;
  std::string input = "1/sqrt(2.53^cos(sqrt(sin(sqrt(tan(sqrt(1.123)))))))";
  double ans = 1/sqrt(pow(2.53,cos(sqrt(sin(sqrt(tan(sqrt(1.123))))))));
  char buff_check[111] = "";
  std::sprintf(buff_check, "%.7f", ans);
  std::string check = buff_check;
  m.SetInputString(input);

  ASSERT_EQ(m.GetStringAnswer(),check);
}

TEST(TestModelCalculation, Test_16) {
  s21::CalcModel m;
  std::string input = "log(4.31+x/2)";
  double x = 1.45;
  double ans = log10(4.31+x/2);
  char buff_check[111] = "";
  std::sprintf(buff_check, "%.7f", ans);
  std::string check = buff_check;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),check);
}

TEST(TestModelCalculation, Test_17) {
  s21::CalcModel m;
  std::string input = "4^2+x";
  double x = 1.45;
  double ans = pow(4,2)+x;
  char buff_check[111] = "";
  std::sprintf(buff_check, "%.7f", ans);
  std::string check = buff_check;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),check);
}


TEST(TestModelInputError, Test_1) {
  s21::CalcModel m;
  std::string input = "1e+x";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_2) {
  s21::CalcModel m;
  std::string input = "(x)/(x))";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_3) {
  s21::CalcModel m;
  std::string input = "1e*132";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_4) {
  s21::CalcModel m;
  std::string input = "1123e+5.1";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_5) {
  s21::CalcModel m;
  std::string input = "001235431";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_6) {
  s21::CalcModel m;
  std::string input = "1e+x(acos(2*(2x)))";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_7) {
  s21::CalcModel m;
  std::string input = "acos(pow(1,x))/54";
  m.SetInputString(input);
  m.SetX(333);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_8) {
  s21::CalcModel m;
  std::string input = "5mob2";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_9) {
  s21::CalcModel m;
  std::string input = "(acos(atg(x+1.33)+asin(44))^52)/21";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_10) {
  s21::CalcModel m;
  std::string input = "lg(15*x/22)";
  m.SetX(0);
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_11) {
  s21::CalcModel m;
  std::string input = "log(+11-44-11+1e-(x))";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_12) {
  s21::CalcModel m;
  std::string input = "1x+";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_13) {
  s21::CalcModel m;
  std::string input = "++sqrt(44,1)";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_14) {
  s21::CalcModel m;
  std::string input = "^acos(x+1.33)";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_15) {
  s21::CalcModel m;
  std::string input = "atan(x+)";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_16) {
  s21::CalcModel m;
  std::string input = "/ln(+tan(123.11)-acos(0.991))";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_17) {
  s21::CalcModel m;
  std::string input = "11e+5+x()))";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_18) {
  s21::CalcModel m;
  std::string input = "()())";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_19) {
  s21::CalcModel m;
  std::string input = ")13+123/123.1";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_20) {
  s21::CalcModel m;
  std::string input = "1111(55+31)";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_21) {
  s21::CalcModel m;
  std::string input = "123.55+x1";
  m.SetInputString(input);
  m.SetX(0);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelInputError, Test_22) {
  s21::CalcModel m;
  std::string input = ")(()x";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(), "Error: Wrong input");
}

TEST(TestModelCalculationError, Test_1) {
  s21::CalcModel m;
  std::string input = "acos(10+x)";
  int x = 3;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Calculation error");
}

TEST(TestModelCalculationError, Test_2) {
  s21::CalcModel m;
  std::string input = "asin(x)";
  double x = 6.542;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Calculation error");
}

TEST(TestModelCalculationError, Test_3) {
  s21::CalcModel m;
  std::string input = "sqrt(2.11-x)";
  double x = 126.2;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Calculation error");
}

TEST(TestModelCalculationError, Test_4) {
  s21::CalcModel m;
  std::string input = "log(x-87.1)";
  double x = 87.1;
  m.SetX(x);
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Calculation error");
}

TEST(TestModelCalculationError, Test_5) {
  s21::CalcModel m;
  std::string input = "1mod0";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Div by zero");
}

TEST(TestModelCalculationError, Test_6) {
  s21::CalcModel m;
  std::string input = "123/0+4331";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Div by zero");
}

TEST(TestModelCalculationError, Test_7) {
  s21::CalcModel m;
  std::string input = "ln(-3)";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Calculation error");
}

TEST(TestModelCalculationError, Test_8) {
  s21::CalcModel m;
  std::string input = "333^1000";
  m.SetInputString(input);
  ASSERT_EQ(m.GetStringAnswer(),"Error: Calculation error");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
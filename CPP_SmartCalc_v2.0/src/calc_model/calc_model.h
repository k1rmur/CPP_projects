#ifndef CALC_MODEL_H_

#define CALC_MODEL_H_

#include <vector>

#include "calculator.h"
#include "converter.h"
#include "locale.h"
#include "parser.h"
namespace s21 {
class CalcModel {
 public:
  CalcModel() = default;
  ~CalcModel() = default;

  void SetInputString(const std::string& str);
  void SetX(double x);
  double GetAnswer();
  std::string GetStringAnswer();
  void SetPlot(double origin,double end, const std::string& str);
  std::vector<double>& GetXPlot();
  std::vector<double>& GetYPlot();
  bool GetCheckPlot();

 private:
  void ConvertStringToPolish();
  void Calculate();

  Parser parser_;
  Converter converter_;
  Calculator calculator_;
  double x_ = 0;
  std::vector<double> plotx_;
  std::vector<double> ploty_;
  std::stack<s21::Data> parse_result_;
  std::stack<s21::Data> converter_result_;
  bool is_calculated_ = false;
  bool is_ploted_ = true;
  double answer_ = 0;
  std::string string_asnwer_ = "";

};
}  // namespace s21
#endif

#include "calc_model.h"

void s21::CalcModel::SetInputString(const std::string& str) {
  try {
    parse_result_ = parser_.ParseString(str);
    ConvertStringToPolish();
  } catch (std::exception& e) {
    string_asnwer_ = e.what();
    is_calculated_ = false;
  }
}

void s21::CalcModel::ConvertStringToPolish() {
  converter_result_ = converter_.ConvertToPolish(parse_result_);
  Calculate();
}

void s21::CalcModel::SetX(double x) { x_ = x; }

void s21::CalcModel::Calculate() {
  try {
    answer_ = calculator_.PerformCalculation(converter_result_, x_);
    setlocale(LC_NUMERIC, "C");
    char buffer[111] = "";
    std::sprintf(buffer, "%.7f", answer_);
    string_asnwer_ = buffer;
    is_calculated_ = true;
  } catch (std::exception& e) {
    string_asnwer_ = e.what();
    is_calculated_ = false;
  }
}

std::string s21::CalcModel::GetStringAnswer() { return string_asnwer_; }

double s21::CalcModel::GetAnswer() { return answer_; }

void s21::CalcModel::SetPlot(double origin, double end,
                             const std::string& str) {
  double step = 0.001;
  plotx_.clear();
  ploty_.clear();
  is_ploted_ = true;
  for (double X = origin; X <= end;
       X += step, X = round(X * 1000000) / 1000000) {
    SetX(X);
    SetInputString(str);
    if (is_calculated_ == false) {
      plotx_.clear();
      ploty_.clear();
      is_ploted_ = false;
      break;
    }
    plotx_.push_back(X);
    ploty_.push_back(GetAnswer());
  }
}

std::vector<double>& s21::CalcModel::GetXPlot() { return plotx_; }

std::vector<double>& s21::CalcModel::GetYPlot() { return ploty_; }

bool s21::CalcModel::GetCheckPlot() { return is_ploted_; }
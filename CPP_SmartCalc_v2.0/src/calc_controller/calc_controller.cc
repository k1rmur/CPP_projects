#include "calc_controller.h"

namespace s21 {

void s21::CalcController::SetInputString(const std::string& str) {
  model_->SetInputString(str);
}

void s21::CalcController::SetXValue(double x) { model_->SetX(x); }

std::string s21::CalcController::GetStringAnswer() {
  return model_->GetStringAnswer();
}

void s21::CalcController::SetPlot(double origin, double end,
                                  const std::string& str) {
  model_->SetPlot(origin, end, str);
}

std::vector<double>& s21::CalcController::GetXPlot() {
  return model_->GetXPlot();
}

std::vector<double>& s21::CalcController::GetYPlot() {
  return model_->GetYPlot();
}

bool s21::CalcController::GetCheckPlot() { return model_->GetCheckPlot(); }

}  // namespace s21
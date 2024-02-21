#ifndef CALC_CONTROLLER_H_

#define CALC_CONTROLLER_H_

#include "../calc_model/calc_model.h"

namespace s21 {
class CalcController {
 public:
  CalcController() = delete;
  CalcController(CalcModel* model) : model_(model) {}

  void SetInputString(const std::string& str);
  void SetXValue(double x);
  std::string GetStringAnswer();
  void SetPlot(double origin,double end, const std::string& str);
  std::vector<double>& GetXPlot();
  std::vector<double>& GetYPlot();
  bool GetCheckPlot();

 private:
  CalcModel* model_;
};
}  // namespace s21

#endif

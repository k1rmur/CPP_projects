#include "controller.h"

namespace s21 {

const MazeData& Controller::GenerateMaze(size_t rows, size_t columns) {
  model_->SetMazeRows(rows);
  model_->SetMazeColumns(columns);
  model_->GenerateMaze();
  return model_->GetMazeData();
}

const MazeData& Controller::ImportDataFromFile(const std::string& path) {
  model_->ReadMazeDataFromFile(path);
  return model_->GetMazeData();
}

void Controller::ExportDataToFile(const std::string& path) {
  model_->SaveMazeDataToFile(path);
}

const std::vector<Point>& Controller::FindPath(Point start, Point end) {
  model_->SetPathPoints(start, end);
  model_->SolveMaze();
  return model_->GetPath();
}

const std::string& Controller::GetStatus() { return model_->GetStatus(); }

}  // namespace s21

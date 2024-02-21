#ifndef A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_

#define A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  Controller() = delete;

  Controller(Model* m) : model_(m) {}

  const MazeData& GenerateMaze(size_t rows, size_t columns);

  const MazeData& ImportDataFromFile(const std::string& path);

  void ExportDataToFile(const std::string& path);

  const std::vector<Point>& FindPath(Point start, Point end);

  const std::string& GetStatus();

 private:
  Model* model_;
};
}  // namespace s21

#endif

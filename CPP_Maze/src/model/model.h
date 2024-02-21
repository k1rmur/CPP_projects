#ifndef A1_MAZE_SRC_MODEL_MODEL_H_
#define A1_MAZE_SRC_MODEL_MODEL_H_

#include "file_reader.h"
#include "file_writer.h"
#include "maze_generator.h"
#include "maze_solver.h"

namespace s21 {
class Model {
 public:
  Model();

  void GenerateMaze();

  void ReadMazeDataFromFile(const std::string& path);
  void SaveMazeDataToFile(const std::string& path);

  void SetMazeRows(size_t rows) noexcept;
  void SetMazeColumns(size_t columns) noexcept;

  void SetPathPoints(Point start, Point end);

  const MazeData& GetMazeData();

  const std::vector<Point>& GetPath();

  const std::string& GetStatus();

  void SolveMaze();

  void ValidateMaze();

 private:
  MazeGenerator maze_gen_;
  MazeSolver maze_solver_;

  std::string status_;

  MazeData maze_;
  size_t maze_rows_;
  size_t maze_columns_;

  std::vector<Point> path_;
  Point start_;
  Point end_;
};
}  // namespace s21
#endif  // MAZE_MODEL_H

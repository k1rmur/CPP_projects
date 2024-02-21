#ifndef A1_MAZE_SRC_VIEW_RENDERER_H_
#define A1_MAZE_SRC_VIEW_RENDERER_H_

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <cmath>
#include <vector>

#include "../model/maze_data.h"

namespace s21 {

class Renderer : public QGraphicsScene {
 public:
  Renderer();

  bool IsPathCompleted();

  const Point& GetStartPoint();
  const Point& GetEndPoint();

  void SetMazeData(const MazeData& data);

  void SetMazePath(const std::vector<Point>& path);

  void DrawMaze();
  void DrawPath();

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;

 private:
  void Reset();
  void AddPointToMaze(const Point& point, QColor color);
  void AddPathLineToMaze(QColor color);
  void RemovePath();

  const double kWidth = 500;
  const double kHeight = 500;
  const double kWallWidth = 2;
  const double kPathWidth = 2;

  double column_size_;
  double row_size_;

  Point start_;
  Point end_;
  bool is_start_selected_;
  bool is_end_selected_;
  bool is_path_drawn_;

  const MazeData* maze_;
  const std::vector<Point>* path_;

  QColor back_color_;
  QColor wall_color_;
  QColor path_color_;
  QColor start_color_;
  QColor end_color_;
};
}  // namespace s21
#endif  // RENDERER_H

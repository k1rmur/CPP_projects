#include "renderer.h"

namespace s21 {

Renderer::Renderer() {
  maze_ = nullptr;
  Reset();
  back_color_ = Qt::black;
  wall_color_ = Qt::white;
  path_color_ = Qt::magenta;

  start_color_ = Qt::blue;
  end_color_ = Qt::green;
  setBackgroundBrush(back_color_);
}

void Renderer::SetMazeData(const MazeData& data) { maze_ = &data; }

void Renderer::SetMazePath(const std::vector<Point>& path) { path_ = &path; }

void Renderer::DrawMaze() {
  Reset();
  if (maze_->is_correct) {
    QPen pen(wall_color_, kWallWidth);
    addLine(QLine(0, 0, 0, kHeight), pen);
    addLine(QLine(0, 0, kWidth, 0), pen);
    column_size_ = kWidth / maze_->right_borders.GetColumns();
    row_size_ = kHeight / maze_->right_borders.GetRows();
    for (size_t i = 0; i < maze_->right_borders.GetRows(); i++) {
      for (size_t j = 0; j < maze_->right_borders.GetColumns(); j++) {
        if (maze_->right_borders(i, j)) {
          addLine(QLine((j + 1) * column_size_, (i * row_size_),
                        (j + 1) * column_size_, (i + 1) * row_size_),
                  pen);
        }
        if (maze_->bottom_borders(i, j)) {
          addLine(QLine(j * column_size_, (i + 1) * row_size_,
                        (j + 1) * column_size_, (i + 1) * row_size_),
                  pen);
        }
      }
    }
  }
}

void Renderer::DrawPath() {
  if (path_ != nullptr && !path_->empty()) {
    AddPathLineToMaze(path_color_);
    AddPointToMaze(start_, start_color_);
    AddPointToMaze(end_, end_color_);
    is_path_drawn_ = true;
  }
}

void Renderer::RemovePath() {
  AddPathLineToMaze(back_color_);
  AddPointToMaze(start_, back_color_);
  AddPointToMaze(end_, back_color_);
  is_path_drawn_ = false;
  is_start_selected_ = false;
  is_end_selected_ = false;
  path_ = nullptr;
}

void Renderer::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
  if (maze_ != nullptr && maze_->is_correct) {
    Qt::MouseButton button = mouseEvent->button();
    if (button == Qt::LeftButton) {
      if (is_path_drawn_) {
        RemovePath();
      }
      QPointF point = mouseEvent->lastScenePos();
      if (is_start_selected_) {
        AddPointToMaze(start_, back_color_);
      }
      start_.SetPoint(std::trunc(point.y() / row_size_),
                      std::trunc(point.x() / column_size_));
      AddPointToMaze(start_, start_color_);
      is_start_selected_ = true;
    } else if (button == Qt::RightButton) {
      QPointF point = mouseEvent->lastScenePos();
      if (is_path_drawn_) {
        RemovePath();
      }
      if (is_end_selected_) {
        AddPointToMaze(end_, back_color_);
      }
      end_.SetPoint(std::trunc(point.y() / row_size_),
                    std::trunc(point.x() / column_size_));
      AddPointToMaze(end_, end_color_);
      is_end_selected_ = true;
    }
  }
}

void Renderer::AddPointToMaze(const Point& point, QColor color) {
  addRect(column_size_ * point.col_number + column_size_ / 4,
          row_size_ * point.row_number + row_size_ / 4, column_size_ / 2,
          row_size_ / 2, QPen(color, kPathWidth), color);
}

void Renderer::AddPathLineToMaze(QColor color) {
  QPen pen(color, kPathWidth);
  for (size_t i = 0; i < path_->size() - 1; i++) {
    const Point& first = path_->at(i);
    const Point& second = path_->at(i + 1);
    addLine(column_size_ * first.col_number + column_size_ / 2,
            row_size_ * first.row_number + row_size_ / 2,
            column_size_ * second.col_number + column_size_ / 2,
            row_size_ * second.row_number + row_size_ / 2, pen);
  }
}

bool Renderer::IsPathCompleted() {
  return is_start_selected_ && is_end_selected_ && (start_ != end_);
}

const Point& Renderer::GetStartPoint() { return start_; }
const Point& Renderer::GetEndPoint() { return end_; }

void Renderer::Reset() {
  clear();
  path_ = nullptr;
  is_path_drawn_ = false;
  is_start_selected_ = false;
  is_end_selected_ = false;
}

}  // namespace s21

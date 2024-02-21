#include "model.h"
namespace s21 {

Model::Model() {
  maze_.is_correct = false;
  start_.Reset();
  end_.Reset();
}

void Model::SetMazeRows(size_t rows) noexcept { maze_rows_ = rows; }

void Model::SetPathPoints(Point start, Point end) {
  start_ = start;
  end_ = end;
}

void Model::SetMazeColumns(size_t columns) noexcept { maze_columns_ = columns; }

void Model::GenerateMaze() {
  maze_ = maze_gen_.GenerateMaze(maze_rows_, maze_columns_);
  status_ = "Status: Maze successfully generated!";
}

const MazeData& Model::GetMazeData() { return maze_; }

void Model::SaveMazeDataToFile(const std::string& path) {
  if (maze_.is_correct) {
    FileWriter* writer = &FileWriter::GetInstance();
    status_ = "Status: Maze successfully saved!";
    try {
      writer->WriteDataToFile(path, maze_);
    } catch (OpenFileError& e) {
      status_ = e.what();
    }
  }
}

void Model::ReadMazeDataFromFile(const std::string& path) {
  FileReader* reader = &FileReader::GetInstance();
  status_ = "Status: Maze successfully loaded!";
  try {
    maze_ = reader->ReadDataFromFile(path);
    ValidateMaze();
  } catch (std::runtime_error& e) {
    maze_.is_correct = false;
    status_ = e.what();
  }
}

void Model::SolveMaze() {
  maze_solver_.SetMaze(maze_);
  path_ = maze_solver_.SolveMaze(start_, end_);
  if (path_.empty()) {
    status_ = "Status: Start = end/Impossible to build the path!";
  } else {
    status_ = "Status: Maze successfully solved!";
  }
}

void Model::ValidateMaze() {
  maze_.is_correct = true;
  for (size_t i = 0; i < maze_.right_borders.GetRows(); i++) {
    if (!maze_.right_borders(i, maze_.right_borders.GetColumns() - 1)) {
      maze_.is_correct = false;
      status_ = "Status: Incorrect right border value!";
      break;
    }
  }
  if (maze_.is_correct) {
    for (size_t i = 0; i < maze_.bottom_borders.GetColumns(); i++) {
      if (!maze_.bottom_borders(maze_.bottom_borders.GetRows() - 1, i)) {
        maze_.is_correct = false;
        status_ = "Status: Incorrect bottom border value!";
        break;
      }
    }
  }
}

const std::vector<Point>& Model::GetPath() { return path_; }

const std::string& Model::GetStatus() { return status_; }

}  // namespace s21
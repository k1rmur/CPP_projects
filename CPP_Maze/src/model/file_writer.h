#ifndef A1_MAZE_SRC_MODEL_FILE_WRITER_H_

#define A1_MAZE_SRC_MODEL_FILE_WRITER_H_

#include <fstream>
#include <string>

#include "exceptions.h"
#include "maze_data.h"

namespace s21 {

class FileWriter {
 public:
  FileWriter(const FileWriter&) = delete;
  FileWriter& operator=(const FileWriter&) = delete;

  static FileWriter& GetInstance() {
    static FileWriter instance;
    return instance;
  }

  void WriteDataToFile(const std::string& path, const MazeData& data);

 private:
  FileWriter() {}

  void WriteMatrix(std::ofstream& file, const Matrix& data);
};

}  // namespace s21

#endif
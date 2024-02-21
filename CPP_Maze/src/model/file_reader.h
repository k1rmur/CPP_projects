#ifndef A1_MAZE_SRC_MODEL_FILE_READER_H_

#define A1_MAZE_SRC_MODEL_FILE_READER_H_

#include <fstream>
#include <string>

#include "exceptions.h"
#include "maze_data.h"

namespace s21 {
class FileReader {
 public:
  FileReader(const FileReader&) = delete;
  FileReader& operator=(const FileReader&) = delete;

  static FileReader& GetInstance() {
    static FileReader instance;
    return instance;
  }

  MazeData ReadDataFromFile(const std::string& path);

 private:
  FileReader() {}

  void ParseFirstLine(MazeData& data, const std::string& str);
  void ParseMatrixData(Matrix& data, std::ifstream& file);

  bool IsBool(char c);
  bool IsSymbolValid(char c);
};
}  // namespace s21

#endif
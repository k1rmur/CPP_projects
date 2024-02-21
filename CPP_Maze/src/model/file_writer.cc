#include "file_writer.h"

namespace s21 {

void FileWriter::WriteDataToFile(const std::string& path,
                                 const MazeData& data) {
  std::ofstream file;
  file.open(path);
  if (file.is_open()) {
    file << data.right_borders.GetRows() << " "
         << data.bottom_borders.GetColumns() << std::endl;
    WriteMatrix(file, data.right_borders);
    file << std::endl << std::endl;
    WriteMatrix(file, data.bottom_borders);
    file.close();
  } else {
    throw OpenFileError("Status: Can't open the file!");
  }
}

void FileWriter::WriteMatrix(std::ofstream& file, const Matrix& data) {
  for (size_t i = 0; i < data.GetRows(); i++) {
    for (size_t j = 0; j < data.GetColumns(); j++) {
      file << static_cast<int>(data(i, j));
      if (j != data.GetColumns() - 1) {
        file << " ";
      }
    }
    if (i != data.GetRows() - 1) {
      file << std::endl;
    }
  }
}

}  // namespace s21
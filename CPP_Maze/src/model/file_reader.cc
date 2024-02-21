#include "file_reader.h"

namespace s21 {
MazeData FileReader::ReadDataFromFile(const std::string& path) {
  MazeData result;
  std::ifstream file;
  file.open(path);
  if (file.is_open()) {
    if (file.peek() == EOF) {
      file.close();
      throw FileContentError("Status: File content error!");
    }
    std::string buffer;
    getline(file, buffer);
    try {
      ParseFirstLine(result, buffer);
      ParseMatrixData(result.right_borders, file);
      getline(file, buffer);
      if (buffer.size() == 0) {
        ParseMatrixData(result.bottom_borders, file);
      } else {
        throw FileContentError("Status: File content error!");
      }
    } catch (...) {
      file.close();
      throw;
    }
    file.close();
  } else {
    throw OpenFileError("Status: Can't open the file!");
  }
  result.is_correct = true;
  return result;
}

void FileReader::ParseFirstLine(MazeData& data, const std::string& str) {
  size_t pos = 0;
  size_t length = 0;
  int rows = 0;
  int columns = 0;
  try {
    rows = std::stoi(str, &pos);
    rows *= str[pos] == ' ' ? 1 : 0;
    length += pos;
    columns = std::stoi(str.substr(pos + 1), &pos);
    length += pos + 1;
    columns *= str[length] == '\0' ? 1 : 0;
  } catch (...) {
    throw FileContentError("Status: Wrong data!");
  }
  if ((rows <= 0 || rows > 50 || columns <= 0 || columns > 50)) {
    throw FileContentError("Status: Wrong Size Line Data!");
  }
  data.SetSize(rows, columns);
}

void FileReader::ParseMatrixData(Matrix& data, std::ifstream& file) {
  for (size_t i = 0; i < data.GetRows(); i++) {
    std::string buffer;
    size_t count = 0;
    if (getline(file, buffer)) {
      for (size_t j = 0; j < buffer.size(); j++) {
        if (j % 2 == 0) {
          if (IsBool(buffer[j]) && count < data.GetColumns()) {
            data(i, count) = static_cast<bool>(buffer[j] - '0');
            count++;
          } else {
            throw FileContentError("Status: File content error!");
          }
        } else if (!IsSymbolValid(buffer[j])) {
          throw FileContentError("Status: Invalid character!");
        }
      }
      if (count != data.GetColumns()) {
        throw FileContentError("Status: Incorrect number of elements in line!");
      }
    } else {
      throw FileContentError("Status: Not enough lines!");
    }
  }
}

bool FileReader::IsBool(char c) { return c == '0' || c == '1'; }

bool FileReader::IsSymbolValid(char c) {
  return c == ' ' || c == '\n' || c == '\0';
}

}  // namespace s21

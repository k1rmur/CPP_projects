#ifndef A1_MAZE_SRC_MODEL_EXCEPTIONS_H_

#define A1_MAZE_SRC_MODEL_EXCEPTIONS_H_

#include <stdexcept>

class FileContentError : public std::runtime_error {
 public:
  explicit FileContentError(const char* message)
      : std::runtime_error(message) {}
};

class OpenFileError : public std::runtime_error {
 public:
  explicit OpenFileError(const char* message) : std::runtime_error(message) {}
};

#endif
#include "../controller/controller.h"
#include "gtest/gtest.h"

TEST(TestReadData, Test_1) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze10x10_1.txt");
  s21::MazeData res = model.GetMazeData();
  bool right_check[100]{0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0,
                        1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1,
                        0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
                        0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1,
                        0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1,
                        1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1};
  bool bot_check[100]{0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1,
                      0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0,
                      0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0,
                      1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0,
                      1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                      0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_EQ(res.bottom_borders.GetRows(), 10);
  ASSERT_EQ(res.bottom_borders.GetColumns(), 10);
  ASSERT_EQ(res.right_borders.GetRows(), 10);
  ASSERT_EQ(res.right_borders.GetColumns(), 10);
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully loaded!");
  for (size_t i = 0; i < 100; i++) {
    ASSERT_EQ(res.bottom_borders(i / 10, i % 10), bot_check[i]);
    ASSERT_EQ(res.right_borders(i / 10, i % 10), right_check[i]);
  }
}

TEST(TestReadData, Test_2) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze17x40.txt");
  s21::MazeData res = model.GetMazeData();
  bool right_check[680]{
      0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0,
      1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0,
      1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1,
      0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0,
      1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0,
      1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0,
      1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,
      1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
      1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1,
      0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1,
      1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
      0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0,
      1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1,
      0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0,
      1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1,
      0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
      1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0,
      0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0,
      1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0,
      0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0,
      0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0,
      0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1,
      1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
      0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
      0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 1};
  bool bot_check[680]{
      1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1,
      0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0,
      1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
      1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0,
      1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,
      1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0,
      1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
      0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
      1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1,
      1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
      1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1,
      0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0,
      0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1,
      0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
      1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
      1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0,
      0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0,
      0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0,
      0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
      0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1,
      1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1};
  ASSERT_EQ(res.bottom_borders.GetRows(), 17);
  ASSERT_EQ(res.bottom_borders.GetColumns(), 40);
  ASSERT_EQ(res.right_borders.GetRows(), 17);
  ASSERT_EQ(res.right_borders.GetColumns(), 40);
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully loaded!");
  for (size_t i = 0; i < 680; i++) {
    ASSERT_EQ(res.bottom_borders(i / 40, i % 40), bot_check[i]);
    ASSERT_EQ(res.right_borders(i / 40, i % 40), right_check[i]);
  }
}

TEST(TestReadData, Test_3) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze25x10.txt");
  s21::MazeData res = model.GetMazeData();
  bool right_check[250]{
      0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
      1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1,
      0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0,
      1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1,
      1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0,
      0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1,
      0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1,
      0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
      1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
      1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
      0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1};
  bool bot_check[250]{
      1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
      1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1,
      0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0,
      0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
      1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1,
      0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1,
      0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_EQ(res.bottom_borders.GetRows(), 25);
  ASSERT_EQ(res.bottom_borders.GetColumns(), 10);
  ASSERT_EQ(res.right_borders.GetRows(), 25);
  ASSERT_EQ(res.right_borders.GetColumns(), 10);
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully loaded!");
  for (size_t i = 0; i < 250; i++) {
    ASSERT_EQ(res.bottom_borders(i / 10, i % 10), bot_check[i]);
    ASSERT_EQ(res.right_borders(i / 10, i % 10), right_check[i]);
  }
}

TEST(TestReadData, Test_4) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze20x20.txt");
  s21::MazeData res = model.GetMazeData();
  ASSERT_EQ(res.bottom_borders.GetRows(), 20);
  ASSERT_EQ(res.bottom_borders.GetColumns(), 20);
  ASSERT_EQ(res.right_borders.GetRows(), 20);
  ASSERT_EQ(res.right_borders.GetColumns(), 20);
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully loaded!");
}

TEST(TestReadData, Test_5) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze50x50.txt");
  s21::MazeData res = model.GetMazeData();
  ASSERT_EQ(res.bottom_borders.GetRows(), 50);
  ASSERT_EQ(res.bottom_borders.GetColumns(), 50);
  ASSERT_EQ(res.right_borders.GetRows(), 50);
  ASSERT_EQ(res.right_borders.GetColumns(), 50);
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully loaded!");
}

TEST(TestReadData, Test_6) {
  s21::Model model;
  model.ReadMazeDataFromFile("no_such_file.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Can't open the file!");
}

TEST(TestReadData, Test_7) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/empty_file.txt");
  ASSERT_EQ(model.GetStatus(), "Status: File content error!");
}

TEST(TestReadData, Test_8) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_1.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Wrong Size Line Data!");
}

TEST(TestReadData, Test_9) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_2.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Invalid character!");
}

TEST(TestReadData, Test_10) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_3.txt");
  ASSERT_EQ(model.GetStatus(), "Status: File content error!");
}

TEST(TestReadData, Test_11) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_4.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Incorrect number of elements in line!");
}

TEST(TestReadData, Test_12) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_5.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Not enough lines!");
}

TEST(TestReadData, Test_13) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_6.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Not enough lines!");
}

TEST(TestReadData, Test_14) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_1.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Incorrect right border value!");
}

TEST(TestReadData, Test_15) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_2.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Incorrect bottom border value!");
}

TEST(TestReadData, Test_16) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_3.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Wrong data!");
}

TEST(TestReadData, Test_17) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_4.txt");
  ASSERT_EQ(model.GetStatus(), "Status: File content error!");
}

TEST(TestReadData, Test_18) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_5.txt");
  ASSERT_EQ(model.GetStatus(), "Status: File content error!");
}

TEST(TestReadData, Test_19) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_6.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Incorrect number of elements in line!");
}

TEST(TestReadData, Test_20) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_8.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Wrong Size Line Data!");
}

TEST(TestReadData, Test_21) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/incorrect_maze_7.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Wrong Size Line Data!");
}

TEST(TestReadData, Test_22) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_8.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Wrong Size Line Data!");
}

TEST(TestReadData, Test_23) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_8.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Wrong Size Line Data!");
}

TEST(TestReadData, Test_24) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/wrong_maze_data_9.txt");
  ASSERT_EQ(model.GetStatus(), "Status: Wrong Size Line Data!");
}

TEST(TestSolveMaze, Test_1) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze10x10_1.txt");
  model.SetPathPoints(s21::Point(0, 0), s21::Point(9, 9));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  std::vector<s21::Point> check{
      s21::Point(9, 9), s21::Point(9, 8), s21::Point(9, 7), s21::Point(9, 6),
      s21::Point(8, 6), s21::Point(7, 6), s21::Point(7, 5), s21::Point(6, 5),
      s21::Point(6, 6), s21::Point(6, 7), s21::Point(5, 7), s21::Point(5, 8),
      s21::Point(6, 8), s21::Point(6, 9), s21::Point(5, 9), s21::Point(4, 9),
      s21::Point(3, 9), s21::Point(2, 9), s21::Point(1, 9), s21::Point(0, 9),
      s21::Point(0, 8), s21::Point(1, 8), s21::Point(2, 8), s21::Point(3, 8),
      s21::Point(3, 7), s21::Point(2, 7), s21::Point(1, 7), s21::Point(1, 6),
      s21::Point(1, 5), s21::Point(1, 4), s21::Point(0, 4), s21::Point(0, 3),
      s21::Point(1, 3), s21::Point(2, 3), s21::Point(2, 4), s21::Point(2, 5),
      s21::Point(3, 5), s21::Point(3, 4), s21::Point(4, 4), s21::Point(4, 3),
      s21::Point(3, 3), s21::Point(3, 2), s21::Point(3, 1), s21::Point(2, 1),
      s21::Point(2, 2), s21::Point(1, 2), s21::Point(0, 2), s21::Point(0, 1),
      s21::Point(0, 0)};
  for (size_t i = 0; i < res.size(); i++) {
    ASSERT_TRUE(res[i] == check[i]);
  }
}

TEST(TestSolveMaze, Test_2) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze17x40.txt");
  model.SetPathPoints(s21::Point(16, 38), s21::Point(12, 38));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  std::vector<s21::Point> check{s21::Point(12, 38), s21::Point(13, 38),
                                s21::Point(14, 38), s21::Point(15, 38),
                                s21::Point(16, 38)};
  for (size_t i = 0; i < res.size(); i++) {
    ASSERT_TRUE(res[i] == check[i]);
  }
}

TEST(TestSolveMaze, Test_3) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze20x20.txt");
  model.SetPathPoints(s21::Point(19, 19), s21::Point(19, 11));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  std::vector<s21::Point> check{
      s21::Point(19, 11), s21::Point(19, 12), s21::Point(19, 13),
      s21::Point(19, 14), s21::Point(19, 15), s21::Point(19, 16),
      s21::Point(19, 17), s21::Point(19, 18), s21::Point(19, 19)};
  for (size_t i = 0; i < res.size(); i++) {
    ASSERT_TRUE(res[i] == check[i]);
  }
}

TEST(TestSolveMaze, Test_4) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze50x50.txt");
  model.SetPathPoints(s21::Point(23, 14), s21::Point(47, 48));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  ASSERT_TRUE(!res.empty());
}

TEST(TestSolveMaze, Test_5) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze50x50.txt");
  model.SetPathPoints(s21::Point(23, 23), s21::Point(23, 23));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(),
            "Status: Start = end/Impossible to build the path!");
  auto res = model.GetPath();
  ASSERT_TRUE(res.empty());
}

TEST(TestSolveMaze, Test_6) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze25x10.txt");
  model.SetPathPoints(s21::Point(1, 1), s21::Point(1, 2));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  ASSERT_TRUE(!res.empty());
}

TEST(TestSolveMaze, Test_7) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze25x10.txt");
  model.SetPathPoints(s21::Point(0, 0), s21::Point(11, 8));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  ASSERT_TRUE(!res.empty());
}

TEST(TestSolveMaze, Test_8) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze10x10_2.txt");
  model.SetPathPoints(s21::Point(9, 1), s21::Point(8, 5));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  ASSERT_TRUE(!res.empty());
}

TEST(TestSolveMaze, Test_9) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze50x50.txt");
  model.SetPathPoints(s21::Point(10, 49), s21::Point(49, 0));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  ASSERT_TRUE(!res.empty());
}

TEST(TestSolveMaze, Test_10) {
  s21::Model model;
  model.ReadMazeDataFromFile("../data-samples/maze17x40.txt");
  model.SetPathPoints(s21::Point(2, 15), s21::Point(16, 30));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(), "Status: Maze successfully solved!");
  auto res = model.GetPath();
  ASSERT_TRUE(!res.empty());
}

TEST(TestSolveMaze, Test_11) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/closed_end.txt");
  model.SetPathPoints(s21::Point(0, 0), s21::Point(0, 1));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(),
            "Status: Start = end/Impossible to build the path!");
  auto res = model.GetPath();
  ASSERT_TRUE(res.empty());
}

TEST(TestSolveMaze, Test_12) {
  s21::Model model;
  model.ReadMazeDataFromFile("./tests/closed_end.txt");
  model.SetPathPoints(s21::Point(0, 0), s21::Point(0, 0));
  model.SolveMaze();
  ASSERT_EQ(model.GetStatus(),
            "Status: Start = end/Impossible to build the path!");
  auto res = model.GetPath();
  ASSERT_TRUE(res.empty());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

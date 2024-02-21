#include <QApplication>

#include "maze_view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  MazeView view(&controller);
  view.show();
  return a.exec();
}

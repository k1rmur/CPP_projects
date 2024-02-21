#ifndef A1_MAZE_SRC_VIEW_MAZEVIEW_H_
#define A1_MAZE_SRC_VIEW_MAZEVIEW_H_

#include <QFileDialog>
#include <QMainWindow>

#include "../controller/controller.h"
#include "renderer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MazeView;
}
QT_END_NAMESPACE

class MazeView : public QMainWindow {
  Q_OBJECT

 public:
  MazeView(s21::Controller* c, QWidget* parent = nullptr);
  ~MazeView();

 private:
  void SetEventHandler();

  Ui::MazeView* ui_;
  s21::Controller* controller_;
  s21::Renderer* renderer_;

 private slots:
  void ProcessMazeGenerateButtonClicked();
  void ProcessExportButtonClicked();
  void ProcessImportButtonCLicked();
  void ProcessSolveMazeButtonClicked();
};
#endif  // MAZEVIEW_H_

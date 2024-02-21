#include "maze_view.h"

#include "ui_maze_view.h"

MazeView::MazeView(s21::Controller* c, QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::MazeView), controller_(c) {
  ui_->setupUi(this);
  renderer_ = new s21::Renderer();
  ui_->graphicsView->setScene(renderer_);
  SetEventHandler();
}

MazeView::~MazeView() {
  delete ui_;
  delete renderer_;
}

void MazeView::SetEventHandler() {
  connect(ui_->pushButton_MazeGenerate, SIGNAL(clicked()), this,
          SLOT(ProcessMazeGenerateButtonClicked()));
  connect(ui_->pushButton_Export, SIGNAL(clicked()), this,
          SLOT(ProcessExportButtonClicked()));
  connect(ui_->pushButton_Import, SIGNAL(clicked()), this,
          SLOT(ProcessImportButtonCLicked()));
  connect(ui_->pushButton_SolveMaze, SIGNAL(clicked()), this,
          SLOT(ProcessSolveMazeButtonClicked()));
}

void MazeView::ProcessMazeGenerateButtonClicked() {
  double rows = ui_->spinBox_MazeRows->value();
  double columns = ui_->spinBox_MazeColumns->value();
  renderer_->SetMazeData(controller_->GenerateMaze(rows, columns));
  renderer_->DrawMaze();
  ui_->label_status->setText(QString::fromStdString(controller_->GetStatus()));
}

void MazeView::ProcessExportButtonClicked() {
  QString file = QFileDialog::getSaveFileName(nullptr, "Input file name:", "/",
                                              "TXT (*.txt)");
  if (!file.isNull()) {
    controller_->ExportDataToFile(file.toStdString());
    ui_->label_status->setText(
        QString::fromStdString(controller_->GetStatus()));
  }
}

void MazeView::ProcessImportButtonCLicked() {
  QString file = QFileDialog::getOpenFileName(nullptr, "Input file name:", "/",
                                              "TXT (*.txt)");
  if (!file.isNull()) {
    const s21::MazeData& maze =
        controller_->ImportDataFromFile(file.toStdString());
    if (maze.is_correct) {
      ui_->spinBox_MazeRows->setValue(maze.right_borders.GetRows());
      ui_->spinBox_MazeColumns->setValue(maze.right_borders.GetColumns());
    }
    renderer_->SetMazeData(maze);
    renderer_->DrawMaze();
    ui_->label_status->setText(
        QString::fromStdString(controller_->GetStatus()));
  }
}

void MazeView::ProcessSolveMazeButtonClicked() {
  if (renderer_->IsPathCompleted()) {
    const std::vector<s21::Point>& path = controller_->FindPath(
        renderer_->GetStartPoint(), renderer_->GetEndPoint());
    renderer_->SetMazePath(path);
    renderer_->DrawPath();
    ui_->label_status->setText(
        QString::fromStdString(controller_->GetStatus()));
  }
}

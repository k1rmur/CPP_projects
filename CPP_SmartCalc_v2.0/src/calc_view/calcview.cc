#include "calcview.h"

#include "ui_calcview.h"

CalcView::CalcView(s21::CalcController* controller, QWidget* parent)
    : QMainWindow(parent), controller_(controller), ui(new Ui::CalcView) {
  ui->setupUi(this);
}

CalcView::~CalcView() { delete ui; }

void CalcView::on_pushButton_30_clicked() { ui->lineEdit->insert("0"); }

void CalcView::on_pushButton_clicked() { ui->lineEdit->insert("+"); }

void CalcView::on_pushButton_2_clicked() { ui->lineEdit->insert("-"); }

void CalcView::on_pushButton_3_clicked() { ui->lineEdit->insert("*"); }

void CalcView::on_pushButton_4_clicked() { ui->lineEdit->insert("^"); }

void CalcView::on_pushButton_5_clicked() { ui->lineEdit->insert("/"); }

void CalcView::on_pushButton_6_clicked() { ui->lineEdit->insert("cos"); }

void CalcView::on_pushButton_7_clicked() { ui->lineEdit->insert("acos"); }

void CalcView::on_pushButton_8_clicked() { ui->lineEdit->insert("sin"); }

void CalcView::on_pushButton_9_clicked() { ui->lineEdit->insert("tan"); }

void CalcView::on_pushButton_10_clicked() { ui->lineEdit->insert("asin"); }

void CalcView::on_pushButton_11_clicked() { ui->lineEdit->insert("atan"); }

void CalcView::on_pushButton_12_clicked() { ui->lineEdit->insert("log"); }

void CalcView::on_pushButton_13_clicked() { ui->lineEdit->insert("sqrt"); }

void CalcView::on_pushButton_14_clicked() { ui->lineEdit->insert("ln"); }

void CalcView::on_pushButton_15_clicked() { ui->lineEdit->insert("mod"); }

void CalcView::on_pushButton_16_clicked() { ui->lineEdit->insert("1"); }

void CalcView::on_pushButton_17_clicked() { ui->lineEdit->insert("2"); }

void CalcView::on_pushButton_18_clicked() { ui->lineEdit->insert("3"); }

void CalcView::on_pushButton_19_clicked() { ui->lineEdit->insert("4"); }

void CalcView::on_pushButton_20_clicked() { ui->lineEdit->insert("5"); }

void CalcView::on_pushButton_22_clicked() { ui->lineEdit->insert("6"); }

void CalcView::on_pushButton_23_clicked() { ui->lineEdit->insert("7"); }

void CalcView::on_pushButton_24_clicked() { ui->lineEdit->insert("8"); }

void CalcView::on_pushButton_25_clicked() { ui->lineEdit->insert("9"); }

void CalcView::on_pushButton_26_clicked() { ui->lineEdit->insert("x"); }

void CalcView::on_pushButton_27_clicked() { ui->lineEdit->clear(); }

void CalcView::on_pushButton_28_clicked() { ui->lineEdit->insert("("); }

void CalcView::on_pushButton_29_clicked() { ui->lineEdit->insert(")"); }

void CalcView::on_pushButton_31_clicked() { ui->lineEdit->insert("."); }

void CalcView::on_pushButton_32_clicked() { ui->lineEdit->backspace(); }

void CalcView::on_pushButton_33_clicked() { ui->lineEdit->insert("e"); }

void CalcView::on_pushButton_21_clicked() {
  controller_->SetXValue(ui->doubleSpinBox->value());
  controller_->SetInputString(ui->lineEdit->text().toStdString());
  ui->lineEdit->setText(QString::fromStdString(controller_->GetStringAnswer()));
}

void CalcView::on_pushButton_34_clicked() {
  double a = ui->doubleSpinBox_2->value();
  double b = ui->doubleSpinBox_3->value();
  controller_->SetPlot(a, b, ui->lineEdit->text().toStdString());
  QVector<double> qX(controller_->GetXPlot().begin(),
                     controller_->GetXPlot().end());
  QVector<double> qY(controller_->GetYPlot().begin(),
                     controller_->GetYPlot().end());
  ui->widget->clearGraphs();
  ui->widget->addGraph();
  if (controller_->GetCheckPlot()) {
    ui->widget->graph(0)->setData(qX, qY);
  } else {
    ui->lineEdit->setText(
        QString::fromStdString(controller_->GetStringAnswer()));
  }
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  ui->widget->xAxis->setRange(a, b);
  ui->widget->yAxis->setRange(ui->doubleSpinBox_4->value(),
                              ui->doubleSpinBox_5->value());
  ui->widget->replot();
}

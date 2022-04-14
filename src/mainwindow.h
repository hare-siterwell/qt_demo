/**
 * @file mainwindow.h
 * @author y
 * @brief Main Window
 * @version 1.0
 * @date 2022-03-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

 private:
  Ui::MainWindow *ui = nullptr;
};

#endif  // MAINWINDOW_H

/**
 * @file mainwindow.cpp
 * @author y
 * @brief Main Window
 * @version 1.0
 * @date 2022-03-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "mainwindow.h"

#include "ui_mainwindow.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

/**
 * @brief Destroy the Main Window:: Main Window object
 *
 */
MainWindow::~MainWindow() { delete ui; }

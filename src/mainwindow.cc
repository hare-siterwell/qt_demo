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

#include <QMessageBox>
#include <qDebug>

#include "config.h"
#include "ui_mainwindow.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::About);
}

/**
 * @brief Destroy the Main Window:: Main Window object
 *
 */
MainWindow::~MainWindow() { delete ui; }

/**
 * @brief Show version information
 *
 */
void MainWindow::About()
{
  QMessageBox::about(
      this, tr("About"),
      tr("<h2>%1</h2>"
         "<p>Version: %2</p>"
         "<p>%3</p>"
         "<p>%4</p>")
          .arg(VER_FILEDESCRIPTION_STR)
          .arg(VER_PRODUCTVERSION_STR)
          .arg(VER_LEGALCOPYRIGHT_STR)
          .arg(tr("This is a simple application to demonstrate Qt features.")));
}

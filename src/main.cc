/**
 * @file main.cpp
 * @author y
 * @brief
 * @version 1.0
 * @date 2022-03-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <QApplication>

#include "mainwindow.h"

/**
 * @brief The application entry point
 *
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 * @return int The exit code of the application
 */
auto main(int argc, char** argv) -> int
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return QApplication::exec();
}

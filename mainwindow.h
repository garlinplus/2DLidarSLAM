#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QKeyEvent>
#include <QtCore>

#include "robot.h"

class OSGWidget;
class QTimerEvent;

namespace Ui
{
class MainWindowForm;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void on_actionExit_triggered();

  void keyPressEvent(QKeyEvent *event);

protected:
  Ui::MainWindowForm *main_window_ui_;
  OSGWidget *osg_widget_{ nullptr };

  int timer_id_;
  void timerEvent(QTimerEvent *event);
  std::unique_ptr<robo::Robot> robot_{ nullptr };
};

#endif  // MAINWINDOW_H

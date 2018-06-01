#include <QApplication>
#include <QKeySequence>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QDesktopServices>

#include "qtermwidget.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QMainWindow *mainWindow = new QMainWindow();

  //grabs size of desktop window and sets the terminal window size to 50%

  QDesktopWidget desktop;
  int x = desktop.width()*0.5;
  int y = desktop.height()*0.5;
  mainWindow->setFixedSize(x,y);

  //terminal environment information
  setenv("TERM", "konsole-256color", 1);

  //sets font 
  QTermWidget *console = new QTermWidget();
  QFont font = QApplication::font();
  font.setFamily("Monospace");
  font.setPointSize(12);

  console->setTerminalFont(font);
  console->setColorScheme("Solarized");
  console->setTerminalOpacity(0.9);

  QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));

  mainWindow->setCentralWidget(console);

  mainWindow->show();
  return app.exec();
}



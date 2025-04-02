#include <QApplication>
#include <QPushButton>

#include "main_window.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    auto mainWindow = MainWindow(nullptr);
    mainWindow.show();
    return QApplication::exec();
}
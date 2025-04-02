//
// Created by krauzerkrip on 02.04.25.
//

#include <QPlainTextEdit>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVideoWidget>
#include <QtWidgets/qsizepolicy.h>
#include <QPushButton>

#include "main_window.h"

static int getSpacing(QPlainTextEdit* textEdit)
{
    QMargins margins = textEdit->contentsMargins();
    const QTextDocument* doc = textEdit->document();
    return QFontMetrics(textEdit->font()).lineSpacing() + doc->documentMargin () * 2 +
        margins.top() + margins.bottom();
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    auto* dock = new QDockWidget(tr("Connection"), this);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    auto* vboxWidget = new QWidget(this);
    auto* vbox = new QVBoxLayout(vboxWidget);
    vboxWidget->setLayout(vbox);

    vboxWidget->setMaximumHeight(256);
    vboxWidget->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Maximum));

    auto* ipField = new QPlainTextEdit(vboxWidget);
    auto* portField = new QPlainTextEdit(vboxWidget);

    ipField->setPlaceholderText("228.228.228.228");
    portField->setPlaceholderText("1337");

    ipField->setFixedHeight(getSpacing(ipField));
    portField->setFixedHeight(getSpacing(ipField));

    vbox->addWidget(ipField);
    vbox->addWidget(portField);

    auto* vboxButtonsWidget = new QWidget(this);
    auto* vboxButtons = new QVBoxLayout(vboxButtonsWidget);

    auto* startButton = new QPushButton(vboxButtonsWidget);
    startButton->setText("Start");
    vboxButtons->addWidget(startButton);

    auto* hboxWidget = new QWidget(this);
    auto* hbox = new QHBoxLayout(hboxWidget);

    hboxWidget->setLayout(hbox);

    hbox->addWidget(vboxWidget);
    hbox->addWidget(vboxButtonsWidget);

    dock->setWidget(hboxWidget);

    auto viewfinder = new QVideoWidget();
    viewfinder->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
    this->setCentralWidget(viewfinder);
}

#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include "QtCore/QTextStream"
#include "QtCore/QDir"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = Q_NULLPTR);

private:
    void connectSlots();

    void findFiles(QDir dir);
    void convertCodec(const QString& strFileName);

private slots:
    void slotSelect();
    void slotConvert();
    void slotToggled(bool checked);

private:
    Ui::MainWidgetClass ui;

    QStringList m_slstSuffix;
    QString m_strCodecName;
};

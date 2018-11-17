#include "MainWidget.h"
#include "QtCore/QFile"
#include "QtWidgets/QFileDialog"
#include "QtWidgets/QMessageBox"
#include "QtCore/QDebug"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , m_strCodecName("UTF-8")
{
    ui.setupUi(this);

    connectSlots();
    m_slstSuffix << "c" << "cpp" << "h";
}

void MainWidget::connectSlots()
{
    connect(ui.btnSelect, &QPushButton::clicked, this, &MainWidget::slotSelect);
    connect(ui.btnConvert, &QPushButton::clicked, this, &MainWidget::slotConvert);
    connect(ui.rbtnGBK, &QRadioButton::toggled, this, &MainWidget::slotToggled);
    connect(ui.rbtnUtf8, &QRadioButton::toggled, this, &MainWidget::slotToggled);
}

void MainWidget::slotSelect()
{
    QString strDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
        ".",
        QFileDialog::ShowDirsOnly
        | QFileDialog::DontResolveSymlinks);

    if (!strDir.isEmpty())
    {
        ui.lineEditDir->setText(strDir);
    }
}

void MainWidget::slotConvert()
{
    QDir dir(ui.lineEditDir->text());
    if (!dir.exists())
    {
        return;
    }

    ui.textEdit->append(" begin convert...");

    findFiles(dir);

    ui.textEdit->append(" end convert");

    QMessageBox::information(this, "convert files", "convert success!");
}


void MainWidget::slotToggled(bool checked)
{
    QRadioButton* pRBtn = qobject_cast<QRadioButton*>(sender());
    if (!pRBtn)
    {
        return;
    }

    if (pRBtn == ui.rbtnUtf8 && checked)
    {
        m_strCodecName = "UTF-8";
        qDebug() << checked;
    }
    else if (pRBtn == ui.rbtnGBK && checked)
    {
        m_strCodecName = "GBK";
        qDebug() << checked;
    }
}

void MainWidget::findFiles(QDir dir)
{
    QFileInfoList infoList = dir.entryInfoList(QStringList(), QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    qDebug() << infoList.size();

    for (auto& fileInfo : infoList)
    {
        if (fileInfo.isDir())
        {
            qDebug() << fileInfo.absoluteFilePath();
            //dir.cd(fileInfo.dir());
            findFiles(fileInfo.absoluteFilePath());
            // dir.cdUp();
        }
        else
        {
            if (m_slstSuffix.contains(fileInfo.suffix()))
            {
                QString strFileName = fileInfo.filePath();
                qDebug() << strFileName;
                ui.textEdit->append(strFileName + "   convert...");
                convertCodec(strFileName);
            }
        }
    }
}



void MainWidget::convertCodec(const QString& strFileName)
{
    QFile oFile(strFileName);
    QString strContent;
    if (oFile.open(QIODevice::ReadOnly))
    {
        strContent = oFile.readAll();
    }
    oFile.close();
    bool br = oFile.remove();
    qDebug() << br;

    oFile.setFileName(strFileName);
    if (oFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&oFile);
        out.setCodec(m_strCodecName.toStdString().c_str());
        out << strContent;
    }
    oFile.close();
}
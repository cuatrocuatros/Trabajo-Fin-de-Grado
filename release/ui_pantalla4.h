/********************************************************************************
** Form generated from reading UI file 'pantalla4.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA4_H
#define UI_PANTALLA4_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_pantalla4
{
public:
    QLabel *label_6;
    QPushButton *pushButton;
    QLabel *label_5;
    QSlider *horizontalSlider;
    QLabel *label_17;
    QLabel *label_11;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_2;
    QLabel *label_12;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QPushButton *pushButton_6;

    void setupUi(QDialog *pantalla4)
    {
        if (pantalla4->objectName().isEmpty())
            pantalla4->setObjectName(QStringLiteral("pantalla4"));
        pantalla4->resize(878, 478);
        label_6 = new QLabel(pantalla4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 340, 81, 21));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(11);
        label_6->setFont(font);
        pushButton = new QPushButton(pantalla4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 350, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton->setFont(font1);
        label_5 = new QLabel(pantalla4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 270, 71, 31));
        label_5->setFont(font);
        horizontalSlider = new QSlider(pantalla4);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(480, 280, 241, 22));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(5000);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_17 = new QLabel(pantalla4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(790, 280, 47, 13));
        label_17->setFont(font);
        label_11 = new QLabel(pantalla4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(750, 280, 31, 16));
        label_11->setFont(font);
        horizontalSlider_2 = new QSlider(pantalla4);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(480, 340, 241, 22));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(1000);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(pantalla4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 350, 91, 31));
        pushButton_2->setFont(font1);
        label_12 = new QLabel(pantalla4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(750, 340, 31, 20));
        label_12->setFont(font);
        pushButton_3 = new QPushButton(pantalla4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 0, 75, 23));
        pushButton_4 = new QPushButton(pantalla4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(800, 0, 75, 23));
        pushButton_5 = new QPushButton(pantalla4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 250, 131, 41));
        label_2 = new QLabel(pantalla4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 260, 151, 16));
        label_3 = new QLabel(pantalla4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 50, 421, 100));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(47);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_4 = new QLabel(pantalla4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 30, 141, 121));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_4->setScaledContents(true);
        label_9 = new QLabel(pantalla4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(400, 170, 101, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Cambria"));
        font3.setPointSize(19);
        font3.setBold(true);
        font3.setWeight(75);
        label_9->setFont(font3);
        pushButton_6 = new QPushButton(pantalla4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(480, 390, 131, 61));
        pushButton_6->setFont(font1);

        retranslateUi(pantalla4);

        QMetaObject::connectSlotsByName(pantalla4);
    } // setupUi

    void retranslateUi(QDialog *pantalla4)
    {
        pantalla4->setWindowTitle(QApplication::translate("pantalla4", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("pantalla4", "Amplitud", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pantalla4", "PLAY", Q_NULLPTR));
        label_5->setText(QApplication::translate("pantalla4", "Frecuencia", Q_NULLPTR));
        label_17->setText(QApplication::translate("pantalla4", "Hz", Q_NULLPTR));
        label_11->setText(QApplication::translate("pantalla4", "47", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pantalla4", "STOP", Q_NULLPTR));
        label_12->setText(QApplication::translate("pantalla4", "1", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("pantalla4", "Atr\303\241s", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pantalla4", "Inicio", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pantalla4", "Cargar MP3", Q_NULLPTR));
        label_2->setText(QApplication::translate("pantalla4", "Cancion: hoy.mp3", Q_NULLPTR));
        label_3->setText(QApplication::translate("pantalla4", "Acoustic Hand", Q_NULLPTR));
        label_4->setText(QString());
        label_9->setText(QApplication::translate("pantalla4", "Perfil 1", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("pantalla4", "Guardar perfil", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pantalla4: public Ui_pantalla4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA4_H

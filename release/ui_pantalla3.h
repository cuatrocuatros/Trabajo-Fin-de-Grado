/********************************************************************************
** Form generated from reading UI file 'pantalla3.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA3_H
#define UI_PANTALLA3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pantalla3
{
public:
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *pantalla3)
    {
        if (pantalla3->objectName().isEmpty())
            pantalla3->setObjectName(QStringLiteral("pantalla3"));
        pantalla3->resize(878, 478);
        pushButton = new QPushButton(pantalla3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 290, 181, 51));
        QFont font;
        font.setPointSize(13);
        font.setBold(false);
        font.setWeight(50);
        pushButton->setFont(font);
        label_2 = new QLabel(pantalla3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 210, 101, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(19);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        pushButton_4 = new QPushButton(pantalla3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 0, 75, 23));
        pushButton_2 = new QPushButton(pantalla3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 290, 191, 51));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(pantalla3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(800, 0, 75, 23));
        label_3 = new QLabel(pantalla3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 50, 421, 100));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(47);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_4 = new QLabel(pantalla3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 30, 141, 121));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_4->setScaledContents(true);

        retranslateUi(pantalla3);

        QMetaObject::connectSlotsByName(pantalla3);
    } // setupUi

    void retranslateUi(QDialog *pantalla3)
    {
        pantalla3->setWindowTitle(QApplication::translate("pantalla3", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pantalla3", "LANZAR", Q_NULLPTR));
        label_2->setText(QApplication::translate("pantalla3", "Perfil 1", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pantalla3", "Atr\303\241s", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pantalla3", "AJUSTES DE PERFIL", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("pantalla3", "Inicio", Q_NULLPTR));
        label_3->setText(QApplication::translate("pantalla3", "Acoustic Hand", Q_NULLPTR));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pantalla3: public Ui_pantalla3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA3_H

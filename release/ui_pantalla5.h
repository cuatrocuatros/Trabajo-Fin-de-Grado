/********************************************************************************
** Form generated from reading UI file 'pantalla5.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA5_H
#define UI_PANTALLA5_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pantalla5
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *pantalla5)
    {
        if (pantalla5->objectName().isEmpty())
            pantalla5->setObjectName(QStringLiteral("pantalla5"));
        pantalla5->resize(878, 478);
        pushButton = new QPushButton(pantalla5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 300, 141, 61));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(pantalla5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 300, 141, 61));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(pantalla5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 0, 75, 23));
        pushButton_5 = new QPushButton(pantalla5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(520, 300, 141, 61));
        pushButton_5->setFont(font);
        pushButton_4 = new QPushButton(pantalla5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(800, 0, 75, 23));
        label_3 = new QLabel(pantalla5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 50, 421, 100));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(47);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_4 = new QLabel(pantalla5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 30, 141, 121));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(pantalla5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 230, 161, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        label_5->setScaledContents(false);

        retranslateUi(pantalla5);

        QMetaObject::connectSlotsByName(pantalla5);
    } // setupUi

    void retranslateUi(QDialog *pantalla5)
    {
        pantalla5->setWindowTitle(QApplication::translate("pantalla5", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pantalla5", "Canci\303\263n 2", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pantalla5", "Canci\303\263n 1", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("pantalla5", "Atr\303\241s", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pantalla5", "Canci\303\263n 3", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pantalla5", "Inicio", Q_NULLPTR));
        label_3->setText(QApplication::translate("pantalla5", "Acoustic Hand", Q_NULLPTR));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("pantalla5", "Elige canci\303\263n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pantalla5: public Ui_pantalla5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA5_H

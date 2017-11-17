/********************************************************************************
** Form generated from reading UI file 'pantalla1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA1_H
#define UI_PANTALLA1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pantalla1
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *pantalla1)
    {
        if (pantalla1->objectName().isEmpty())
            pantalla1->setObjectName(QStringLiteral("pantalla1"));
        pantalla1->resize(878, 478);
        pushButton = new QPushButton(pantalla1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 250, 231, 101));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(18);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(pantalla1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(780, 10, 75, 23));
        label_2 = new QLabel(pantalla1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 50, 421, 100));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(47);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(pantalla1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 30, 141, 121));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_3->setScaledContents(true);

        retranslateUi(pantalla1);

        QMetaObject::connectSlotsByName(pantalla1);
    } // setupUi

    void retranslateUi(QDialog *pantalla1)
    {
        pantalla1->setWindowTitle(QApplication::translate("pantalla1", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pantalla1", "Elegir perfil", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pantalla1", "Atr\303\241s", Q_NULLPTR));
        label_2->setText(QApplication::translate("pantalla1", "Acoustic Hand", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pantalla1: public Ui_pantalla1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA1_H

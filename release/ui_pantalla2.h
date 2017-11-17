/********************************************************************************
** Form generated from reading UI file 'pantalla2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA2_H
#define UI_PANTALLA2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pantalla2
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *pantalla2)
    {
        if (pantalla2->objectName().isEmpty())
            pantalla2->setObjectName(QStringLiteral("pantalla2"));
        pantalla2->resize(878, 478);
        pushButton_3 = new QPushButton(pantalla2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 0, 75, 23));
        pushButton = new QPushButton(pantalla2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 300, 141, 61));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(14);
        pushButton->setFont(font);
        label_2 = new QLabel(pantalla2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 190, 271, 91));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setScaledContents(false);
        pushButton_2 = new QPushButton(pantalla2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 300, 141, 61));
        pushButton_2->setFont(font);
        pushButton_4 = new QPushButton(pantalla2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(800, 0, 75, 23));
        pushButton_5 = new QPushButton(pantalla2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(540, 300, 141, 61));
        pushButton_5->setFont(font);
        label_3 = new QLabel(pantalla2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 50, 421, 100));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(47);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_4 = new QLabel(pantalla2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 30, 141, 121));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_4->setScaledContents(true);

        retranslateUi(pantalla2);

        QMetaObject::connectSlotsByName(pantalla2);
    } // setupUi

    void retranslateUi(QDialog *pantalla2)
    {
        pantalla2->setWindowTitle(QApplication::translate("pantalla2", "Dialog", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("pantalla2", "Atr\303\241s", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pantalla2", "Perfil 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("pantalla2", "Elige perfil", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pantalla2", "Nuevo Perfil", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pantalla2", "Inicio", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pantalla2", "Perfil 2", Q_NULLPTR));
        label_3->setText(QApplication::translate("pantalla2", "Acoustic Hand", Q_NULLPTR));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pantalla2: public Ui_pantalla2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA2_H

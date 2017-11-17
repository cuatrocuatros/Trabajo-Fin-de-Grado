/********************************************************************************
** Form generated from reading UI file 'pantalla0.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA0_H
#define UI_PANTALLA0_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pantalla0
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *pantalla0)
    {
        if (pantalla0->objectName().isEmpty())
            pantalla0->setObjectName(QStringLiteral("pantalla0"));
        pantalla0->resize(878, 478);
        label = new QLabel(pantalla0);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 170, 601, 91));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(pantalla0);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 50, 421, 100));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(47);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(pantalla0);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 30, 141, 121));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_3->setScaledContents(true);
        pushButton_2 = new QPushButton(pantalla0);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 280, 321, 101));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(16);
        pushButton_2->setFont(font2);
        pushButton = new QPushButton(pantalla0);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(440, 280, 321, 101));
        pushButton->setFont(font2);
        pushButton->setAutoDefault(false);

        retranslateUi(pantalla0);

        QMetaObject::connectSlotsByName(pantalla0);
    } // setupUi

    void retranslateUi(QDialog *pantalla0)
    {
        pantalla0->setWindowTitle(QApplication::translate("pantalla0", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("pantalla0", "Bienvenido a Acoustic Hand", Q_NULLPTR));
        label_2->setText(QApplication::translate("pantalla0", "Acoustic Hand", Q_NULLPTR));
        label_3->setText(QString());
        pushButton_2->setText(QApplication::translate("pantalla0", "Iniciar", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pantalla0", "Interacci\303\263n convencional", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pantalla0: public Ui_pantalla0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA0_H

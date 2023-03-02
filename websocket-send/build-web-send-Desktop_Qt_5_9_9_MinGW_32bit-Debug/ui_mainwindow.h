/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_func;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_send;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QPushButton *pushButton_9;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_recv;
    QPushButton *pushButton_2;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(850, 549);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 831, 496));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_id = new QLineEdit(gridLayoutWidget);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_id);

        lineEdit_func = new QLineEdit(gridLayoutWidget);
        lineEdit_func->setObjectName(QStringLiteral("lineEdit_func"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_func);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        plainTextEdit_send = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit_send->setObjectName(QStringLiteral("plainTextEdit_send"));

        formLayout->setWidget(2, QFormLayout::FieldRole, plainTextEdit_send);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_13);


        gridLayout->addLayout(formLayout, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        QFont font1;
        font1.setPointSize(12);
        pushButton_1->setFont(font1);

        horizontalLayout->addWidget(pushButton_1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setFont(font1);

        horizontalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setFont(font1);

        horizontalLayout->addWidget(pushButton_8);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font1);

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setFont(font);

        gridLayout->addWidget(lineEdit_5, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setFrameShape(QFrame::StyledPanel);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_9);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        plainTextEdit_recv = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit_recv->setObjectName(QStringLiteral("plainTextEdit_recv"));

        gridLayout->addWidget(plainTextEdit_recv, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QFont font2;
        font2.setPointSize(13);
        pushButton_2->setFont(font2);

        gridLayout->addWidget(pushButton_2, 7, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setFrameShape(QFrame::StyledPanel);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\233\256\346\240\207", Q_NULLPTR));
        lineEdit_id->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\207\275\346\225\260\345\220\215", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("MainWindow", "\347\273\221\345\256\232", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "\350\247\243\351\231\244\347\273\221\345\256\232", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "\345\276\227\345\210\260\346\211\200\346\234\211\347\233\256\346\240\207ID", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\241\256\350\256\244\345\255\227", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("MainWindow", "7770", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("MainWindow", "ws://localhost:7770", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "PORT", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\345\217\227\345\214\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "URL", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

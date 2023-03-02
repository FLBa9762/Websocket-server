#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWebSockets/QWebSocket>
#include <QMainWindow>
#include <QWebSocketServer>
#include <QJsonObject>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_pushButton_1_released();
        void on_pushButton_2_released();
        void on_pushButton_3_released();
        void Receive_Server_Message(const QString &message);
        void slot_disconnected();
        void on_pushButton_7_released();
        void on_pushButton_8_released();
        void on_pushButton_9_released();

private:
        Ui::MainWindow *ui;
        QWebSocket  *client;
};
#endif // MAINWINDOW_H

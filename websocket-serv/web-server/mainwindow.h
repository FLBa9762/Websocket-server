#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

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
    void on_pushButton_released();
    void on_pushButton_2_released();
    void on_pushButton_3_released();

protected slots:
    void processTextMessage(const QString& message);
    void reply_message();
    void slot_disconnected();
    QJsonArray get_user_id(QString type);

private:
    Ui::MainWindow *ui;
    QList<QWebSocket *> m_clients;
    QWebSocketServer *server;
    int user_num = 0, user_id = 0;
};
#endif // MAINWINDOW_H

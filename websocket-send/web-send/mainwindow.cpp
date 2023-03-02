#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_released()
{
    QTime current_time = QTime::currentTime();
    client = new QWebSocket();
    QString url = ui->lineEdit_3->text();
    client->open(QUrl(url));
    connect(client, &QWebSocket::textMessageReceived, this, &MainWindow::Receive_Server_Message);
    ui->plainTextEdit_recv->appendPlainText(QString(current_time.toString()) + "  " + "点击 发送确认字 确认身份。");
    connect(client, SIGNAL(disconnected()), this, SLOT(slot_disconnected()));
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_1->setDisabled(true);
}


void MainWindow::on_pushButton_2_released()
{

    QJsonObject my_json, params_json;

    QString func_name = ui->lineEdit_func->text();
    QString args = ui->plainTextEdit_send->toPlainText();
    QString target_id = ui->lineEdit_id->text();
    my_json.insert("target_id", target_id);
    my_json.insert("func_name", func_name);
    my_json.insert("func_params", args);

    QJsonDocument jsonDocument(my_json);
    QString jsonString = jsonDocument.toJson();
    client->sendTextMessage(jsonString);
}


void MainWindow::slot_disconnected()
{
    QTime current_time = QTime::currentTime();
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->plainTextEdit_recv->appendPlainText(QString(current_time.toString()) + "  " + "服务器失去连接，请重新建立连接！");
}


void MainWindow::on_pushButton_3_released()
{
    client->sendTextMessage("send_position");
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_3->setDisabled(true);
}


void MainWindow::Receive_Server_Message(const QString &message)
{
    QTime current_time = QTime::currentTime();
    ui->plainTextEdit_recv->appendPlainText(QString(current_time.toString()) + "  " + QString(message));
}

void MainWindow::on_pushButton_7_released()
{
    QTime current_time = QTime::currentTime();
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->plainTextEdit_recv->appendPlainText(QString(current_time.toString()) + "  " + "解除绑定");

    // 清除之前的连接，避免多次收到数据
    client->close();
    client->deleteLater();
    client = nullptr;
}

void MainWindow::on_pushButton_8_released()
{
    client->sendTextMessage("get_target_id");
}

void MainWindow::on_pushButton_9_released()
{
    ui->plainTextEdit_recv->clear();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_3->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    ui->pushButton->setDisabled(true);
    int Port = ui->lineEdit->text().toInt();
    server = new QWebSocketServer("My WebSocket Server", QWebSocketServer::NonSecureMode, this);
    QTime current_time = QTime::currentTime();
    if (!server->listen(QHostAddress::Any, Port)){
        ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     连接端口失败");
    }
    else{
        ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     连接端口成功！");
    }
    QObject::connect(server, &QWebSocketServer::newConnection, this, &MainWindow::reply_message);
    ui->pushButton_3->setEnabled(true);
}

void MainWindow::slot_disconnected()
{
     QTime current_time = QTime::currentTime();
     QObject *senderObject = sender();
     QWebSocket* clientSocket = qobject_cast<QWebSocket*>(sender());
     if (clientSocket == nullptr) {
         // 处理错误情况
         ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     断开连接时有异常发生");
         return;
     }
     if(senderObject->objectName().right(1)=="C"||senderObject->objectName().right(1)=="S"){
         QString exit_id = senderObject->objectName().right(4).left(3);
         ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     用户" + exit_id + " 断开连接。");
     }
     else{
         ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     用户连接失败。");
     }
     m_clients.removeOne(clientSocket);
     user_num--;
}

void MainWindow::reply_message()
{
    QTime current_time = QTime::currentTime();
    user_num++;
    user_id++;


    QWebSocket* my_socket = new QWebSocket();
    my_socket = server->nextPendingConnection();
    my_socket->setObjectName("用户_" + QString::number(user_id).rightJustified(3, '0'));

    connect(my_socket, SIGNAL(textMessageReceived(QString)), this, SLOT(processTextMessage(QString)));
    connect(my_socket, SIGNAL(disconnected()), this, SLOT(slot_disconnected()));

    m_clients.append(my_socket);
    ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     用户" + "请求连接， " + "当前用户数: " + QString::number(user_num));
}

void MainWindow::processTextMessage(const QString& message)
{
    QTime current_time = QTime::currentTime();
    QObject *senderObject = sender();
    if (message == "send_position")
    { 
        senderObject->setObjectName(senderObject->objectName()+="S");
        ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     命名用户为: " + senderObject->objectName());
        for (QWebSocket *socket : m_clients){
            if(socket->objectName().right(1) == "S" and socket->objectName().right(4).left(3) == senderObject->objectName().right(4).left(3))
            {
                socket->sendTextMessage("成功建立连接！");
            }
        }
    }
    else if (message == "cesium_position")
    {
        senderObject->setObjectName(senderObject->objectName()+="C");
        ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     命名用户为: " + senderObject->objectName());
        for (QWebSocket *socket : m_clients){
            if(socket->objectName().right(1) == "C" and socket->objectName().right(4).left(3) == senderObject->objectName().right(4).left(3))
            {
                socket->sendTextMessage("成功建立连接！");
            }
        }
    }
    else if (message == "get_target_id")
    {
        QJsonArray target_data = get_user_id(senderObject->objectName().right(1));
        QJsonObject jsonObject;
        jsonObject["Cesium ID"] = target_data;
        QJsonDocument jsonDoc(jsonObject);
        QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Compact);
        for (QWebSocket *socket : m_clients){
            if(socket->objectName().right(1) == "S" and socket->objectName().right(4).left(3) == senderObject->objectName().right(4).left(3))
            {
                socket->sendTextMessage(QString::fromUtf8(jsonData));
            }
        }
    }
    else
    {
        QString id = senderObject->objectName().right(4);
        if(senderObject->objectName().right(1) == "S")
        {
            QString msg = message;
            QJsonObject doc = QJsonDocument::fromJson(msg.toUtf8()).object();
            QString tar_id = doc.value("target_id").toString();
            if (tar_id == "0")
            {
                for (QWebSocket *socket : m_clients){
                    if(socket->objectName().right(1) == "C")
                    {
                        socket->sendTextMessage(message);
                    }
                }
                ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     接到发送端的消息, id为 " + id + " ，向Cesium广播。");
            }
            else{
                QStringList target_id_list = tar_id.split(" ");
                for (QString& item: target_id_list){
                    int pin = 0;
                    for (QWebSocket *socket : m_clients){
                        if(socket->objectName().right(4).left(3) == item)
                        {
                            socket->sendTextMessage(message);
                            pin = 1;
                        }
                    }
                    if (pin != 0){
                        ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     接到发送端的消息, id为 " + id + " ，向Cesium发送， id为 " + tar_id);
                    }
                    else{
                        ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     id " + item + " 不存在");
                        for (QWebSocket *socket : m_clients){
                            if(socket->objectName().right(4) == senderObject->objectName().right(4))
                            {
                                socket->sendTextMessage("用户" + item + "不存在");
                            }
                        }
                    }
                    }


            }
        }
        else if(senderObject->objectName().right(1) == "C")
        {
            for (QWebSocket *socket : m_clients){
                if(socket->objectName().right(1) == "S")
                {
                    socket->sendTextMessage(message + " id为： " + id);
                }
            }
            ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     接到Cesium的消息, id为 " + id + " ，向发送端广播。");
        }
        else{
            ui->plainTextEdit->appendPlainText(QString(current_time.toString()) + "     收到未知来源, id为 " + id + " 的消息。");
        }


    }
}

void MainWindow::on_pushButton_2_released()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setFocus();
}

QJsonArray MainWindow::get_user_id(QString type)
{

    QJsonArray jsonArray, cesium_list, send_list;
    for (QWebSocket *socket : m_clients){
        if(socket->objectName().right(1) == "S")
        {
            cesium_list.append(socket->objectName().right(4).left(3));
        }
        if(socket->objectName().right(1) == "C")
        {
            send_list.append(socket->objectName().right(4).left(3));
        }
    }

    if (type == "C")
    {
        jsonArray = cesium_list;
    }
    else if (type == "S")
    {
        jsonArray = send_list;
    }
    return  jsonArray;
}

void MainWindow::on_pushButton_3_released()
{
    for (QWebSocket *socket : m_clients){
        socket->sendTextMessage("sever_close");
        socket->close();
    }
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setDisabled(true);
    server->close();
    delete server;
    server = nullptr;
    user_id = 0;
    user_num = 0;
    m_clients.erase(m_clients.begin(), m_clients.end());
    ui->plainTextEdit->appendPlainText("断开服务。");
}

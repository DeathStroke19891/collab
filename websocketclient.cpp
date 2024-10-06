#include "websocketclient.h"
#include <QDebug>

WebSocketClient::WebSocketClient(const QUrl& url, QObject* parent)
    : QObject(parent) {
    connect(&webSocket, &QWebSocket::connected, this, &WebSocketClient::onConnected);
    connect(&webSocket, &QWebSocket::textMessageReceived, this, &WebSocketClient::onMessageReceived);
    connect(&webSocket, &QWebSocket::errorOccurred, this, &WebSocketClient::onError);

    webSocket.open(url);
}

void WebSocketClient::onConnected() {
    qDebug() << "Connected to server";
    webSocket.sendTextMessage("Hello from Qt client!");
}

void WebSocketClient::onMessageReceived(const QString& message) {
    qDebug() << "Message received from server:" << message;

    messageLog.concatenate(message);

    qDebug() << "Current Message Log:" << messageLog.substring(0, messageLog.substring(0, 100).length());
}

void WebSocketClient::onError(QAbstractSocket::SocketError error) {
    qDebug() << "WebSocket error:" << error;
}

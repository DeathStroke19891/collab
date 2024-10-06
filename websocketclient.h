#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QWebSocket>
#include "rope.h" // Include the rope header

class WebSocketClient : public QObject {
    Q_OBJECT

public:
    explicit WebSocketClient(const QUrl& url, QObject* parent = nullptr);

private slots:
    void onConnected();
    void onMessageReceived(const QString& message);
    void onError(QAbstractSocket::SocketError error);

private:
    QWebSocket webSocket;
    Rope messageLog; // Rope to hold concatenated messages
};

#endif // WEBSOCKETCLIENT_H

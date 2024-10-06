#ifndef SHAREDTEXTMODEL_H
#define SHAREDTEXTMODEL_H

#include <QObject>
#include <QString>

class SharedTextModel : public QObject {
    Q_OBJECT
public:
    explicit SharedTextModel(QObject* parent = nullptr);

    void setText(const QString& newText);
    QString getText() const;

signals:
    void textChanged(const QString& newText);

private:
    QString text;
};

#endif // SHAREDTEXTMODEL_H

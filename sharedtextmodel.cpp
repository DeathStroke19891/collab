#include "sharedtextmodel.h"

SharedTextModel::SharedTextModel(QObject* parent) : QObject(parent) {}

void SharedTextModel::setText(const QString& newText) {
    if (text != newText) {
        text = newText;
        emit textChanged(text);
    }
}

QString SharedTextModel::getText() const {
    return text;
}

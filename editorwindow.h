#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include "sharedtextmodel.h"

class EditorWindow : public QWidget {
    Q_OBJECT
public:
    explicit EditorWindow(SharedTextModel* model, QWidget* parent = nullptr);

private slots:
    void onTextChanged();
    void updateText(const QString& newText);

private:
    QTextEdit* textEdit;
    SharedTextModel* sharedModel;
};

#endif // EDITORWINDOW_H

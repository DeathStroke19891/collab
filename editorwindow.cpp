#include "editorwindow.h"
#include <QVBoxLayout>

EditorWindow::EditorWindow(SharedTextModel* model, QWidget* parent)
    : QWidget(parent), sharedModel(model) {
    textEdit = new QTextEdit(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    setLayout(layout);

    // Connect the text edit to the shared model
    connect(textEdit, &QTextEdit::textChanged, this, &EditorWindow::onTextChanged);
    connect(sharedModel, &SharedTextModel::textChanged, this, &EditorWindow::updateText);
}

void EditorWindow::onTextChanged() {
    sharedModel->setText(textEdit->toPlainText());
}

void EditorWindow::updateText(const QString& newText) {
    if (textEdit->toPlainText() != newText) {
        textEdit->setPlainText(newText);
    }
}

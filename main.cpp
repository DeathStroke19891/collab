#include <QApplication>
#include "sharedtextmodel.h"
#include "editorwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SharedTextModel* sharedModel = new SharedTextModel();

    EditorWindow* editor1 = new EditorWindow(sharedModel);
    editor1->setWindowTitle("Editor 1");
    editor1->resize(400, 300);
    editor1->show();

    EditorWindow* editor2 = new EditorWindow(sharedModel);
    editor2->setWindowTitle("Editor 2");
    editor2->resize(400, 300);
    editor2->show();

    return app.exec();
}

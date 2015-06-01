#include <QApplication>
#include <TFrame.h>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    TFrame* frame = new TFrame;
    frame->show();
    return app.exec();
}


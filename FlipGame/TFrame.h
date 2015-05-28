#include <QFrame>
#include <QGridLayout>
#include <QWidget>
#include <TTabuleiro.h>

class TFrame : public QFrame {

QGridLayout* layout;
TTabuleiro* tabuleiro;

public:
    TFrame() {
        QWidget::showMaximized();
        setFrameStyle(QFrame::Box| QFrame::Sunken);
        QString titulo("Flip - Programação Gráfica I - Diovani Bernardi da Motta");
        setWindowTitle(titulo);
        setLineWidth(4);
        setMouseTracking(true);
        setFocus();
        layout = new QGridLayout();
        setLayout(layout);
    }

    void paintEvent(QPaintEvent* event){
        QFrame::paintEvent(event);
        //QPainter painter(this);

    }
};




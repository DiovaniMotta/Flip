#include <QFrame>
#include <QGridLayout>
#include <QWidget>
#include <TTabuleiro.h>
#include <QVector>
#include <QPainter>

class TFrame : public QFrame {

  QGridLayout* layout;
  TTabuleiro* tabuleiro;
  QVector<TPonto> l;

public:
    TFrame() {
        QWidget::showMaximized();
        setFrameStyle(QFrame::Box);
        QString titulo("Flip - Programação Gráfica I - Diovani Bernardi da Motta");
        setWindowTitle(titulo);
        setLineWidth(4);
        setMouseTracking(true);
        setFocus();
        tabuleiro = new TTabuleiro;
    }

    void configurarTabuleiro(){
        tabuleiro->setAltura(this->height());
        tabuleiro->setLargura(this->width());
        tabuleiro->tabuleiro(TPonto::dimensao);
        QVector<TPonto> aux = tabuleiro->getPontos();
        //somente será alterado o numero de pontos na tela se o tamnho da lista for diferente
        if(l.size() != aux.size())
        {
            l = aux;
        }
    }

    void paintEvent(QPaintEvent* event){
        QFrame::paintEvent(event);
        QPainter painter(this);
        configurarTabuleiro();
        for(int x=0; x<l.size(); x++){
            TPonto p = l.at(x);
            painter.setBrush(p.getCorFundo());
            painter.setPen(p.getCorBorda());
            painter.drawRect(p.getX(),p.getY(),p.getAltura(),p.getLargura());
        }
    }
};




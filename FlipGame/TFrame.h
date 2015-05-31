#include <QFrame>
#include <QGridLayout>
#include <QWidget>
#include <TTabuleiro.h>
#include <QVector>
#include <QPainter>
#include <QException>

#ifndef TFRAME
#define TFRAME

class TFrame : public QFrame {

  TTabuleiro* tabuleiro;
  QVector<TPonto> l;

public:

    TFrame() {
        try
        {
            setMinimumSize(800,600);
            setFrameStyle(QFrame::Box);
            QString titulo("Flip - Programação Gráfica I - Diovani Bernardi da Motta");
            setWindowTitle(titulo);
            setLineWidth(4);
            setMouseTracking(true);
            setFocus();
            tabuleiro = new TTabuleiro;
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    /**
     * Método responsavel por configurar o tabuleiro de acordo com as dimensões da tela
     * @brief configurarTabuleiro
     */
    void configurarTabuleiro(){
        try
        {
            tabuleiro->setAltura(this->height());
            tabuleiro->setLargura(this->width());
            tabuleiro->tabuleiro(TPonto::dimensao);
            tabuleiro->configurarTabuleiro(1);
            QVector<TPonto> aux = tabuleiro->getPontos();
            //somente será alterado o numero de pontos na tela se o tamnho da lista for diferente
            if(l.size() != aux.size())
            {
                l = aux;
            }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    void resizeEvent(QResizeEvent* event){
        QFrame::resizeEvent(event);
        configurarTabuleiro();
    }

    void paintEvent(QPaintEvent* event){
        try
        {
            QFrame::paintEvent(event);
            QPainter painter(this);
            for(int x=0; x<l.size(); x++){
                TPonto p = l.at(x);
                painter.setBrush(p.getCorFundo());
                painter.setPen(p.getCorBorda());
                painter.drawRect(p.getX(),p.getY(),p.getAltura(),p.getLargura());
            }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }
};

#endif // TFRAME



#include <TFrame.h>

TFrame::TFrame () {
    setMinimumSize(800,600);
    setFrameStyle(QFrame::Box);
    QString titulo("Flip - Programação Gráfica I - Diovani Bernardi da Motta");
    setWindowTitle(titulo);
    setLineWidth(4);
    setMouseTracking(true);
    setFocus();
    tabuleiro = new TTabuleiro;
    player1 = new TPlayer;
    player1->setNivel(TPlayer::NIVEL2);
    player1->setPosX(3);
    player1->setPosY(5);
    tabuleiro->setPlayer1(player1);
}

void TFrame::resizeEvent(QResizeEvent* event){
    QFrame::resizeEvent(event);
    _h_sz = this->height()*0.05;
    _w_sz = this->width()*0.05;
}

void TFrame::paintEvent(QPaintEvent* event){
    QFrame::paintEvent(event);
    QPainter painter(this);
    for(int x=0;x <TTabuleiro::DIMENSAO;x++){
        for(int y=0; y<TTabuleiro::DIMENSAO; y++){
            TPonto ponto = tabuleiro->nivel(x,y);
            painter.setPen(ponto.getCorBorda());
            painter.setBrush(ponto.getCorFundo());
            painter.drawRect((x * _w_sz),(y*_h_sz),_w_sz,_h_sz);
        }
     }
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawRect((player1->getPosX() * _w_sz),(player1->getPosY() * _h_sz),_w_sz,_h_sz);
 }

void TFrame::keyPressEvent(QKeyEvent* event){
  QFrame::keyPressEvent(event);
  int acima =0;
  int abaixo = 0;
  int esquerda = 0;
  int direita = 0;

  switch(event->key()){
     case Qt::Key_Up:
        acima = player1->getPosY() - 2;
        player1->setPosY(acima);
        colisao->dimensaoJanela(player1);
        player1->setUltimaPosicao(event->key());
        repaint();
        break;
     case Qt::Key_Down:
        abaixo = player1->getPosY() + 2;
        player1->setPosY(abaixo);
        player1->setUltimaPosicao(event->key());
        colisao->dimensaoJanela(player1);
        repaint();
        break;
     case Qt::Key_Left:
        esquerda = player1->getPosX() - 2;
        player1->setPosX(esquerda);
        player1->setUltimaPosicao(event->key());
        colisao->dimensaoJanela(player1);
        repaint();
        break;
     case Qt::Key_Right:
        direita = player1->getPosX() + 2;
        player1->setPosX(direita);
        player1->setUltimaPosicao(event->key());
        colisao->dimensaoJanela(player1);
        repaint();
        break;
  }
}

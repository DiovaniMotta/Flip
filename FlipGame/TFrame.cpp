#include <TFrame.h>

/**
 * @brief TFrame::TFrame construtor da classe
 */
TFrame::TFrame () {
    setMinimumSize(800,600);
    setFrameStyle(QFrame::Box);
    QString titulo("FlipGame - Programação Gráfica I - Diovani Bernardi da Motta");
    setWindowTitle(titulo);
    setLineWidth(4);
    setMouseTracking(true);
    setFocus();
    tabuleiro = new TTabuleiro;
    tabuleiro->posicionar(TPlayer::NIVEL5);
    player1 = tabuleiro->getPlayer1();
    player2 = tabuleiro->getPlayer2();
    colisao = new TColisao;
    colisao->setTabuleiro(tabuleiro);
    QTimer::singleShot((TIMER/FPS),this,SLOT(iniciar()));
}

/**
 * @brief TFrame::resizeEvent evento de redimensionamento da tela
 * @param event
 */
void TFrame::resizeEvent(QResizeEvent* event){
    QFrame::resizeEvent(event);
    colisao->setLargura(this->width());
    colisao->setAltura(this->height());
    _h_sz = this->height()*0.05;
    _w_sz = this->width()*0.05;
    player1->setLargura(_w_sz);
    player1->setAltura(_h_sz);
    player2->setLargura(_w_sz);
    player2->setAltura(_h_sz);
}

/**
 * @brief TFrame::paintEvent evento de repintura da tela
 * @param event
 */
void TFrame::paintEvent(QPaintEvent* event){
    QFrame::paintEvent(event);
    QPainter painter(this);
    for(int x=0;x <TTabuleiro::DIMENSAO;x++){
        for(int y=0; y<TTabuleiro::DIMENSAO; y++){
            TPonto ponto = tabuleiro->nivel(x,y);
            painter.setPen(ponto.getCorBorda());
            painter.setBrush(ponto.getCorFundo());
            painter.drawRect((x * _w_sz),(y*_h_sz),_w_sz,_h_sz);
            ponto.setX((x * _w_sz));
            ponto.setY((y*_h_sz));
            ponto.setHeight(_h_sz);
            ponto.setWidht(_w_sz);
        }
     }
    //desenho do player 1;
    painter.setPen(player1->getBorda());
    painter.setBrush(player1->getFundo());
    player1->setX((player1->getPosX() * _w_sz));
    player1->setY((player1->getPosY() * _h_sz));
    painter.drawRect((player1->getPosX() * _w_sz),(player1->getPosY() * _h_sz),_w_sz,_h_sz);
    // desenho o disparo do player1
    this->disparo(player1,&painter);
    // desenho do player 2;
    painter.setPen(player2->getBorda());
    painter.setBrush(player2->getFundo());
    player2->setX((player2->getPosX() * _w_sz));
    player2->setY((player2->getPosY() * _h_sz));
    painter.drawRect((player2->getPosX() * _w_sz),(player2->getPosY() * _h_sz),_w_sz,_h_sz);
    //desenho o disparo do player2
    this->disparo(player2,&painter);
 }

/**
 * @brief TFrame::keyPressEvent evento acionado ao pressionar uma tecla do teclado
 * @param event
 */
void TFrame::keyPressEvent(QKeyEvent* event){
  QFrame::keyPressEvent(event);
  int acima =0;
  int abaixo = 0;
  int esquerda = 0;
  int direita = 0;
  switch(event->key()){
     //comandos de movimentação do player2
     case Qt::Key_Up:
        acima = player2->getPosY() - TPlayer::SALTOS;
        player2->setPosY(acima);
        player2->setUltimaPosicao(event->key());
        colisao->colisao(player2);
        break;
     case Qt::Key_Down:
        abaixo = player2->getPosY() + TPlayer::SALTOS;
        player2->setPosY(abaixo);
        player2->setUltimaPosicao(event->key());
        colisao->colisao(player2);
        break;
     case Qt::Key_Left:
        esquerda = player2->getPosX() - TPlayer::SALTOS;
        player2->setPosX(esquerda);
        player2->setUltimaPosicao(event->key());
        colisao->colisao(player2);
        break;
     case Qt::Key_Right:
        direita = player2->getPosX() + TPlayer::SALTOS;
        player2->setPosX(direita);
        player2->setUltimaPosicao(event->key());
        colisao->colisao(player2);
        break;
     case Qt::Key_End:
        player2->disparo();
        break;
     //comandos de movimentação do player1
     case Qt::Key_W:
        acima = player1->getPosY() - TPlayer::SALTOS;
        player1->setPosY(acima);
        player1->setUltimaPosicao(event->key());
        colisao->colisao(player1);
        break;
     case Qt::Key_S:
        abaixo = player1->getPosY() + TPlayer::SALTOS;
        player1->setPosY(abaixo);
        player1->setUltimaPosicao(event->key());
        colisao->colisao(player1);
        break;
     case Qt::Key_A:
        esquerda = player1->getPosX() - TPlayer::SALTOS;
        player1->setPosX(esquerda);
        player1->setUltimaPosicao(event->key());
        colisao->colisao(player1);
        break;
     case Qt::Key_D:
        direita = player1->getPosX() + TPlayer::SALTOS;
        player1->setPosX(direita);
        player1->setUltimaPosicao(event->key());
        colisao->colisao(player1);
        break;
     case Qt::Key_Space:
        player1->disparo();
        break;
    }
}

/**
 * @brief TFrame::iniciar slot tratador do evento de pintura de tela
 */
void TFrame::iniciar(){
    this->repaint();
    QTimer::singleShot((TIMER/FPS),this,SLOT(iniciar()));
}

/**
 * @brief TFrame::parar slot tratador do evento de paralização de pintura de tela
 */
void TFrame::parar(){

}

void TFrame::disparo(TPlayer *player,QPainter* painter){
    //se o projetil foi disparado pelo player
    if(player->getProjetil()->isAtivo()){
        int acima = 0;
        int abaixo = 0;
        int esqueda  = 0;
        int direita = 0;
        //verifico qual foi a ultima direção tomanda
        switch(player->getProjetil()->getUltimaPosicao()){
            case Qt::Key_Up:
            case Qt::Key_W:
                qDebug()<<"Posicao player ->";
                qDebug()<<player->getPosX();
                qDebug()<<player->getPosY();
                qDebug()<<"Posicao projetil ->";
                qDebug()<<player->getProjetil()->getPosX();
                qDebug()<<player->getProjetil()->getPosY();
                player->getProjetil()->deslocamento(_h_sz);
                acima = (player->getProjetil()->getY() -  player->getProjetil()->DESLOCAMENTO);
                player->getProjetil()->setY(acima);
                painter->drawRect(player->getProjetil()->getX(),player->getProjetil()-> getY(),
                                  player->getProjetil()->getLargura(),player->getProjetil()->getAltura());
                colisao->colisao(player->getProjetil());
                break;
            case Qt::Key_Down:
            case Qt::Key_S:
                player->getProjetil()->deslocamento(_h_sz);
                abaixo = (player->getProjetil()->getY() + player->getProjetil()->DESLOCAMENTO);
                player->getProjetil()->setY(abaixo);
                painter->drawRect(player->getProjetil()->getX(),player->getProjetil()-> getY(),
                                  player->getProjetil()->getLargura(),player->getProjetil()->getAltura());
                colisao->colisao(player->getProjetil());
                break;
            case Qt::Key_Left:
            case Qt::Key_A:
                qDebug()<<"Direcao Esquerda->";
                qDebug()<<"Posicao player ->";
                qDebug()<<player->getPosX();
                qDebug()<<player->getPosY();
                qDebug()<<"Posicao projetil ->";
                qDebug()<<player->getProjetil()->getPosX();
                qDebug()<<player->getProjetil()->getPosY();
                player->getProjetil()->deslocamento(_w_sz);
                esqueda = (player->getProjetil()->getX() - player->getProjetil()->DESLOCAMENTO);
                player->getProjetil()->setX(esqueda);
                painter->drawRect(player->getProjetil()->getX(),player->getProjetil()-> getY(),
                                  player->getProjetil()->getLargura(),player->getProjetil()->getAltura());
                colisao->colisao(player->getProjetil());
                break;
            case Qt::Key_Right:
            case Qt::Key_D:
                player->getProjetil()->deslocamento(_w_sz);
                direita = (player->getProjetil()->getX() + player->getProjetil()->DESLOCAMENTO);
                player->getProjetil()->setX(direita);
                painter->drawRect(player->getProjetil()->getX(),player->getProjetil()-> getY(),
                                  player->getProjetil()->getLargura(),player->getProjetil()->getAltura());
                colisao->colisao(player->getProjetil());
                break;
            default:
                player->getProjetil()->deslocamento(_h_sz);
                esqueda = (player->getProjetil()->getX() - player->getProjetil()->DESLOCAMENTO);
                player->getProjetil()->setX(esqueda);
                painter->drawRect(player->getProjetil()->getX(),player->getProjetil()-> getY(),
                                  player->getProjetil()->getLargura(),player->getProjetil()->getAltura());
                colisao->colisao(player->getProjetil());
                break;
        }
    }
    if(player->getProjetil()->getX() < 0){
        player->getProjetil()->reiniciar();
    }
    if(player->getProjetil()->getY() < 0){
       player->getProjetil()->reiniciar();
    }
}

void TFrame::disparo(){

}

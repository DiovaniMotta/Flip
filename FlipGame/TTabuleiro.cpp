#include <TTabuleiro.h>

TTabuleiro::TTabuleiro(){
    this->player1 = new TPlayer();
    this->player2 = new TPlayer();
    this->nivel1 = new TNivel1();
    this->nivel2 = new TNivel2();
}

TTabuleiro::TTabuleiro(TPlayer* player1,TPlayer* player2){
    this->player1 = player1;
    this->player2 = player2;
    this->nivel1 = new TNivel1();
    this->nivel2 = new TNivel2();
}

TTabuleiro::~TTabuleiro(){
    delete player1;
    delete player2;
    delete nivel1;
    delete nivel2;
}

void TTabuleiro::setPlayer1(TPlayer* player1){
    this->player1 = player1;
}

TPlayer* TTabuleiro::getPlayer1(){
    return this->player1;
}

void TTabuleiro::setPlayer2(TPlayer* player2){
    this->player2 = player2;
}

TPlayer* TTabuleiro::getPlayer2(){
    return this->player2;
}

TNivel1* TTabuleiro::getNivel1(){
    return this->nivel1;
}

void TTabuleiro::setNivel1(TNivel1 *nivel){
    this->nivel1 = nivel;
}

TNivel2* TTabuleiro::getNivel2(){
    return this->nivel2;
}

void TTabuleiro::setNivel2(TNivel2 *nivel){
    this->nivel2 = nivel;
}
/**
 * @brief TTabuleiro::nivel retorna o ponto que será desenhado na tela
 * @param x a posicao x iterada na matriz
 * @param y a posicao y iterada na matriz
 * @return um objeto contendo as cores de pintura da tela
 */
TPonto TTabuleiro::nivel(int x,int y){
   switch(player1->getNivel()){
        case TPlayer::NIVEL1:
            return nivel1->nivel(x,y);
        case TPlayer::NIVEL2:
            return nivel2->nivel(x,y);
        case TPlayer::NIVEL3:
            return nivel1->nivel(x,y);
        case TPlayer::NIVEL4:
            return nivel1->nivel(x,y);
        case TPlayer::NIVEL5:
            return nivel1->nivel(x,y);
   }
   return nivel(x,y);
}

void TTabuleiro::reposicionar(TPlayer *player1){
    int acima =0;
    int abaixo = 0;
    int esquerda = 0;
    int direita = 0;
    switch(player1->getUltimaPosicao()){
        case Qt::Key_Up:
            acima = player1->getPosY() + TPlayer::SALTOS;
            player1->setPosY(acima);
            break;
        case Qt::Key_Down:
            abaixo = player1->getPosY() - TPlayer::SALTOS;
            player1->setPosY(abaixo);
            break;
        case Qt::Key_Left:
            esquerda = player1->getPosX() + TPlayer::SALTOS;
            player1->setPosX(esquerda);
            break;
        case Qt::Key_Right:
            direita = player1->getPosX() - TPlayer::SALTOS;
            player1->setPosX(direita);
            break;
    }
}

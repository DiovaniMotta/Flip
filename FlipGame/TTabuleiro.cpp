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

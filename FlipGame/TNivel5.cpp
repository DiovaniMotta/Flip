#include <TNivel5.h>

TNivel5::TNivel5(){
    inicializar();
    configurar();
    player1 = new TPlayer;
    player2 = new TPlayer;
}

TNivel5::~TNivel5(){
    delete player1;
    delete player2;
}

void TNivel5::addPonto(int x, int y, TPonto ponto){
    lista[x][y] = ponto;
}

TPonto TNivel5::nivel(int x, int y){
    return lista[x][y];
}

void TNivel5::configurar(){
    for(int x=0; x < DIMENSAO; x++){
        for(int y=0; y<DIMENSAO; y++){
            if(x < (DIMENSAO/2)){
               TColor::branco(&lista[x][y]);
            }else{
               TColor::preto(&lista[x][y]);
            }
            if((x > 4) && (x < 15)){
                if((y < 3)){
                   TColor::cinza(&lista[x][y]);
                }
            }
            if((y > 4) && (y < 15)){
                if((x < 3)){
                   TColor::cinza(&lista[x][y]);
                }
            }
            if((x > 4) && (x < 15)){
                if((y > 16)){
                   TColor::cinza(&lista[x][y]);
                }
            }
            if((y > 4) && (y < 15)){
                if((x > 16)){
                   TColor::cinza(&lista[x][y]);
                }
            }
            if((y > 6) && (y < 13)){
                if((x > 6) && (x < 13)){
                   TColor::cinza(&lista[x][y]);
                }
            }
        }
    }
}

void TNivel5::inicializar(){
    for(int x=0; x<DIMENSAO; x++){
        for(int y=0; y<DIMENSAO; y++){
            TPonto ponto;
            ponto.setCorBorda(Qt::white);
            ponto.setCorFundo(Qt::black);
            lista[x][y] = ponto;
        }
    }
}

void TNivel5::players(){
    player1->setNivel(TPlayer::NIVEL5);
    player1->setPosX(5);
    player1->setPosY(5);
    player1->setBorda(Qt::black);
    player1->setFundo(Qt::white);

    player2->setNivel(TPlayer::NIVEL5);
    player2->setPosX(13);
    player2->setPosY(13);
    player2->setBorda(Qt::white);
    player2->setFundo(Qt::black);
}

void TNivel5::setPlayer1(TPlayer *player1){
    this->player1 = player1;
}

void TNivel5::setPlayer2(TPlayer *player2){
    this->player2 = player2;
}

TPlayer* TNivel5::getPlayer1(){
    return this->player1;
}

TPlayer* TNivel5::getPlayer2(){
    return this->player2;
}
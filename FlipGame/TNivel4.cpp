#include <TNivel4.h>

TNivel4::TNivel4(){
    inicializar();
    configurar();
    player1 = new TPlayer;
    player2 = new TPlayer;
}

TNivel4::~TNivel4(){
    delete player1;
    delete player2;
}

void TNivel4::addPonto(int x, int y, TPonto ponto){
    lista[x][y] = ponto;
}

TPonto TNivel4::nivel(int x, int y){
    return lista[x][y];
}

void TNivel4::configurar(){
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

void TNivel4::inicializar(){
    for(int x=0; x<20; x++){
        for(int y=0; y< 20; y++){
            TPonto ponto;
            ponto.setCorBorda(Qt::white);
            ponto.setCorFundo(Qt::black);
            lista[x][y] = ponto;
        }
    }
}

void TNivel4::players(){
    player2->setNivel(TPlayer::NIVEL4);
    player2->setPosX(17);
    player2->setPosY(2);
    player2->setBorda(Qt::black);
    player2->setFundo(Qt::white);

    player1->setNivel(TPlayer::NIVEL4);
    player1->setPosX(2);
    player1->setPosY(17);
    player1->setBorda(Qt::white);
    player1->setFundo(Qt::black);
}

/**
 * @brief TNivel1::zerar metodo responsavel por zerar o tabuleiro quando um player vence
 * @param player o player que foi derrotado
 */
void TNivel4::zerar(TPlayer *player){
    for(int x=0; x<DIMENSAO; x++){
        for(int y=0; y<DIMENSAO; y++){
            TPonto ponto = lista[x][y];
            ponto.setCorBorda(player->getBorda());
            ponto.setCorFundo(player->getFundo());
            lista[x][y] = ponto;
        }
    }
}

void TNivel4::setPlayer1(TPlayer *player1){
    this->player1 = player1;
}

void TNivel4::setPlayer2(TPlayer *player2){
    this->player2 = player2;
}

TPlayer* TNivel4::getPlayer1(){
    return this->player1;
}

TPlayer* TNivel4::getPlayer2(){
    return this->player2;
}

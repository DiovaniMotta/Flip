#include <TNivel3.h>

TNivel3::TNivel3(){
    inicializar();
    configurar();
    player1 = new TPlayer;
    player2 = new TPlayer;
}

TNivel3::~TNivel3(){
    delete player1;
    delete player2;
}

void TNivel3::configurar(){
    for(int x=0; x < TUtils::DIMENSAO; x++){
        for(int y=0; y<TUtils::DIMENSAO; y++){
            if(x < (TUtils::DIMENSAO/2)){
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
        }
    }
}

void TNivel3::inicializar(){
    for(int x=0; x<TUtils::DIMENSAO; x++){
        for(int y=0; y< TUtils::DIMENSAO; y++){
            TPonto ponto;
            ponto.setCorBorda(Qt::white);
            ponto.setCorFundo(Qt::black);
            lista[x][y] = ponto;
        }
    }
}

TPonto TNivel3::nivel(int x, int y){
    return lista[x][y];
}

void TNivel3::addPonto(int x, int y, TPonto ponto){
    lista[x][y] = ponto;
}

void TNivel3::players(){

    player2->setNivel(TPlayer::NIVEL3);
    player2->setPosX(16);
    player2->setPosY(17);
    player2->setBorda(Qt::black);
    player2->setFundo(Qt::white);

    player1->setNivel(TPlayer::NIVEL3);
    player1->setPosX(3);
    player1->setPosY(2);
    player1->setBorda(Qt::white);
    player1->setFundo(Qt::black);
}

/**
 * @brief TNivel1::zerar metodo responsavel por zerar o tabuleiro quando um player vence
 * @param player o player que foi derrotado
 */
void TNivel3::zerar(TPlayer *player){
    for(int x=0; x<TUtils::DIMENSAO; x++){
        for(int y=0; y<TUtils::DIMENSAO; y++){
            TPonto ponto = lista[x][y];
            ponto.setCorBorda(player->getBorda());
            ponto.setCorFundo(player->getFundo());
            ponto.setX(x);
            ponto.setY(y);
            lista[x][y] = ponto;
        }
    }
}

void TNivel3::setPlayer1(TPlayer *player1){
    this->player1 = player1;
}

void TNivel3::setPlayer2(TPlayer *player2){
    this->player2 = player2;
}

TPlayer* TNivel3::getPlayer1(){
    return this->player1;
}

TPlayer* TNivel3::getPlayer2(){
    return this->player2;
}

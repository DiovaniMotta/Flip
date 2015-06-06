#include <TNivel2.h>

TNivel2::TNivel2 () {
  inicializar();
  configurar();
  player1 = new TPlayer;
  player2 = new TPlayer;
}

TNivel2::~TNivel2(){
    delete player1;
    delete player2;
}

void TNivel2::inicializar(){
    for(int x=0; x<DIMENSAO; x++){
        for(int y=0; y< DIMENSAO; y++){
            TPonto ponto;
            ponto.setCorBorda(Qt::white);
            ponto.setCorFundo(Qt::black);
            lista[x][y] = ponto;
        }
    }
}

TPonto TNivel2::nivel(int x, int y){
    return lista[x][y];
}

void TNivel2::addPonto(int x, int y,TPonto ponto) {
    lista[x][y] = ponto;
}

void TNivel2::configurar(){
    for(int x=0; x<DIMENSAO; x++){
      for(int y=0; y<DIMENSAO; y++){
          int fim = (DIMENSAO - 2);
          if(x < (DIMENSAO/2)){
             TColor::branco(&lista[x][y]);
          }else{
             TColor::preto(&lista[x][y]);
          }
          if((y < 2) || (y >= fim)){
             TColor::cinza(&lista[x][y]);
          }
          if((x < 2) || (x >= fim)){
             TColor::cinza(&lista[x][y]);
          }
          if((x > 3) && (x < 8)){
              if((y > 3) && (y < 8)){
                TColor::preto(&lista[x][y]);
              }
          }
          if((x > 11) && (x < 16)){
              if((y > 11) && (y < 16)){
                TColor::branco(&lista[x][y]);
              }
          }
        }
    }
}

void TNivel2::players(){
    player1->setNivel(TPlayer::NIVEL2);
    player1->setPosX(5);
    player1->setPosY(5);
    player1->setBorda(Qt::black);
    player1->setFundo(Qt::white);

    player2->setNivel(TPlayer::NIVEL2);
    player2->setPosX(13);
    player2->setPosY(13);
    player2->setBorda(Qt::white);
    player2->setFundo(Qt::black);
}

/**
 * @brief TNivel1::zerar metodo responsavel por zerar o tabuleiro quando um player vence
 * @param player o player que foi derrotado
 */
void TNivel2::zerar(TPlayer *player){
    for(int x=0; x<DIMENSAO; x++){
        for(int y=0; y<DIMENSAO; y++){
            TPonto ponto = lista[x][y];
            ponto.setCorBorda(player->getBorda());
            ponto.setCorFundo(player->getFundo());
            lista[x][y] = ponto;
        }
    }
}

void TNivel2::setPlayer1(TPlayer *player1){
    this->player1 = player1;
}

void TNivel2::setPlayer2(TPlayer *player2){
    this->player2 = player2;
}

TPlayer* TNivel2::getPlayer1(){
    return this->player1;
}

TPlayer* TNivel2::getPlayer2(){
    return this->player2;
}


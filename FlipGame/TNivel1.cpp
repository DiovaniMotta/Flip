#include <TNivel1.h>

TNivel1::TNivel1 () {
    inicializar();
    configurar();
    this->player1 = new TPlayer;
    this->player2 = new TPlayer;
}

TNivel1::~TNivel1(){
    delete player1;
    delete player2;
}

void TNivel1::inicializar(){
    for(int x=0; x<DIMENSAO; x++){
        for(int y=0; y<DIMENSAO; y++){
            TPonto ponto;
            ponto.setCorBorda(Qt::white);
            ponto.setCorFundo(Qt::black);
            lista[x][y] = ponto;
        }
    }
}

TPonto TNivel1::nivel(int x, int y){
    return lista[x][y];
}

void TNivel1::addPonto(int x, int y,TPonto ponto) {
    lista[x][y] = ponto;
}

void TNivel1::configurar(){
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
          if((x > 7) && (x < 12)){
              if((y > 7) && (y < 12)){
                TColor::cinza(&lista[x][y]);
              }
          }
       }
    }
}
/**
 * @brief TNivel1::players configura a posicao de inicio dos players
 */
void TNivel1::players(){

    player1->setNivel(TPlayer::NIVEL1);
    player1->setPosX(5);
    player1->setPosY(10);
    player1->setBorda(Qt::white);
    player1->setFundo(Qt::black);

    player2->setNivel(TPlayer::NIVEL1);
    player2->setPosX(15);
    player2->setPosY(10);
    player2->setBorda(Qt::black);
    player2->setFundo(Qt::white);

}
/**
 * @brief TNivel1::zerar metodo responsavel por zerar o tabuleiro quando um player vence
 * @param player o player que foi derrotado
 */
void TNivel1::zerar(TPlayer *player){
    for(int x=0; x<DIMENSAO; x++){
        for(int y=0; y<DIMENSAO; y++){
            TPonto ponto = lista[x][y];
            ponto.setCorBorda(player->getBorda());
            ponto.setCorFundo(player->getFundo());
            lista[x][y] = ponto;
        }
    }
}

void TNivel1::setPlayer1(TPlayer *player1){
    this->player1 = player1;
}

void TNivel1::setPlayer2(TPlayer *player2){
    this->player2 = player2;
}

TPlayer* TNivel1::getPlayer1(){
    return this->player1;
}

TPlayer* TNivel1::getPlayer2(){
    return this->player2;
}

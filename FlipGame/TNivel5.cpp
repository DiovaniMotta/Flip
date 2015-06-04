#include <TNivel5.h>

TNivel5::TNivel5(){
    inicializar();
    configurar();
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
    for(int x=0; x<DIMENSAO; x++){
      for(int y=0; y<DIMENSAO; y++){
          int fim = (DIMENSAO - 2);
          if(x < 10){
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

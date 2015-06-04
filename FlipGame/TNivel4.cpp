#include <TNivel4.h>

TNivel4::TNivel4(){
    inicializar();
    configurar();
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

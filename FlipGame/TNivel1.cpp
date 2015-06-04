#include <TNivel1.h>

void TNivel1::inicializar(){
    for(int x=0; x<20; x++){
        for(int y=0; y< 20; y++){
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

TNivel1::TNivel1 () {
    inicializar();
    configurar();
}

void TNivel1::configurar(){
    for(int x=0; x<20; x++){
      for(int y=0; y<20; y++){
          int fim = (20 - 2);
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
          if((x > 7) && (x < 12)){
              if((y > 7) && (y < 12)){
                TColor::cinza(&lista[x][y]);
              }
          }
       }
    }
}

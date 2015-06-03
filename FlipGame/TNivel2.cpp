/*
#include <TNivel2.h>
#include <TNivel.h>

TNivel2::TNivel2 () {
  inicializar();
  configurar();
}

void TNivel2::configurar(){
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
*/

#pragma once
#include <TNivel.h>
#include <TTabuleiro.h>
#include <TColor.h>

#ifndef TNIVEL1
#define TNIVEL1

class TNivel1 : public TNivel {

protected:
    void configurar(){
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

public:
    TNivel1 () {
        inicializar();
        configurar();
    }

    TPonto nivel(int x, int y){
        return lista[x][y];
    }
};

#endif // TNIVEL1

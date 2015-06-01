#include <TNivel.h>

#ifndef TNIVEL2
#define TNIVEL2

class TNivel2 : public TNivel {

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
              /*
              if((x > 3) && (x < 8)){
                  if((y > 3) && (y < 8)){
                    TColor::preto(&lista[x][y]);
                  }
              }*/
            }
        }
    }
public:
    TNivel2 () {
      inicializar();
      configurar();
    }

    TPonto nivel(int x, int y){
        return lista[x][y];
    }
};
#endif // TNIVEL2

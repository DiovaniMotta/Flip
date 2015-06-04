#include <TNivel.h>


TNivel::TNivel () {

}

void TNivel::inicializar(){
    for(int x=0; x<20; x++){
        for(int y=0; y< 20; y++){
            TPonto ponto;
            ponto.setCorBorda(Qt::white);
            ponto.setCorFundo(Qt::black);
            lista[x][y] = ponto;
        }
    }
}

TPonto TNivel::nivel(int x, int y){
    return lista[x][y];
}



void TNivel::addPonto(int x, int y,TPonto ponto) {
    lista[x][y] = ponto;
}

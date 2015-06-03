#include <TColisao.h>

TColisao::TColisao(){
    largura = 0;
    altura = 0;
}

TColisao::TColisao(int larg, int alt){
    largura = larg;
    altura = alt;
}

TColisao::~TColisao(){

}

void TColisao::dimensaoJanela(TPlayer* player){
    if(player->getPosX()> largura){
        player->setPosX(largura);
    }
    if(player->getPosY() > altura){
        player->setPosY(altura);
    }
}

int TColisao::getLargura(){
    return largura;
}

void TColisao::setAltura(int alt){
    altura = alt;
}

int TColisao::getAltura(){
   return altura;
}

void TColisao::setLargura(int larg){
    largura = larg;
}

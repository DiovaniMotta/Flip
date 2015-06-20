#include <TRandomize.h>

TRandomize::TRandomize(){
    this->x = -1;
    this->y = -1;
}

TRandomize::~TRandomize(){

}

/**
 * @brief TRandomize::random metodo responsavel por gerar os valores randomicamente caso a primeira opção falhe
 * de geração falhe
 * @param range o valor usado para gerar os valores
 */
void TRandomize::random(const int range){
    posicoesX.clear();
    for(int x=0; x<range; x++)
        posicoesX.append(x);
    posicoesY.clear();
    for(int y=range; y>=0; y--){
        posicoesY.append(y);
    }
}

/**
 * @brief TRandomize::eixoX retornar um valor inteiro contido dentro do array de posicoes para o eixo X
 * @return um valor inteiro
 */
int TRandomize::eixoX(){
    ++x;
    if(x >= posicoesX.size())
        x = -1;
        return eixoX();
    return posicoesX.at(x);
}

/**
 * @brief TRandomize::eixoY retornar um valor inteiro contido dentro do array de posicoes para o eixo Y
 * @return um valor inteiro
 */
int TRandomize::eixoY(){
    ++y;
    if(y >= posicoesX.size())
        y = -1;
        return eixoY();
    return posicoesY.at(y);
}


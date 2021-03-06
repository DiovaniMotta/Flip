#include <TUtils.h>

/**
 * @brief TUtils::randomize gera um valor aleatorio entre 0 o range (parametro) repassado pelo usuario
 * @param range o escopo de geração do valor
 * @return um valor inteiro representando o valor aleatorio gerado
 */
int TUtils::randomize(const int range){
    srand( (unsigned)time(NULL));
    return (rand() % range);
}

/**
 * @brief TUtils::dimensao método responsavel por calcular valores para as dimensoes usadas pela aplicacao
 * @param medida uma medida base
 * @param percentual o percentual em relacao a medida informada
 * @return um valor calculado para a medida
 */
int TUtils::dimensao(int medida, const float percentual){
    return (int)(medida * percentual);
}

/**
 * @brief TUtils::recalcular método responsavel por recalcular os valores usados pelo objeto Player
 * @param player o objeto que tera suas variaveis recalculadas
 * @param widht a largura da widget
 * @param height a altura do widght
 */
void TUtils::recalcular(TPlayer *player, const int widht, const int height){
    player->setX((player->getPosX() * widht));
    player->setY((player->getPosY() * height));
    player->setAltura(height);
    player->setLargura(widht);
}

/**
 * @brief TUtils::recalcular método responsavel por recalcular os valores usados pelos objetos Projeteis
 * @param projetil o objeto que tera suas variaveis recalculadas
 * @param widht a largura da widget
 * @param height a altura do widget
 */
void TUtils::recalcular(TProjetil* projetil,const int widht,const int height){
    int largura = (widht / 2);
    int altura = (height / 2);
    projetil->setAltura(altura);
    projetil->setLargura(largura);
    projetil->setX(((projetil->getPosX() * widht) + (widht/4)));
    projetil->setY(((projetil->getPosY() * height) + (height/4)));
}

/**
 * @brief TUtils::recalcular método responsavel por recalcular os valores usados para mostrar a localização
 * dos projeteis na tela
 * @param tiro o disparo especial feito pelo player
 * @param widht  a largura da widget
 * @param height a altura do widget
 */
void TUtils::recalcular(TTiro *tiro, const int widht, const int height){
    int largura = (widht / 2);
    int altura = (height / 2);
    tiro->setAltura(altura);
    tiro->setLargura(largura);
    tiro->setX(((tiro->getPosX() * widht) + (widht/4)));
    tiro->setY(((tiro->getPosY() * height) + (height/4)));
}

/**
 * @brief TUtils::equals responsavel por verificar se já nao existe um objeto TTiro
 * desenhado naquele local
 * @param tiro o objeto que sera verificiado
 * @param ponto o ponto da tela em que será avaliado
 * @return true se no ponto selecionado existir um objeto tiro desenhado e falso caso nao exista
 */
bool TUtils::existe(TTiro *tiro, TPonto ponto){
    if(tiro == NULL)
        return false;
    if(ponto.getX() == tiro->getPosX())
       if(ponto.getY() == tiro->getPosY())
          return true;
    return false;
}

/**
 * @brief TUtils::dimensao método responsavel por efetuar o calculo do posicionamento de um objeto na tela
 * @param medida a medida padrao
 * @param divisor o fator da divisao
 * @param decremento o decremento para correção da coordenada
 * @return um valor inteiro representando a posicao
 */
int TUtils::dimensao(int medida, int divisor, int decremento){
    return (int)((medida/divisor) - decremento);
}

/**
 * @brief TUtils::dimensao  método responsavel por calcular o posicionamento do menu em relação ao painel
 * @param painel o objeto painel em que será pintado os menus
 * @param index o indice do menu
 * @param percentual o percentual em relação ao tamanho do menu
 * @return a nova coordenada para o eixo y
 */
int TUtils::dimensao(TPainel *painel, int index, const float percentual){
    return (int) ((painel->getY() + (painel->getY() * 0.40)) + (painel->getY() * (index * percentual)));
}


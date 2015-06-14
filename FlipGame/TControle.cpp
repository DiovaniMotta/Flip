#include <TControle.h>

/**
 * @brief TControle::remove responsavel por remover os objetos já utilizados
 * @param bombas o vetor de objetos projeteis
 * @param index o indice de indexação do vetor atualmente
 */
void TControle::remove(QVector<TProjetil> *projeteis, const int index){
    if(index < 0)
        return;
    if(index >= projeteis->size())
        return;
    for(int x=0;x < index; x++){
        projeteis->remove(x);
    }
}

/**
 * @brief TControle::remove responsavel por remover os objetos já utilizados
 * @param bombas o vetor de objetos bombas
 * @param index o indice de indexação do vetor atualmente
 */
void TControle::remove(QVector<TTiro> *bombas, const int index){
    if(index < 0)
        return;
    if(index >= bombas->size())
        return;
    for(int x=0;x < index; x++){
        bombas->remove(x);
    }
}
/**
 * @brief TControle::posicionar método responsavel por reposicionar o indice dos disparos de tiros especiais
 * @param bombas o vetor que será avaliado
 * @param index o indice atual de iteracao sobre o vetor
 */
int TControle::posicionar(QVector<TTiro> *bombas, int index){
    for(int x=0; x< bombas->size();x++){
        TTiro tiro = bombas->at(x);
        if(!tiro.isColidiu())
          return x;
    }
    return index;
}

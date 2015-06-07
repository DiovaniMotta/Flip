#include <TUtils.h>

/**
 * @brief TUtils::randomize gera um valor aleatorio entre 0 o range (parametro) repassado pelo usuario
 * @param range o escopo de geração do valor
 * @return um valor inteiro representando o valor aleatorio gerado
 */
int TUtils::randomize(const int range){
    return (rand() % range);
}

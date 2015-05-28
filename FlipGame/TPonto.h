#include <TCor.h>
/**
 * Author : Diovani Bernardi da Motta
 * @brief The TPonto class classe responsável por representar cada ponto do tabuleiro
 */
class TPonto {

    int x;
    int y;
    int altura;
    int largura;
    TCor cor;
public:

    TPonto(){
        this->altura = 0;
        this->largura = 0;
        this->x = 0;
        this->y = 0;
    }

    TPonto(int x,int y,int altura, int largura){
        this->altura= altura;
        this->largura = largura;
        this->x = x;
        this->y = y;
    }

    void setAltura(int altura){
         this ->altura = altura;
    }

    int getAltura(){
        return altura;
    }

    void getLargura(int largura){
        this->largura = largura;
    }

    int getLargura(){
       return this->largura;
    }

    void setX(int x) {
      this->x = x;
    }

    int getX(){
      return this->x;
    }

    void setY(int y){
      this->y = y;
    }

    int getY(){
       return this->y;
    }

    void setCor(TCor cor){
      this->cor = cor;
    }

    TCor getCor(){
      this->cor;
    }
};

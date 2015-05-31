#include <QColor>
#include <QDebug>

#ifndef TPONTO
#define TPONTO
/**
 * Author : Diovani Bernardi da Motta
 * @brief The TPonto class classe responsável por representar cada ponto do tabuleiro
 */
class TPonto {

    int x;
    int y;
    int altura;
    int largura;
    QColor corFundo;
    QColor corBorda;

public:
    static const int dimensao = 50;

    TPonto(){
        this->altura = 0;
        this->largura = 0;
        this->x = 0;
        this->y = 0;
    }

    TPonto(int x,int y,int altura, int largura,QColor corBorda,QColor corFundo){
        this->altura= altura;
        this->largura = largura;
        this->x = x;
        this->y = y;
        this->corBorda = corBorda;
        this->corFundo = corFundo;
    }

    ~TPonto(){
    }

    void setAltura(int altura){
         this ->altura = altura;
    }

    int getAltura(){
        return altura;
    }

    void setLargura(int largura){
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

    void setCorFundo(QColor corFundo){
       this->corFundo = corFundo;
    }

    QColor getCorFundo(){
       return this->corFundo;
    }

    void setCorBorda(QColor corBorda){
       this->corBorda = corBorda;
    }

    QColor getCorBorda(){
       return this->corBorda;
    }
};
#endif // TPONTO

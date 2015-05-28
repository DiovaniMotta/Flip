#include <QVector>
#include <TPonto.h>

/**
 * Author : Diovani Bernardi da Motta
 * @brief The TTabuleiro class classe responsável por montar as informações que serão exibidas para o usuario em forma de
 * tabuleiro
 */
class TTabuleiro{

    // armazena as dimensões da tela
    int largura;
    int altura;
    // armazena os pontos que serão desenhados na tela
    QVector<TPonto>* pontos;

public:

    TTabuleiro() {
        this->largura = 0;
        this->altura = 0;
        this->pontos = new QVector<TPonto>;
    }

    TTabuleiro(int altura, int largura){
        this->altura = altura;
        this->largura = largura;
    }

    ~TTabuleiro(){
        delete pontos;
    }

    void setAltura(int altura){
        this->altura = altura;
    }

    int getAltura(){
        return this->altura;
    }

    void setLargura(int largura){
        this->largura = largura;
    }

    int getLargura(){
        return this->largura;
    }

    void setPontos(QVector<TPonto>* l){
        this->pontos = l;
    }

    QVector<TPonto>* getPontos(){
        return this->pontos;
    }

    void tabularizar(){

    }
};

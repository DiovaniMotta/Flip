#include <QVector>
#include <TPonto.h>
#include <QDebug>
#include <TDimensao.h>
#include <TCor.h>
#include <TPlayer.h>

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
    QVector<TPonto> pontos;
public:

    TTabuleiro() {
        this->largura = 0;
        this->altura = 0;
    }

    TTabuleiro(int altura, int largura){
        this->altura = altura;
        this->largura = largura;
    }

    ~TTabuleiro(){
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

    void setPontos(QVector<TPonto> l){
        this->pontos = l;
    }

    QVector<TPonto> getPontos(){
        return this->pontos;
    }

    void tabuleiro(const int dimensao){
        pontos.clear();
        int widht = (int)(largura / dimensao);
        int height = (int) (altura / dimensao);
        int size = (widht * height);
        TDimensao* dim = new TDimensao;
        TCor* cor = new TCor;
        dim->setMaxX(widht);
        dim->setMaxY(height);
        for(int x=0; x < size; x++)
        {
            TPonto ponto;
            ponto.setAltura(dimensao);
            ponto.setLargura(dimensao);
            ponto.setCorFundo(cor->cor());
            ponto.setCorBorda(cor->cor(ponto.getCorFundo()));
            QPoint* p = dim->posicao(dimensao);
            ponto.setX(p->rx());
            ponto.setY(p->ry());
            pontos.append(ponto);
        }
    }

    void configurarTabuleiro(TPlayer* player){
        switch (player->getNivel()) {
            case TPlayer::NIVEL1:
                nivel1();
                break;
            case TPlayer::NIVEL2:
                nivel2();
                break;
            case TPlayer::NIVEL3:
                nivel3();
                break;
            case TPlayer::NIVEL4:
                nivel4();
                break;
            case TPlayer::NIVEL5:
                nivel5();
                break;
        }
    }

private:

    void nivel1(){
       for(int x=0; x<pontos.size(); x++){
          if(x < 81){

          }
       }
    }

    void nivel2(){
       for(int x=0; x<pontos.size(); x++){

       }
    }

    void nivel3(){
       for(int x=0; x<pontos.size(); x++){

       }
    }

    void nivel4(){
       for(int x=0; x<pontos.size(); x++){

       }
    }

    void nivel5(){
       for(int x=0; x<pontos.size(); x++){

       }
    }
};

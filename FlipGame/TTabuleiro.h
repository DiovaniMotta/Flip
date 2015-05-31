#include <QVector>
#include <TPonto.h>
#include <QDebug>
#include <TDimensao.h>
#include <TCor.h>
#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <TNivel3.h>
#include <TNivel4.h>
#include <TNivel5.h>

#ifndef TTABULEIRO
#define TTABULEIRO
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
    TDimensao* dim;
    TCor* cor = new TCor;

public:

    TTabuleiro() {
        this->largura = 0;
        this->altura = 0;
        dim = new TDimensao;
        cor = new TCor;
    }

    TTabuleiro(int altura, int largura,TDimensao* dim,TCor* cor){
        this->altura = altura;
        this->largura = largura;
        this->cor = cor;
        this->dim = dim;
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

    /**
     * Método responsavel por montar os objeto que irão compor o tabuleiro
     * @brief tabuleiro
     * @param dimensao
     */
    void tabuleiro(const int dimensao){
        try
        {
            pontos.clear();
            int widht = (int)(largura / dimensao);
            int height = (int) (altura / dimensao);
            int size = (widht * height);
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
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    /**
     * Método responsavel por configurar o tabuleiro de acordo com o nivel em que
     * o player está
     * @brief configurarTabuleiro
     * @param player
     */
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

    /**
     * Método responsavel por configurar o tabuleiro de acordo com o nivel em que
     * o player está
     * @brief configurarTabuleiro
     * @param player
     */
    void configurarTabuleiro(const int nivel){
        switch (nivel) {
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
       try
       {
            QVector<TPonto> lista;
            int size = pontos.size();
            TNivel1 nivel1;
            nivel1.setDimensao(dim);
            nivel1.setTamanho(size);
            nivel1.setCor(cor);
            for(int x=0; x<pontos.size(); x++){
                TPonto ponto = pontos.at(x);
                nivel1.inicio(x,&ponto);
                nivel1.branco(x,&ponto);
                nivel1.preto(x,&ponto);
                nivel1.fim(x,&ponto);
                nivel1.centro(x,&ponto);
                lista.append(ponto);
            }
            pontos.clear();
            pontos = lista;
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    void nivel2(){
       try
       {
          QVector<TPonto> lista;
          int size = pontos.size();
          TNivel2 nivel2;
          nivel2.setDimensao(dim);
          nivel2.setTamanho(size);
          nivel2.setCor(cor);
          for(int x=0; x<pontos.size(); x++){
             TPonto ponto = pontos.at(x);
             nivel2.inicio(x,&ponto);
             nivel2.branco(x,&ponto);
             nivel2.preto(x,&ponto);
             nivel2.fim(x,&ponto);
             //nivel2.centro(x,&ponto);
             lista.append(ponto);
          }
          pontos.clear();
          pontos = lista;
       }
       catch(QException exception)
       {
            qDebug()<<exception.what();
       }
    }

    void nivel3(){
        try
        {
           QVector<TPonto> lista;
           int size = pontos.size();
           TNivel3 nivel3;
           nivel3.setDimensao(dim);
           nivel3.setTamanho(size);
           nivel3.setCor(cor);
           for(int x=0; x<pontos.size(); x++){

           }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    void nivel4(){
        try
        {
           QVector<TPonto> lista;
           int size = pontos.size();
           TNivel4 nivel4;
           nivel4.setDimensao(dim);
           nivel4.setTamanho(size);
           nivel4.setCor(cor);
           for(int x=0; x<pontos.size(); x++){

           }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    void nivel5(){
        try
        {
           QVector<TPonto> lista;
           int size = pontos.size();
           TNivel5 nivel5;
           nivel5.setDimensao(dim);
           nivel5.setTamanho(size);
           nivel5.setCor(cor);
           for(int x=0; x<pontos.size(); x++){

           }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }
};

#endif // TTABULEIRO

#pragma once

#ifndef TPLAYER
#define TPLAYER

#include <QColor>
#include <TProjetil.h>
#include <QVector>
#include <TBomba.h>
#include <QDebug>
/**
 * Classe responsavel por armazenar as informações do player que está no jogo
 * @brief The TPlayer class
 */
class TPlayer {

  int nivel;
  int posX;
  int posY;
  int x;
  int y;
  int largura;
  int altura;
  int ultimaPosicao;
  int i;
  int j;
  QColor fundo;
  QColor borda;

  TProjetil* projetil;
  QVector<TBomba>* bombas;

public:

    static const int NIVEL1 = 1;
    static const int NIVEL2 = 2;
    static const int NIVEL3 = 3;
    static const int NIVEL4 = 4;
    static const int NIVEL5 = 5;

    static const int SALTOS = 1;

    TPlayer();

    ~TPlayer();

    int getNivel();

    void setNivel(int nivel);

    void setPosX(int posX);

    void setPosY(int posY);

    int getPosX();

    int getPosY();

    void setUltimaPosicao(int ultima);

    int getUltimaPosicao();

    void setAltura(int altura);

    int getAltura();

    void setLargura(int largura);

    int getLargura();

    void setFundo(QColor fundo);

    QColor getFundo();

    void setBorda(QColor borda);

    QColor getBorda();

    int getX();

    void setX(int x);

    int getY();

    void setY(int y);

    void setProjetil(TProjetil* projetil);

    TProjetil* getProjetil();

    void setBombas(QVector<TBomba>* b);

    QVector<TBomba>* getBombas();

    void addBomba(TBomba* bomba);

    void  disparo();

    void disparo(const int tipo);


private:

    void duplo();

    void triplo();
};
#endif // TPLAYER

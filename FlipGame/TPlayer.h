#pragma once

#ifndef TPLAYER
#define TPLAYER

#include <QColor>
#include <TProjetil.h>
#include <QVector>
#include <TTiro.h>
#include <QDebug>
#include <TTiro.h>
#include <TControle.h>

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
  int i;// variavel contador de tipos disparados do tipo TProjetil
  int j; // variavel contador de tipos disparados TBomba(Raio)
  int l; // variavel contador de tipos disparados TBomba(Bomba)
  //variaveis de controle dos tiros especiais
  int indexRaios;
  int indexBombas;
  QColor fundo;
  QColor borda;
  // tipos de projeteis que podem ser disparos pelo player
  QVector<TProjetil>* tiros;
  QVector<TTiro>* bombas;
  QVector<TTiro>* raios;

public:

    static const int NIVEL1 = 1;
    static const int NIVEL2 = 2;
    static const int NIVEL3 = 3;
    static const int NIVEL4 = 4;
    static const int NIVEL5 = 5;

    static const int TIROS = 5;
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

    void setBombas(QVector<TTiro>* b);

    QVector<TTiro>* getBombas();

    void setRaios(QVector<TTiro>* b);

    QVector<TTiro>* getRaios();

    void setTiros(QVector<TProjetil>* projeteis);

    QVector<TProjetil>* getTiros();

    void addBomba(TTiro* bomba);

    void addRaio(TTiro* bomba);

    void  disparo();

    void disparo(const int valor);

private:

    void raio(); // configura os disparos especiais feitos pelo jogador

    void bomba(); // configura os disparos especiais feitos pelo jogador
};
#endif // TPLAYER

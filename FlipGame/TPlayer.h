#include <QColor>

#pragma once

#ifndef TPLAYER
#define TPLAYER
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
  QColor fundo;
  QColor borda;

public:

    static const int NIVEL1 = 1;
    static const int NIVEL2 = 2;
    static const int NIVEL3 = 3;
    static const int NIVEL4 = 4;
    static const int NIVEL5 = 5;

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
};
#endif // TPLAYER

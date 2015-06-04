#ifndef TTABULEIRO
#define TTABULEIRO

#include <TPonto.h>
#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>

/**
 * Author : Diovani Bernardi da Motta
 * @brief The TTabuleiro class classe responsável por montar as informações que serão exibidas para o usuario em forma de
 * tabuleiro
 */
class TTabuleiro {

   TPlayer* player1;
   TPlayer* player2;
   TNivel1* nivel1;
   TNivel2* nivel2;

public:
    static const int DIMENSAO = 20;

    TTabuleiro();

    TTabuleiro(TPlayer* player1,TPlayer* player2);

    ~TTabuleiro();

    void setPlayer1(TPlayer* player1);

    TPlayer* getPlayer1();

    void setPlayer2(TPlayer* player2);

    TPlayer* getPlayer2();

    TPonto nivel(int x,int y);

    TNivel1* getNivel1();

    void setNivel1(TNivel1* nivel);

    TNivel2* getNivel2();

    void setNivel2(TNivel2* nivel);
};
#endif // TTABULEIRO

#ifndef TUTILS
#define TUTILS

#include <stdio.h>
#include <stdlib.h>
#include <TPlayer.h>
#include <TProjetil.h>
#include <TTiro.h>
#include <TPonto.h>
#include <QVector>
#include <QDebug>

class TUtils {

public:

    static const int DIMENSAO = 20;
    static const float CINCO_POR_CENTO = 0.05;

    TUtils ();

    static int randomize(const int range);

    static int dimensao(int medida,const float percentual);

    static void recalcular(TPlayer* player,const int widht,const int height);

    static void recalcular(TProjetil* projetil,const int widht,const int height);

    static bool existe(TTiro* tiro,TPonto ponto);

};


#endif // TUTILS


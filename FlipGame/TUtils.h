#ifndef TUTILS
#define TUTILS

#include <stdio.h>
#include <stdlib.h>
#include <TPlayer.h>
#include <TProjetil.h>
#include <TTiro.h>
#include <TPonto.h>
#include <QVector>
#include <TPainel.h>
#include <QDebug>
#include <time.h>
#include <QTime>

class TUtils {

public:

    static const int DIMENSAO = 20;
    static const int MEDIA_DIMENSAO = (DIMENSAO/2);
    static const float CINCO_POR_CENTO = 0.05;
    static const float OITO_POR_CENTO = 0.08;
    static const float CINQUENTA_POR_CENTO = 0.5;
    static const float VINTE_POR_CENTO = 0.20;
    static const float QUINZE_POR_CENTO = 0.15;
    static const float QUARENTA_POR_CENTO = 0.40;

    TUtils ();

    static int randomize(const int range);

    static int dimensao(int medida,const float percentual);

    static int  dimensao(int medida,int divisor,int decremento);

    static int  dimensao(TPainel* painel,int index,const float percentual);

    static void recalcular(TPlayer* player,const int widht,const int height);

    static void recalcular(TProjetil* projetil,const int widht,const int height);

    static void recalcular(TTiro* tiro,const int widht,const int height);

    static bool existe(TTiro* tiro,TPonto ponto);
};


#endif // TUTILS


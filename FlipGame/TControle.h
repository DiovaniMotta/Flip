#ifndef TCONTROLE
#define TCONTROLE

#include <TPlayer.h>
#include <QVector>
#include <TProjetil.h>
#include <TProjetil.h>
#include <QDebug>

class TControle {

public:

    TControle () {}

    static void remove(QVector<TTiro>* bombas,const int index);

    static void remove(QVector<TProjetil>* projeteis,const int index);

    static int posicionar(QVector<TTiro>* bombas,int index);
};
#endif // TCONTROLE


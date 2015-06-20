#ifndef TRANDOMIZE
#define TRANDOMIZE

#include<QVector>
#include<TUtils.h>

class TRandomize {

    QVector<int> posicoesX;
    QVector<int> posicoesY;
    int x;
    int y;

public:

    TRandomize ();

    ~TRandomize();

    void random(const int range);

    int eixoX();

    int eixoY();

};
#endif // TRANDOMIZE


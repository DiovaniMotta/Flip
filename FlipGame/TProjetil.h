#ifndef TPROJETIL
#define TPROJETIL

#include <QColor>

class TProjetil {

    int x;
    int y;
    int posX;
    int posY;
    int largura;
    int altura;
    bool ativo;
    QColor corFundo;
    QColor borda;

public:
    static const int DESLOCAMENTO = 10;

    TProjetil ();

    TProjetil(int x, int y, int posX, int posY, int largura, int altura);

    ~TProjetil();

    void setX(int x);

    void setY(int y);

    void setPosX(int posX);

    void setPosY(int posY);

    void setLargura(int largura);

    void setAltura(int altura);

    int getX();

    int getY();

    int getPosX();

    int getPosY();

    int getLargura();

    int getAltura();

    void setAtivo(bool ativo);

    bool isAtivo();

    void setCorFundo(QColor fundo);

    QColor getCorFundo();

    void setCorBorda(QColor borda);

    QColor getCorBorda();

    void disparo();
};
#endif // TPROJETIL


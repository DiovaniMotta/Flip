#ifndef TPROJETIL
#define TPROJETIL

class TProjetil {

    int x;
    int y;
    int posX;
    int posY;
    int largura;
    int altura;
    bool ativo;

public:

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
};
#endif // TPROJETIL


#ifndef TPROJETIL
#define TPROJETIL

#include <QColor>
#include <QKeyEvent>
#include <QDebug>

class TProjetil {

    int nivel;
    int x;
    int y;
    int posX;
    int posY;
    int count; // vai contar o numero de saltos dados de acordo com a diretiva SALTOS e vai atualizar as variaveis X/Y
    int largura;
    int altura;
    int ultimaPosicao;
    bool ativo;
    QColor corFundo;
    QColor borda;

    //variaveis usadas para o controle do deslocamento
    const int SALTOS = 5;
    const float PERCENTUAL_DESLOCAMENTO = 0.20;

public:
    int DESLOCAMENTO = 0;

    TProjetil ();

    TProjetil(int x, int y, int posX, int posY, int largura, int altura);

    ~TProjetil();

    void setNivel(int nivel);

    int getNivel();

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

    void setUltimaPosicao(int ultimaPosicao);

    int getUltimaPosicao();

    void disparo();

    void reiniciar();

    void deslocamento(int dimen); // recebe uma dimensao da tela (Altura ou largura)


};
#endif // TPROJETIL


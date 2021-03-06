#ifndef TPROJETIL
#define TPROJETIL

#include <QColor>
#include <QKeyEvent>
#include <QDebug>
#include <QVector>

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
    bool disparou;
    QColor corFundo;
    QColor borda;

    //variaveis usadas para o controle do deslocamento
    static const int SALTOS = 2;
    static const float PERCENTUAL_DESLOCAMENTO = 0.5;

public:
    int DESLOCAMENTO;

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

    void setDisparou(bool disparou);

    bool isAtivo();

    bool isDisparou();

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


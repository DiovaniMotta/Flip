#ifndef TBOMBA
#define TBOMBA

#include <QColor>
#include <QObject>

class TBomba {

    int x;
    int y;
    int posX;
    int posY;
    int direcao;
    int tipo;
    int largura;
    int altura;
    int count; // vai contar o numero de saltos dados de acordo com a diretiva SALTOS e vai atualizar as variaveis X/Y
    int nivel;

    bool visivel;
    bool ativo;

    QColor fundo;
    QColor borda;

    //variaveis usadas para o controle do deslocamento
    const int SALTOS = 5;
    const float PERCENTUAL_DESLOCAMENTO = 0.20;

public:
    int DESLOCAMENTO = 0;

   static const int DUPLO = 2;
   static const int TRIPLO = 3;

   TBomba ();

   TBomba(int x, int y, int posX, int posY,bool visivel);

   ~TBomba();

   void setX(int x);

   void setY(int y);

   void setPosX(int posX);

   void setPosY(int posY);

   void setVisivel(bool visivel);

   void setAtivo(bool ativo);

   int getX();

   int getY();

   int getPosX();

   int getPosY();

   bool isVisivel();

   bool isAtivo();

   int getTipo();

   int getDirecao();

   int getLargura();

   int getAltura();

   int getNivel();

   void setFundo(QColor fundo);

   void setBorda(QColor borda);

   void setDirecao(int direcao);

   void setTipo(int tipo);

   void setLargura(int largura);

   void setAltura(int altura);

   void setNivel(int nivel);

   QColor getFundo();

   QColor getBorda();

   void deslocamento(int dimen); // recebe uma dimensao da tela (Altura ou largura)
};
#endif // TBOMBA


#ifndef TTIRO
#define TTIRO

#include <QColor>
#include <QObject>
#include <QDebug>

class TTiro {

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

    bool visivel; // informa se o objeto será pintado na tela para que o player possa pega-lo
    bool ativo; // informa se o tiro especial foi disparado pelo player e sua trajetoria deve ser pintada na tela
    bool colidiu; //variavel que informa se o projétil ja colidiu com algum elemento do tabuleiro

    QColor fundo;
    QColor borda;

    //variaveis usadas para comparacao da colisao
    QColor corFundoJogador;
    QColor corBordaJogador;

    //variaveis usadas para o controle do deslocamento
    static const int SALTO = 5;
    static const float PERCENTUAL = 0.20;

public:

   int DESLOCAMENTO;

   //constantes usadas para identificar o tipo de disparo
   static const int BOMBA = 1;
   static const int RAIO = 2;

   TTiro();

   TTiro(int x, int y, int posX, int posY,bool visivel);

   ~TTiro();

   void setX(int x);

   void setY(int y);

   void setPosX(int posX);

   void setPosY(int posY);

   void setVisivel(bool visivel);

   void setAtivo(bool ativo);

   void setColidiu(bool colidiu);

   int getX();

   int getY();

   int getPosX();

   int getPosY();

   bool isVisivel();

   bool isAtivo();

   bool isColidiu();

   int getTipo();

   int getDirecao();

   int getLargura();

   int getAltura();

   int getNivel();

   void setDirecao(int direcao);

   void setTipo(int tipo);

   void setLargura(int largura);

   void setAltura(int altura);

   void setNivel(int nivel);

   QColor getFundo();

   QColor getBorda();

   QColor getCorFundoJogador();

   QColor getCorBordaJogador();

   void setFundo(QColor fundo);

   void setBorda(QColor borda);

   void setCorFundoJogador(QColor fundo);

   void setCorBordaJogador(QColor borda);

   void deslocamento(int dimen); // recebe uma dimensao da tela (Altura ou largura)

   void reiniciar();
};
#endif // TTIRO


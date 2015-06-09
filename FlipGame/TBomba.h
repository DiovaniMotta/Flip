#ifndef TBOMBA
#define TBOMBA

#include <QColor>
#include <QObject>

class TBomba {

    int x;
    int y;
    int posX;
    int posY;
    bool visivel;
    bool ativo;
    QColor fundo;
    QColor borda;

public:

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

   void setFundo(QColor fundo);

   void setBorda(QColor borda);

   QColor getFundo();

   QColor getBorda();

};
#endif // TBOMBA


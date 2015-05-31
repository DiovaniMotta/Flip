#include <QWidget>

#ifndef TPLAYER
#define TPLAYER
/**
 * Classe responsavel por armazenar as informações do player que está no jogo
 * @brief The TPlayer class
 */
class TPlayer : public QWidget {

  int nivel;
  int posX;
  int posY;
  int altura;
  int largura;

public:

    static const int NIVEL1 = 1;
    static const int NIVEL2 = 2;
    static const int NIVEL3 = 3;
    static const int NIVEL4 = 4;
    static const int NIVEL5 = 5;

    TPlayer() {
        this->nivel = 1;
        this->posX = 0;
        this->posY = 0;
        this->altura = 0;
        this->largura = 0;
    }

    int getNivel(){
        return this->nivel;
    }

    void setNivel(int nivel){
        this->nivel = nivel;
    }

    void setPosX(int pos){
        this->posX = pos;
    }

    void setPosY(int pos){
        this->posY = pos;
    }

    int getPosX(){
        return this->posX;
    }

    int getPosY(){
        return this->posY;
    }

    void setAltura(int altura){
        this->altura = altura;
    }

    void setLargura(int largura){
        this->largura = largura;
    }

    int getLargura(){
        return this->largura;
    }

    int getAltura(){
        return this->altura;
    }
};
#endif // TPLAYER

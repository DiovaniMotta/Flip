/**
 * Classe responsavel por armazenar as informações do player que está no jogo
 * @brief The TPlayer class
 */
class TPlayer {

  int nivel;

public:

    static const int NIVEL1 = 1;
    static const int NIVEL2 = 2;
    static const int NIVEL3 = 3;
    static const int NIVEL4 = 4;
    static const int NIVEL5 = 5;

    TPlayer() {}

    int getNivel(){
        return this->nivel;
    }

    void setNivel(int nivel){
        this->nivel = nivel;
    }
};

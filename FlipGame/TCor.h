#include <QColor>

/**
 * Author: Diovani Bernardi da Motta
 * @brief The TUtils class Classe responsavel por armazenar as constantes usadas pela aplicacao
 */
class TCor {

private:

    int randomColor(){
        return (qrand() % 3);
    }

public:
    TCor () {}
    ~TCor(){}

    static const int CINZA = 0;
    static const int PRETO = 1;
    static const int BRANCO = 2;

    QColor cor(QColor cor){

        if(cor.operator ==(Qt::white)){
            return Qt::black;
        }
        if(cor.operator ==(Qt::black)){
            return Qt::white;
        }
        return Qt::gray;
    }

    QColor cor(){
        int cor = randomColor();
        switch(cor)
        {
            case TCor::CINZA:
              return Qt::gray;
            case TCor::BRANCO:
              return Qt::white;
            case TCor::PRETO:
              return Qt::black;
        }
        return Qt::gray;
    }
};

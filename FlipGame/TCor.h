#include <QColor>
#include <QException>

#ifndef TCOR
#define TCOR

/**
 * Author: Diovani Bernardi da Motta
 * @brief The TCor class Classe responsavel por armazenar as constantes usadas pela aplicacao
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
        try
        {
            if(cor.operator ==(Qt::white)){
                return Qt::black;
            }
            if(cor.operator ==(Qt::black)){
                return Qt::white;
            }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
        return Qt::gray;
    }

    QColor cor(){
        try
        {
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
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }

        return Qt::gray;
    }
};


#endif // TCOR


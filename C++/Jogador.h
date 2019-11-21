#ifndef _JOGADOR_
#define _JOGADOR_

#include <string>

using namespace std;

class Jogador{
    public:
        Jogador(string);
        unsigned getPontos();
        void setPontos(int);
        string getNome();

    private:
       unsigned pontos;
       string nome;
};

#endif

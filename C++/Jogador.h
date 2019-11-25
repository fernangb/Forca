#ifndef _JOGADOR_
#define _JOGADOR_

#include <string>

using namespace std;

class Jogador{
    public:
        Jogador(string);
        int getPontos();
        void setPontos(int);
        string getNome();

    private:
       int pontos;
       string nome;
};

#endif

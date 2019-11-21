#include <string>
#include <vector>

#include "Jogador.h"
#include "Palavra.h"

#define MAX_VIDAS 7
#define NUM_PONTOS_ACERTO 10


class Jogo{
    public:
        //Jogo(string, string, string);
        Jogo(Jogador, Palavra);
        unsigned getNumVidas();

        void montarTela();
        bool verificarJogada(char);
        void desenharForca(unsigned);
        void desenharPalavra();
        void jogar();
        bool verificarLetraRepetida(char);

    private:
        unsigned numVidas;
        Jogador jogador;
        Palavra palavra;
        vector <char> letrasErradas;
        vector <char> letrasCertas;


};
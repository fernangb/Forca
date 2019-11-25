#ifndef _JOGO_
#define _JOGO_


#include <string>
#include <vector>

#include "Jogador.h"
#include "Palavra.h"

#define MAX_VIDAS 6
#define NUM_PONTOS_ACERTO 10


class Jogo{
    public:
        //Jogo(string, string, string);
        Jogo(Jogador, Palavra);
        unsigned getNumVidas();
        unsigned getRodada();
        void setRodada();
        void setNumVidas();
        unsigned getAcertosSeguidos();
        void setAcertosSeguidos(unsigned);
        void  setMaxAcertosSeguidos(unsigned);
        unsigned getMaxAcertosSeguidos();

        void montarTela();
        bool verificarJogada(char);
        void desenharForca(unsigned);
        void desenharPalavra();
        void jogar();
        bool verificarLetraRepetida(char);
        void calcularPontuacaoFinal(bool);
        
    private:
        unsigned numVidas;
        Jogador jogador;
        Palavra palavra;
        vector <char> letrasErradas;
        vector <char> letrasCertas;
        unsigned rodada;
        unsigned acertosSeguidos;
        unsigned maxAcertosSeguidos;



};

#endif
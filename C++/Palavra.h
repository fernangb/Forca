#ifndef _PALAVRA_
#define _PALAVRA_

#include <iostream>
#include <string>
#include <vector>

#define FACIL 40
#define MEDIO 80
#define DIFICIL 100

using namespace std;

class Palavra{
    public:
        Palavra(string, string);
        string getDificuldade();
        string getNome();
        string getDica();
        unsigned getNumLetras();
        unsigned getNumLetrasDiferentes();
        unsigned calcularLetrasDiferentes();
        string calcularDificuldade();
        bool VerificarPalavra();



    private:
        unsigned codigo;
        string nome;
        string dica;
        unsigned numLetras;
        unsigned numLetrasDiferentes;
        string dificuldade;

};

#endif
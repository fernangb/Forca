#ifndef _PALAVRA_
#define _PALAVRA_

#include <iostream>
#include <string>
#include <vector>

#define FACIL 30
#define MEDIO 60
#define DIFICIL 90

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
        int getCodigo();
        void setCodigo(int);

    private:
        unsigned codigo;
        string nome;
        string dica;
        unsigned numLetras;
        unsigned numLetrasDiferentes;
        string dificuldade;

};

#endif
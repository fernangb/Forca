#include <iostream>
#include <string>
#include <vector>

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
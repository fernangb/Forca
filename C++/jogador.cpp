#include <string>
#include "Jogador.h"

using namespace std;

Jogador::Jogador(string n){
    nome = n;
    pontos = 0;
}

int Jogador:: getPontos(){
    return pontos;
}

void Jogador:: setPontos(int p){
    pontos = p;
}

string Jogador:: getNome(){
    return nome;
}
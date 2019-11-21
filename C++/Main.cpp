#include <iostream>
#include <string>

#include "Palavra.h"
#include "Jogador.h"
#include "Jogo.h"

using namespace std;

int main(){
    Palavra palavra("FLAMENGO", "TIME DE FUTEBOL");
    Jogador jogador("GABRIEL");
    
    Jogo jogo(jogador, palavra);
    jogo.jogar();

    // cout<<palavra.getNome() << endl;
    // cout<<palavra.getDica() << endl;
    // cout<<palavra.getDificuldade() << endl;
    // cout<<palavra.getNumLetras() << endl;
    // cout<<palavra.getNumLetrasDiferentes() << endl;

    return 0;
}

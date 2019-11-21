#include <iostream>
#include <string>

#include "Palavra.h"
#include "Jogador.h"
#include "Jogo.h"

using namespace std;

int main(){
    Palavra palavra("GRENINJA", "POKEMON");
    Jogador jogador("GABRIEL");
    
    Jogo jogo(jogador, palavra);
    jogo.jogar();

    return 0;
}

/*REVER:
- PONTUACAO SE PERDER
- LETRA MINUSCULA
- SELECIONAR PALAVRA RANDOMICAMENTE
- TRATAMENTO DE ERRO

*/

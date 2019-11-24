#include <iostream>
#include <string>
#include <cstdlib> 


#include "Palavra.h"
#include "Jogador.h"
#include "Jogo.h"

using namespace std;

int main(){
    string nome;
    char dificuldade;
    bool ok = false;
    string nivel;

    system("clear");

    cout<<"          JOGO DA FORCA "<<endl;
    cout<<"Digite o seu nome: "<<endl;
    cin>>nome;

    cout<<"DIFICULDADE"<<endl;
    cout<<"1- Facil"<<endl;
    cout<<"2- Medio"<<endl;
    cout<<"3- Dificil"<<endl;

    while(!ok){
        cout<<"Escolha uma dificuldade:"<<endl;
        cin>>dificuldade;

        if((dificuldade != '1')&&(dificuldade!= '2')&&(dificuldade != '3'))
            cout<<"Erro. Caractere invalido. Digite novamente."<<endl;
        else
            ok = true;
        
    }

    Jogador jogador(nome);

    if(dificuldade == '1'){
        nivel = "FACIL";
        Palavra p1("ABACAXI", "FRUTA");
               Jogo jogo(jogador, p1);
                   jogo.jogar();


    }
    else  if(dificuldade == '2'){
        nivel = "MEDIO";
        Palavra p2("MELANCIA", "FRUTA");
       Jogo jogo(jogador, p2);
           jogo.jogar();

    }
    else{
        nivel = "DIFICIL";
        Palavra p3("CHAMPEDAQUE", "FRUTA");
        Jogo jogo(jogador, p3);
            jogo.jogar();

    }


    return 0;
}

/*REVER:
- SELECIONAR PALAVRA RANDOMICAMENTE
- TRATAMENTO DE ERRO

*/

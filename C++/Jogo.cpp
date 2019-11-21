#include <string>
#include <iostream>

#include "Jogo.h"
#include "Jogador.h"
#include "Palavra.h"

using namespace std;


Jogo::Jogo(Jogador j, Palavra p){
    //jogador(j);
    //palavra(p,d);

    // jogador.nome = j;
    // jogador.pontos=0;

    // palavra.nome = p;
    // palavra.dica = d;
    // palavra.numLetras = palavra.size();
    // palavra.numLetrasDiferentes = palavra.calcularLetrasDiferentes();
    // palavra.dificuldade = palavra.calcularDificuldade();

    jogador = j;
    palavra = p;

    numVidas = MAX_VIDAS;
}

unsigned Jogo:: getNumVidas(){
    return numVidas;
}

void Jogo:: jogar(){
    bool acertei = false;
    char letra;

    while(numVidas>0 || acertei){
        montarTela();
        cout<<"Digite uma letra:" <<endl;
        cin>>letra;

        if(verificarLetraRepetida(letra)){
            montarTela();
            cout<<"Letra Repetida. =(" <<endl;
        }else{ //Se a letra nao for repetida eu posso verificar a jogada
            if(verificarJogada(letra)){
                letrasCertas.push_back(letra);
                cout<<"Boa !! Letra Correta =) "<<endl;
            }else{
                letrasErradas.push_back(letra);
                cout<<"Poxa !! Letra Incorreta =( "<<endl;
                numVidas--;
            }
        }

        //Verificando se eu acertei a palavra
        if(palavra.getNumLetrasDiferentes() == letrasCertas.size())
            acertei = true;
    }

    //Jogo acabou
    if(acertei)
        cout<<"Parabens. Voce acertou a palavra =)"<<endl;
    else
        cout<<"Game Over =("<<endl;

    cout<<"Sua pontuacao final foi: "<<jogador.getPontos()<<endl;
}

bool Jogo:: verificarLetraRepetida(char letra){
    bool achei = false;
    //Palavras certas
    for(unsigned i=0; i<letrasCertas.size();i++)
        if(letra == letrasCertas[i])
            achei = true;

    //Palavras erradas
    for(unsigned i=0; i<letrasErradas.size();i++)
        if(letra == letrasErradas[i])
            achei = true;
    
    return achei;
}

void Jogo:: montarTela(){
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Jogador: "<<jogador.getNome()<<endl;
    cout<<"Pontos:  "<<jogador.getPontos()<<endl;
    cout<<"Vidas:  "<<numVidas<<endl;

    desenharForca(numVidas);
    desenharPalavra();
    cout<<"--------------------------------------------------------------------"<<endl;
    
}

void Jogo:: desenharForca(unsigned vidas){
    cout<<"______________________"<<endl;

    //Cabeca
    if(vidas == MAX_VIDAS)
        cout<<"|"<<endl;
    else
        cout<<"|                     O "<<endl;

    //Tronco e Bracos
    if(vidas == MAX_VIDAS)
        cout<<"|"<<endl;
    else if(vidas == MAX_VIDAS -1)
        cout<<"|                     | "<<endl;
    else if(vidas == MAX_VIDAS -2)
        cout<<"|                    (| "<<endl;
    else
        cout<<"|                    (|) "<<endl;

    //Pernas
       if(vidas >= MAX_VIDAS-4)
        cout<<"|"<<endl;
    else if(vidas >= MAX_VIDAS-5)
        cout<<"|                     ] "<<endl;
    else
        cout<<"|                     ]["<<endl;

}

void Jogo:: desenharPalavra(){
    bool existe;

    for(unsigned i=0; i<palavra.getNumLetras(); i++){
        existe = false;
        for(unsigned j=0; j<letrasCertas.size(); j++)
            if(palavra.nome[i] == letrasCertas[j])
                existe = true;
        
        if(existe)
            cout<<" "<<palavra.nome[i];
        else
            cout<<"* ";
    }
    cout<<endl;
}

bool Jogo:: verificarJogada(char letra){
    bool existe=false;

    for(unsigned i=0; i<palavra.getNumLetras(); i++)
    {
        if(letra == palavra.nome[i]){
            existe = true;
            jogador.setPontos(NUM_PONTOS_ACERTO);
        }
    }

    if(existe)
        return true;

    return false;
}


#include <string>
#include <iostream>
#include<cctype>

#include "Jogo.h"
#include "Jogador.h"
#include "Palavra.h"

using namespace std;


Jogo::Jogo(Jogador j, Palavra p): jogador(j.getNome()), palavra(p.getNome(), p.getDica()){
    numVidas = MAX_VIDAS;
    rodada = 1;
}

unsigned Jogo:: getNumVidas(){
    return numVidas;
}

void Jogo::setNumVidas(){
    numVidas--;
}
unsigned Jogo:: getRodada(){
    return rodada;
}

void Jogo::setRodada(){
    rodada++;
}

void Jogo:: jogar(){
    char letra;
    bool continua = true;
    bool acertei = false;

    while (continua){
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
                setNumVidas();
            }
        }

        cout<<palavra.getNumLetrasDiferentes()<<endl;
        cout<<letrasCertas.size()<<endl;
        cout<<continua<<endl;
        cout<<getNumVidas()<<endl;

        if(numVidas==0)
            continua=false;

        //Verificando se eu acertei a palavra
        if(palavra.getNumLetrasDiferentes() == letrasCertas.size()){
            acertei = true;
            continua=false;
        }
        else
            setRodada();
    }

    //Jogo acabou
    if(acertei)
        cout<<"Parabens. Voce acertou a palavra =)"<<endl;
    else
        cout<<"Game Over =("<<endl;
    
    
    calcularPontuacaoFinal();
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
    cout<<"Vidas:  "<<getNumVidas()<<endl;
    cout<<"Rodada: "<<getRodada()<<endl;

    desenharForca(numVidas);
    desenharPalavra();
    cout<<"--------------------------------------------------------------------"<<endl;
    
}

void Jogo:: desenharForca(unsigned vidas){
    cout<<"__________________"<<endl;

    //Cabeca
    if(vidas == MAX_VIDAS)
        cout<<"|"<<endl;
    else
        cout<<"|                     O "<<endl;

    //Tronco e Bracos
    if(vidas >= MAX_VIDAS - 1)
        cout<<"|"<<endl;
    else if(vidas == MAX_VIDAS -2)
        cout<<"|                     | "<<endl;
    else if(vidas == MAX_VIDAS -3)
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
    string palavraEscolhida = palavra.getNome();

    for(unsigned i=0; i<palavra.getNumLetras(); i++){
        existe = false;
        for(unsigned j=0; j<letrasCertas.size(); j++)
            if(palavraEscolhida[i] == letrasCertas[j])
                existe = true;
        
        if(existe)
            cout<<" "<<palavraEscolhida[i];
        else
            cout<<"* ";
    }
    cout<<endl;
    cout<<"Dica: "<<palavra.getDica()<<endl;
    cout<<"Dificuldade: "<<palavra.getDificuldade()<<endl;
    cout<<"Numero de letras: "<<palavra.getNumLetras()<<endl;
    
    for(unsigned i=0; i<letrasErradas.size();i++)
        cout<<" "<<letrasErradas.at(i);
    cout<<endl;
}

bool Jogo:: verificarJogada(char letra){
    bool existe=false;
    string palavraEscolhida = palavra.getNome();

    letra = toupper(letra);

    for(unsigned i=0; i<palavra.getNumLetras(); i++)
    {
        if(letra == palavraEscolhida[i]){
            existe = true;
            jogador.setPontos(NUM_PONTOS_ACERTO);
        }
    }

    if(existe)
        return true;

    return false;
}

void Jogo:: calcularPontuacaoFinal(){
    unsigned nivel;

    if(palavra.getDificuldade() == "FACIL")
        nivel = FACIL;
    else if (palavra.getDificuldade() == "MEDIO")
        nivel = MEDIO;
    else
        nivel = DIFICIL;
      
    unsigned pontuacao = ((jogador.getPontos() - (letrasErradas.size()*10))*nivel/rodada);
    jogador.setPontos((-1)*jogador.getPontos()); //Zerando a pontuacao final
    jogador.setPontos(pontuacao);
}
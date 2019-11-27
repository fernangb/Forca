#include <string>
#include <iostream>
#include<cctype>
#include <cstdlib> 

#include "Jogo.h"
#include "Jogador.h"
#include "Palavra.h"
#include "Arquivo.h"

using namespace std;


Jogo::Jogo(Jogador j, Palavra p): jogador(j.getNome()), palavra(p.getNome(), p.getDica()){
    system("clear");
    numVidas = MAX_VIDAS;
    rodada = 1;
    acertosSeguidos = 0;
    maxAcertosSeguidos = 0;
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

unsigned Jogo:: getAcertosSeguidos(){
    return acertosSeguidos;
}

void Jogo::setAcertosSeguidos(unsigned numero){
    acertosSeguidos = numero;
}

unsigned Jogo:: getMaxAcertosSeguidos(){
    return acertosSeguidos;
}

void Jogo::setMaxAcertosSeguidos(unsigned numero){
    if(numero > maxAcertosSeguidos)
        maxAcertosSeguidos = numero;
}

void Jogo:: jogar(){
    char letra;
    bool continua = true;
    bool acertei = false;
    char sair;

    while (continua){
 
        montarTela();
        cout<<"Digite uma letra:" <<endl;
        cin>>letra;
        letra = toupper(letra);

        if(verificarLetraRepetida(letra)){
            montarTela();
            cout<<"Letra Repetida. =(" <<endl;
        }else{ //Se a letra nao for repetida eu posso verificar a jogada
            system("clear");

            if(verificarJogada(letra)){
                letrasCertas.push_back(letra);
                cout<<"Boa !! Letra Correta =) "<<endl;
            }else{
                letrasErradas.push_back(letra);
                cout<<"Poxa !! Letra Incorreta =( "<<endl;
                setNumVidas();
            }
        }

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
    system("clear");
    desenharForca(numVidas);
    desenharPalavra();
    cout<<"--------------------------------------------------------------------"<<endl;

    if(acertei)
        cout<<"Parabens. Voce acertou a palavra =)"<<endl;
    else{
        cout<<"Game Over =("<<endl;
        cout<<"A palavra era "<<palavra.getNome()<<endl;
    }
    
    
    calcularPontuacaoFinal(acertei);
    cout<<"Sua pontuacao final foi: "<<jogador.getPontos()<<endl;

        Arquivo file("Pontuacoes");
        file.lerPalavrasProVector();
        Jogador j(jogador.getNome());
        j.setPontos(jogador.getPontos());
        file.jogador.push_back(j);
        file.escreverJogada(jogador.getNome(),jogador.getPontos());

    cout<<"Digite qualquer tecla e depois ENTER para voltar ao menu inicial ..."<<endl;
    cin>>sair;
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
    cout<<"Numero de Letras: "<<palavra.getNumLetras()<<endl;
    cout<<"Dificuldade: "<<palavra.getDificuldade()<<endl;

    desenharForca(numVidas);
    desenharPalavra();
    cout<<"--------------------------------------------------------------------"<<endl;
    
}

void Jogo:: desenharForca(unsigned vidas){
    cout<<"_______________________"<<endl;

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
        cout<<"|                    /| "<<endl;
    else
        cout<<"|                    /|\\ "<<endl;

    //Pernas
       if(vidas >= MAX_VIDAS-4)
        cout<<"|"<<endl;
    else if(vidas >= MAX_VIDAS-5)
        cout<<"|                     / "<<endl;
    else
        cout<<"|                     /\\"<<endl;

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
    
    for(unsigned i=0; i<letrasErradas.size();i++)
        cout<<" "<<letrasErradas.at(i);
    cout<<endl;
    cout<<"Dica: "<<palavra.getDica()<<endl;
}

bool Jogo:: verificarJogada(char letra){
    bool existe=false;
    unsigned numLetras = 0;
    string palavraEscolhida = palavra.getNome();

    for(unsigned i=0; i<palavra.getNumLetras(); i++)
        if(letra == palavraEscolhida[i]){
            existe = true;
            numLetras++;
        }


    if(!existe){
        setAcertosSeguidos(0);
        jogador.setPontos(jogador.getPontos() - (NUM_PONTOS_ACERTO/2)) ;
        return false;
    }

    setAcertosSeguidos(acertosSeguidos+1);
    setMaxAcertosSeguidos(acertosSeguidos);
    jogador.setPontos(jogador.getPontos() + (NUM_PONTOS_ACERTO*acertosSeguidos*numLetras));


    return true;
}

void Jogo:: calcularPontuacaoFinal(bool acerto){
    unsigned nivel;
    unsigned pontuacao;
    int pontoExtra;    

    if(palavra.getDificuldade() == "FACIL")
        nivel = FACIL;
    else if (palavra.getDificuldade() == "MEDIO")
        nivel = MEDIO;
    else
        nivel = DIFICIL;


    
    cout<<"Maior sequencia: "<<maxAcertosSeguidos<<endl;


    //Calculando a pontuacao a partir do acerto ou erro
    //Comparar numero de letras erradas com a rodada
    //rodada maxima: numLetrasDiferentes + maximo de vidas
    if(acerto)
        pontoExtra = (nivel*maxAcertosSeguidos) - (rodada*10); //quando mais rapido acertar, menos pontos serao descontados
    else
        pontoExtra = (nivel*maxAcertosSeguidos) - (palavra.getNumLetrasDiferentes() + MAX_VIDAS - rodada)*50; // quanto mais tempo durar, menos pontos serao descontados

    pontuacao = jogador.getPontos() + pontoExtra;
    jogador.setPontos(pontuacao);
}


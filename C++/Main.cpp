#include <iostream>
#include <string>
#include <cstdlib> 


#include "Palavra.h"
#include "Jogador.h"
#include "Jogo.h"
#include "Arquivo.h"

using namespace std;

int main(){
    // string nome;
    // string palavra;
    // string dica;
    // //char dificuldade;
    // bool ok = false;
    // string nivel;
    // char continua;

    Arquivo arq("Palavras");
    // Palavra p1(0,"UVA", "FRUTA" );
    // Palavra p2(1,"FLAMENGO", "TIME" );
    // arq.palavra.push_back(p1);
    // arq.palavra.push_back(p2);
    // arq.escreverPalavra();


    string palavra;
    string dica;
    //bool ok=false;

    // system("clear");
    // cout()

    arq.iniciarPalavras();
    // int numero = arq.palavra.size();
   int continua=0;

       // int kkk = arq.limparArquivo();
    system("clear");
    arq.iniciarPalavras();

        // for(unsigned i=0;i<arq.palavra.size();i++)
        // cout<<arq.palavra[i].getNome()<<" "<<arq.palavra[i].getDica()<<endl;
    while(continua==0){
            int numero = arq.palavra.size()+1;

            cout<<arq.palavra.size()<<endl;

        //system("clear");
        cout<<"Escreva uma palavra:"<<endl;
        cin>> palavra;
        cout<<"Escreva uma dica:"<<endl;
        cin>> dica;
        cout<<"Continua? 0 sim "<<endl;
        cin>>continua;
        Palavra p(palavra, dica);
        arq.palavra.push_back(p);
        arq.escreverPalavra(palavra,dica, p.getDificuldade());

        // if(continua == 's')
        //     ok=true;
            
    }

    //cout<<arq.encontrarPalavra ("FACIL")<<endl;
    //cout<<arq.palavraEscolhida.getNome()<<endl;


    for(unsigned i=0;i<arq.palavra.size();i++)
        cout<<arq.palavra[i].getNome()<<" "<<arq.palavra[i].getDica()<<endl;

	int	indice = rand()%palavra.size();
    Jogador j("GABRIEL");
    
    Jogo jogo(j,arq.palavra[indice]);
    jogo.jogar();



    // system("clear");

    // cout<<"          JOGO DA FORCA "<<endl;
    // cout<<"Digite o seu nome: "<<endl;
    // cin>>nome;

    // cout<<"DIFICULDADE"<<endl;
    // cout<<"1- Facil"<<endl;
    // cout<<"2- Medio"<<endl;
    // cout<<"3- Dificil"<<endl;

    // while(!ok){
    //     cout<<"Escolha uma dificuldade:"<<endl;
    //     cin>>dificuldade;

    //     if((dificuldade != '1')&&(dificuldade!= '2')&&(dificuldade != '3'))
    //         cout<<"Erro. Caractere invalido. Digite novamente."<<endl;
    //     else
    //         ok = true;
        
    // }

    // Jogador jogador(nome);

    // if(dificuldade == '1'){
    //     nivel = "FACIL";
    //     Palavra p1("ABACAXI", "FRUTA");
    //            Jogo jogo(jogador, p1);
    //                jogo.jogar();


    // }
    // else  if(dificuldade == '2'){
    //     nivel = "MEDIO";
    //     Palavra p2("MELANCIA", "FRUTA");
    //    Jogo jogo(jogador, p2);
    //        jogo.jogar();

    // }
    // else{
    //     nivel = "DIFICIL";
    //     Palavra p3("CHAMPEDAQUE", "FRUTA");
    //     Jogo jogo(jogador, p3);
    //         jogo.jogar();

    // }


    return 0;
}

/*REVER:
- SELECIONAR PALAVRA RANDOMICAMENTE
- TRATAMENTO DE ERRO

*/

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>


//#include "Palavra.h"
//#include "Jogador.h"
#include "Jogo.h"
#include "Arquivo.h"

using namespace std;

int main(){

    char opcao= 'A';
    string nomeJogador = "A";
    string nomePalavra;
    string dicaPalavra;


    // char continua='0';
    int pontos;
    // Arquivo arq("Pontuacoes");
    // arq.iniciarJogada();
    int continua=0;
            Arquivo file("Pontuacoes");

                    file.iniciarJogada();

    while(continua==0){
                system("clear");
                cout<<"Digite um nome: "<<endl;
                cin>>nomePalavra;
                cout<<"Digite pontos: "<<endl;
                cin>>pontos;
                cout<<"0 : ";
                cin >> continua;
                Jogador j(nomePalavra);
                j.setPontos(pontos);
                file.jogador.push_back(j);
                file.escreverJogada(j.getNome(),j.getPontos());
    
    }


    //     cout<<"Digite um nome: "<<endl;
    //     cin>>nomeJogador;
    //     cout<<"Pontos: "<<endl;
    //     cin>>pontos;
    //    // arq.iniciarJogada();
    //     Jogador j(nomeJogador);
    //     j.setPontos(pontos);
    //     arq.jogador.push_back(j);
    //     arq.escreverJogada(nomePalavra,pontos);
    //     cout<<"Continua : 0 : "<<endl;
    //     cin>>continua;

            
    // }
    // for (unsigned i=0; i<arq.jogador.size();i++)
    //     cout<<arq.jogador[i].getNome()<<" "<<arq.jogador[i].getPontos()<<endl;
//int pontos;
    // while(opcao!='0'){
    //     //Escrevendo o menu
    //     system("clear");
    //     cout<<"==================JOGO DA FORCA ==================="<<endl;
    //     cout<<"1- Jogar"<<endl;
    //     cout<<"2- Inserir palavra"<<endl;
    //     cout<<"3- Ranking"<<endl;
    //     cout<<"0- Sair"<<endl<<endl;
    //     cout<<"Escolha uma opcao: "<<endl;
    //     cin>>opcao;
    //     cout<<"==================================================="<<endl;

    //     switch(opcao){
    //         case '1':{ //jogar
    //             system("clear");
    //             cout<<"Digite o seu nome"<<endl;
    //             cin>>nomeJogador;

    //             Jogador jogador(nomeJogador);
    //             Arquivo file("Palavras");
    //             file.iniciarPalavras();
    //             srand(time(NULL));
    //             int indice = rand() % (file.palavra.size()+1);
    //             Jogo jogo(jogador, file.palavra[indice]);
    //             jogo.jogar();
    //             pontos = jogo.jogador.getPontos();

    //             //Arquivo file2("Pontuacoes");
    //             //file2.iniciarJogada();
    //             //files2.escreverJogada(nomeJogador, pontos);



    //         }
    //             break;
    //         case '2':{ //inserir palavra
    //             Arquivo file("Palavras");
    //             file.iniciarPalavras();
    //             system("clear");
    //             cout<<"Digite uma palavra: "<<endl;
    //             cin>>nomePalavra;
    //             cout<<"Digite uma dica: "<<endl;
    //             cin>>dicaPalavra;

    //             //convertendo para maiusculo
    //             for(unsigned i=0;i<nomePalavra.size();i++)
    //                 nomePalavra[i] = toupper(nomePalavra[i]);
    //             for(unsigned i=0;i<dicaPalavra.size();i++)
    //                 dicaPalavra[i] = toupper(dicaPalavra[i]);

    //             Palavra palavra(nomePalavra,dicaPalavra);
    //             file.palavra.push_back(palavra);
    //             file.escreverPalavra(palavra.getNome(),palavra.getDica(),palavra.getDificuldade());
    //         }
    //             break;
    //         case '3':{//ranking
   
    //         //    Arquivo file("Pontuacoes");
    //         //     file.iniciarJogada();
    //         //     for(unsigned i=0; i< file.jogador.size(); i++)
    //         //         cout<<file.jogador[i].getNome()<<" "<<file.jogador.getPontos()<<endl;
    //         }        
    //             break;
    //         case '0':
    //             //sair
    //             break;
    //         default:
    //             cout<<"Erro. Opcao invalida"<<endl;

    //     }

    // }

   





//     string palavra;
//     string dica;
//     //bool ok=false;

//     // system("clear");
//     // cout()

// //     arq.iniciarPalavras();
// //     // int numero = arq.palavra.size();
// //    int continua=0;

// //        // int kkk = arq.limparArquivo();
// //     system("clear");
// //    // arq.iniciarPalavras();

// //         // for(unsigned i=0;i<arq.palavra.size();i++)
// //         // cout<<arq.palavra[i].getNome()<<" "<<arq.palavra[i].getDica()<<endl;
// //     while(continua==0){
// //             int numero = arq.palavra.size()+1;

// //             cout<<arq.palavra.size()<<endl;

// //         system("clear");
// //         cout<<"Escreva uma palavra:"<<endl;
// //         cin>> palavra;
// //         cout<<"Escreva uma dica:"<<endl;
// //         cin>> dica;
// //         cout<<"Continua? 0 sim "<<endl;
// //         cin>>continua;
// //         Palavra p(palavra, dica);
// //         arq.palavra.push_back(p);
// //         arq.escreverPalavra(palavra,dica, p.getDificuldade());

// //         // if(continua == 's')
// //         //     ok=true;
            
// //     }

// //     //cout<<arq.encontrarPalavra ("FACIL")<<endl;
// //     //cout<<arq.palavraEscolhida.getNome()<<endl;


// //     // for(unsigned i=0;i<arq.palavra.size();i++)
// //     //     cout<<arq.palavra[i].getNome()<<" "<<arq.palavra[i].getDica()<<endl;
// //     cout<<arq.palavra.size();
// //     srand(time(NULL));
// // 	int	indice = rand() % (arq.palavra.size()+1);
// //     Jogador j("GABRIEL");
    
// //     //cout<<"ELEMENTOS = "<<arq.palavra.size()<<endl;
// //     Jogo jogo(j,arq.palavra[indice]);
// //     jogo.jogar();

// //     // system("clear");

// //     // cout<<"          JOGO DA FORCA "<<endl;
// //     // cout<<"Digite o seu nome: "<<endl;
// //     // cin>>nome;

// //     // cout<<"DIFICULDADE"<<endl;
// //     // cout<<"1- Facil"<<endl;
// //     // cout<<"2- Medio"<<endl;
// //     // cout<<"3- Dificil"<<endl;

// //     // while(!ok){
// //     //     cout<<"Escolha uma dificuldade:"<<endl;
// //     //     cin>>dificuldade;

// //     //     if((dificuldade != '1')&&(dificuldade!= '2')&&(dificuldade != '3'))
// //     //         cout<<"Erro. Caractere invalido. Digite novamente."<<endl;
// //     //     else
// //     //         ok = true;
        
// //     // }

// //     // Jogador jogador(nome);

// //     // if(dificuldade == '1'){
// //     //     nivel = "FACIL";
// //     //     Palavra p1("ABACAXI", "FRUTA");
// //     //            Jogo jogo(jogador, p1);
// //     //                jogo.jogar();


// //     // }
// //     // else  if(dificuldade == '2'){
// //     //     nivel = "MEDIO";
// //     //     Palavra p2("MELANCIA", "FRUTA");
// //     //    Jogo jogo(jogador, p2);
// //     //        jogo.jogar();

// //     // }
//     // else{
//     //     nivel = "DIFICIL";
//     //     Palavra p3("CHAMPEDAQUE", "FRUTA");
//     //     Jogo jogo(jogador, p3);
//     //         jogo.jogar();

//     // }


    return 0;
}

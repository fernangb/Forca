#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

#include "Jogo.h"
#include "Arquivo.h"

using namespace std;

int main(){

    char opcao= 'A';
    string nomeJogador = "A";
    string nomePalavra;
    string dicaPalavra;
    char dificuldade;
    string nivel;
    int indice;

    while(opcao!='0'){
        //Escrevendo o menu
        system("clear");
        cout<<"==================JOGO DA FORCA ==================="<<endl;
        cout<<"1- Jogar"<<endl;
        cout<<"2- Inserir palavra"<<endl;
        cout<<"3- Ranking"<<endl;
        cout<<"0- Sair"<<endl<<endl;
        cout<<"Escolha uma opcao: "<<endl;
        cin>>opcao;
        cout<<"==================================================="<<endl;

        switch(opcao){
            case '1':{ //jogar
                system("clear");
                cout<<"Digite o seu nome"<<endl;
                cin>>nomeJogador;
                do{

                    cout<<"Escolha a dificuldade: "<<endl;
                    cout<<"1- Facil"<<endl;
                    cout<<"2- Medio"<<endl;
                    cout<<"3- Dificil"<<endl;
                    cin>>dificuldade;
                    if(dificuldade!='1' && dificuldade!='2' && dificuldade!='3'){
                        system("clear");
                        cout<<"Erro. Opcao Invalida"<<endl;
                    }
                }while(dificuldade!='1' && dificuldade!='2' && dificuldade!='3');
                
                Jogador jogador(nomeJogador);
                Arquivo file("Palavras");
                file.lerPalavrasProVector();

                switch(dificuldade){
                    case '1':
                        nivel = "FACIL";
                        break;
                    case '2':
                        nivel = "MEDIO";
                        break;
                    default:
                        nivel = "DIFICIL";
                }

                //Escolhendo uma palavra com a dificuldade desejada
                do{
                    srand(time(NULL));
                    indice = rand() % (file.palavra.size()+1);
                }while(file.palavra[indice].getDificuldade() != nivel);

                Jogo jogo(jogador, file.palavra[indice]);
                jogo.jogar();
            }
                break;
            case '2':{ //inserir palavra
                Arquivo file("Palavras");
                file.lerPalavrasProVector();
                system("clear");
                cout<<"Digite uma palavra: "<<endl;
                cin>>nomePalavra;
                cout<<"Digite uma dica: "<<endl;
                cin>>dicaPalavra;

                //convertendo para maiusculo
                for(unsigned i=0;i<nomePalavra.size();i++)
                    nomePalavra[i] = toupper(nomePalavra[i]);
                for(unsigned i=0;i<dicaPalavra.size();i++)
                    dicaPalavra[i] = toupper(dicaPalavra[i]);

                Palavra palavra(nomePalavra,dicaPalavra);
                file.palavra.push_back(palavra);
                file.escreverPalavra(palavra.getNome(),palavra.getDica(),palavra.getDificuldade());
            }
                break;
            case '3':{//ranking

                Arquivo file("Pontuacoes");
                file.lerJogadorProVector();
                file.rankearJogadores();


            }        
                break;
            case '0':
                //sair
                break;
            default:
                cout<<"Erro. Opcao invalida"<<endl;

        }

    }
    return 0;
}

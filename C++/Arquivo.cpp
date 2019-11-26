#include "Arquivo.h"

Arquivo::Arquivo(string nome){
    nomeArquivo = nome + ".txt";;
}

void  Arquivo::verificarArquivoAberto () {
	if (!arquivo.is_open ()) {
		cout << "Erro ao abrir o arquivo." << endl;
		exit (1);
	}
}

void  Arquivo::lerPalavrasProVector () {
	//abre o arquivo texto

	string linhaArquivo; //string que recebe a linha inteira do arquivo
	unsigned linha = 0;
	string sId; //string do codigo, que sera convertido em int
    string sNome;
    string sDica;
	//int id;

	arquivo.open (nomeArquivo, fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto ();

	while ((!arquivo.eof () )) {

		unsigned caracteres = 0;
		getline (arquivo, linhaArquivo);

		if (linha > 0) { //verifica se o arquivo esta vazio para não haver erros (segmental fault), lembrando que ele ignora

			for (unsigned x = 0; x < linhaArquivo.size (); x++) {
					caracteres++; //serve para verificar se a linha está vazia, pois se estiver o objeto user não é adicionado ao vetor
			}

			if (linhaArquivo.size() >= 5) {
				sNome = linhaArquivo.substr (0, 20);  
				sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());
				sDica = linhaArquivo.substr (20, linhaArquivo.size());  
				sDica.erase(remove(sDica.begin(), sDica.end(), ' '), sDica.end());
			}
			Palavra p(sNome, sDica);

			if (caracteres != 0) {
				palavra.push_back (p);	

			}
		}

		linha++;

	}

	arquivo.close ();

}

void  Arquivo::escreverPalavra(string nome, string dica, string dificuldade){
   	arquivo.open (nomeArquivo.c_str(), fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto (); 
	arquivo <<setw(20) << nome << setw(20) << dica<<endl;//<<setw(20)<<dificuldade<<endl;
    arquivo.close();
}

void  Arquivo::escreverJogada(string nome, int pontos){
   	arquivo.open (nomeArquivo.c_str(), fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto (); 
	arquivo <<setw(20)<<nome<<setw(20)<<pontos<<endl;
    arquivo.close();

}


void  Arquivo::lerJogadorProVector () {
	//abre o arquivo texto

	string linhaArquivo; //string que recebe a linha inteira do arquivo
	unsigned linha = 0;
	string sId; //string do codigo, que sera convertido em int
    string sNome;
    string sPontos;
	int pontos;

	arquivo.open (nomeArquivo, fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto();

	while (!(arquivo.eof() - 1)) {
		unsigned caracteres = 0;
		getline (arquivo, linhaArquivo);

		if (linha > 0) { //verifica se o arquivo esta vazio para não haver erros (segmental fault), lembrando que ele ignora

			for (unsigned x = 0; x < linhaArquivo.size (); x++) {
					caracteres++; //serve para verificar se a linha está vazia, pois se estiver o objeto user não é adicionado ao vetor
			}
			sNome = linhaArquivo.substr(0,20);
			sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());

			sPontos = linhaArquivo.substr (20, linhaArquivo.size());  
			sPontos.erase(remove(sPontos.begin(), sPontos.end(), ' '), sPontos.end());
			pontos = atoi(sPontos.c_str());

			//cout<<sNome<<" "<<pontos<<endl;

			Jogador j(sNome);
			j.setPontos(pontos);

			if (caracteres != 0) {
				jogador.push_back (j);	
			}
		}
		linha++;
	}
	arquivo.close ();
}

void Arquivo:: rankearJogadores(){
	//sort(jogador.begin(), jogador.end(), compararJogadores);
	char sair;

	for(unsigned i = 0; i<jogador.size();i++){
		for(unsigned j = 0; j<jogador.size();j++){
			if(jogador.at(j).getPontos() > jogador.at(j).getPontos()){
				Jogador aux = jogador.at(i);
				jogador.at(i) = jogador.at(j);
				jogador.at(j) = aux;
			}


		}
	}

	cout<<"Posicao"<<setw(5)<<"Jogador"<<setw(15)<<"Pontos"<<endl;
	for(unsigned i=0; i< jogador.size(); i++)
		cout<< i+1 <<setw(5)<<jogador.at(i).getNome()<<setw(15)<<jogador.at(i).getPontos()<<endl;

    cout<<"Digite qualquer tecla e depois ENTER para voltar ao menu inicial ..."<<endl;
    cin>>sair;

}


/*
    for (int i = 0; i < jogadores.size(); i++) {
        for (int j = 0; j < jogadores.size(); j++) {
            if (jogadores[j]->getExperiencia() < jogadores[i]->getExperiencia()) {
                Jogador *temp = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = temp;
            }
        }
    }
*/

// static bool Arquivo:: compararJogadores(Jogador &a, Jogador &b){
// 	return a.getPontos() < b.getPontos();
// }

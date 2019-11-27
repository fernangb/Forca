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

	string linhaArquivo; //string que recebe a linha inteira do arquivo
	unsigned linha = 0;
    string sNome;
    string sDica;
	string sDificuldade;

	arquivo.open (nomeArquivo, fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto ();

	while (getline (arquivo, linhaArquivo)) {

		unsigned caracteres = 0;

		if (linha >= 0) { //verifica se o arquivo esta vazio para não haver erros (segmental fault), lembrando que ele ignora

			for (unsigned x = 0; x < linhaArquivo.size (); x++) {
					caracteres++; //serve para verificar se a linha está vazia, pois se estiver o objeto user não é adicionado ao vetor
			}

			if (linhaArquivo.size() >= 5) {
				sNome = linhaArquivo.substr (0, 20);  
				sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());
				sDica = linhaArquivo.substr (20, 20);//linhaArquivo.size());  
				sDica.erase(remove(sDica.begin(), sDica.end(), ' '), sDica.end());
				sDificuldade = linhaArquivo.substr (40,20);// linhaArquivo.size());  
				sDificuldade.erase(remove(sDificuldade.begin(), sDificuldade.end(), ' '), sDificuldade.end());
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
	arquivo <<setw(20) << nome << setw(20) << dica<<setw(20)<<dificuldade<<endl;
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

	while (getline (arquivo, linhaArquivo)) {
		unsigned caracteres = 0;

		if (linha >= 0) { //verifica se o arquivo esta vazio para não haver erros (segmental fault), lembrando que ele ignora

			for (unsigned x = 0; x < linhaArquivo.size (); x++) {
					caracteres++; //serve para verificar se a linha está vazia, pois se estiver o objeto user não é adicionado ao vetor
			}
			sNome = linhaArquivo.substr(0,20);
			sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());

			sPontos = linhaArquivo.substr (20, linhaArquivo.size());  
			sPontos.erase(remove(sPontos.begin(), sPontos.end(), ' '), sPontos.end());
			pontos = atoi(sPontos.c_str());

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
			if(jogador.at(i).getPontos() > jogador.at(j).getPontos()){
				Jogador aux = jogador.at(i);
				jogador.at(i) = jogador.at(j);
				jogador.at(j) = aux;
			}


		}
	}

	cout<<"POS"<<setw(20)<<"JOGADOR"<<setw(20)<<"PONTOS"<<endl;
	cout<<"==================================================="<<endl;
	for(unsigned i=0; i< jogador.size(); i++){
		if(i<9){
			cout<< "00"<<i+1 <<setw(20)<<jogador.at(i).getNome()<<setw(20)<<jogador.at(i).getPontos()<<endl;
		}else if(i<99){
			cout<<"0"<<i+1 <<setw(20)<<jogador.at(i).getNome()<<setw(20)<<jogador.at(i).getPontos()<<endl;
		}else{
			cout<< i+1 <<setw(20)<<jogador.at(i).getNome()<<setw(20)<<jogador.at(i).getPontos()<<endl;

		}
	}
    cout<<"Digite qualquer tecla e depois ENTER para voltar ao menu inicial ..."<<endl;
    cin>>sair;

}


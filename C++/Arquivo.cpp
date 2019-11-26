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

void  Arquivo::iniciarPalavras () {
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

			//sNome = linhaArquivo.substr(0,20);
			//sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());

			if (linhaArquivo.size() >= 5) {
				sNome = linhaArquivo.substr (0, 20); //pega apenas o "meio" da string, que contem o nome do user e espaços
				sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());
				sDica = linhaArquivo.substr (20, linhaArquivo.size()); //deleta os 30 primeiros caracteres da string, pegando o rating
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
void  Arquivo::lerLinhasArquivo () {
	string linha;

	arquivo.open (nomeArquivo.c_str (), fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto ();

	while (!arquivo.eof ()) {
		getline (arquivo, linha);
		cout << linha << endl;
	}

	arquivo.close ();
}

void  Arquivo::mostrarVectorPalavras () {

	for (unsigned i = 0; i < palavra.size(); i++) {
		cout << setw(20) << palavra.at(i).getNome()
			 << setw(20) << palavra.at(i).getDica() << endl;
		
	}
}

string  Arquivo::encontrarPalavra (string dificuldade) {
	int indice;
	string nome;
	string dica;
	do{
		indice = rand()%palavra.size();
		
		if(palavra[indice].getDificuldade() == dificuldade){
			nome = palavra[indice].getNome();
			dica = palavra[indice].getDica();
		}

	}while(palavra[indice].getDificuldade() != dificuldade);
	// palavraEscolhida(nome, dica);
	return "oi";
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


void  Arquivo::iniciarJogada () {
	//abre o arquivo texto

	string linhaArquivo; //string que recebe a linha inteira do arquivo
	unsigned linha = 0;
	string sId; //string do codigo, que sera convertido em int
    string sNome;
    string sPontos;
	int pontos;

	arquivo.open (nomeArquivo, fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto ();

	while ((!arquivo.eof () )) {
		unsigned caracteres = 0;
		getline (arquivo, linhaArquivo);

		if (linha > 0) { //verifica se o arquivo esta vazio para não haver erros (segmental fault), lembrando que ele ignora

			for (unsigned x = 0; x < linhaArquivo.size (); x++) {
					caracteres++; //serve para verificar se a linha está vazia, pois se estiver o objeto user não é adicionado ao vetor
			}
			sNome = linhaArquivo.substr(0,20);
			sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());


			sPontos = linhaArquivo.substr (20,linhaArquivo.size()); //deleta os 30 primeiros caracteres da string, pegando o rating
			sPontos.erase(remove(sPontos.begin(), sPontos.end(), ' '), sPontos.end());
			pontos = atoi(sPontos.c_str());

			/*
	while ((!arquivo.eof () )) {

		unsigned caracteres = 0;
		getline (arquivo, linhaArquivo);

		if (linha > 0) { //verifica se o arquivo esta vazio para não haver erros (segmental fault), lembrando que ele ignora

			for (unsigned x = 0; x < linhaArquivo.size (); x++) {
					caracteres++; //serve para verificar se a linha está vazia, pois se estiver o objeto user não é adicionado ao vetor
			}

			if (linhaArquivo.size() >= 5) {
				sNome = linhaArquivo.substr (0, 20); //pega apenas o "meio" da string, que contem o nome do user e espaços
				sNome.erase(remove(sNome.begin(), sNome.end(), ' '), sNome.end());
				sDica = linhaArquivo.substr (20, linhaArquivo.size()); //deleta os 30 primeiros caracteres da string, pegando o rating
				sDica.erase(remove(sDica.begin(), sDica.end(), ' '), sDica.end());
			}
			Palavra p(sNome, sDica);

			if (caracteres != 0) {
				palavra.push_back (p);	

			}
		}

		linha++;

	}

			*/
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

void Arquivo:: lerPalavras(){
    ofstream escrita;
    string linha;

    arquivo.open(nomeArquivo, fstream::in | fstream::out | fstream::app);
    verificarArquivoAberto();

    

}


#include "arquivo.h"


 Arquivo:: Arquivo (string file) {
	fileName = file + ".txt";
}

 Arquivo::~ Arquivo () {
	//cout << "Fechando o arquivo" << endl;
}

void  Arquivo::verificarArquivoAberto () {
	if (!filestr.is_open ()) {
		cout << "Erro ao abrir o arquivo." << endl;
		exit (1);
	}
}
//Abrindo o arquivo de palavras e salvando num vector de palavras

void  Arquivo::iniciarVPalavras () {
	//abre o arquivo texto

	string linhaArquivo; //string que recebe a linha inteira do arquivo
	unsigned linha = 0;
	string sId; //string Id obtida do arquivo texto, será convertida para int depois
    string sPalavra;
    string sDica;
	int id;

	filestr.open (fileName.c_str (), fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto ();

	while ((!filestr.eof () )) {

		unsigned caracteres = 0;
		getline (filestr, linhaArquivo);

		if (linha > 0) { //verifica se o arquivo esta vazio para não haver erros (segmental fault), lembrando que ele ignora
						 //a primeira linha do arquivo que contem "ID     USER    RATING"
			sId = linhaArquivo.substr (0, 5); //string Id recebe os 5 primeiros caracteres do arquivo, pois sabe-se que 
											  //o arquivo começa com o identificador e 5 espaços, e o identificador tem no max 2 caract.

			//a linha abaixo remove os espaços em branco da string, portanto só havera a string contendo o numero de id
			sId.erase(remove(sId.begin(), sId.end(), ' '), sId.end());
			id = atoi (sId.c_str ()); //faz a conversão de string para inteiro

			for (unsigned x = 0; x < linhaArquivo.size (); x++) {
					caracteres++; //serve para verificar se a linha está vazia, pois se estiver o objeto user não é adicionado ao vetor
			}

			if (linhaArquivo.size() >= 5) {
				sPalavra = linhaArquivo.substr (5, linhaArquivo.size() - 7); //pega apenas o "meio" da string, que contem o nome do user e espaços
				sPalavra.erase(remove(sPalavra.begin(), sPalavra.end(), ' '), sPalavra.end());
				sDica = linhaArquivo.substr (30, linhaArquivo.size()); //deleta os 30 primeiros caracteres da string, pegando o rating
				sDica.erase(remove(sDica.begin(), sDica.end(), ' '), sDica.end());
			}
			Palavra palavra(id, sPalavra, sDica);

			if (caracteres != 0) {
				palavras.push_back (palavra);	//adiciona o objeto usuario ao vetor apenas se a linha não estiver vazia

			}
		}

		linha++;

	}

	filestr.close ();

}

void  Arquivo::escreverPalavraVector (int id, string nome, string dica) {

    Palavra palavra(id, nome, dica);

	palavra.setId (palavras.back().getId() + 1); //se o ultimo id for 9 o do novo usuario sera 10
										  //pega o numero do id do ultimo elemento do vetor e o novo será ele + 1

	palavras.push_back (palavra);

}


void  Arquivo::escreverVectorArquivo () {

	fstream copyFile;
	string fileNameCopy = "Palavrascopy.txt";
	string fileNameTemp = "Palavrastemp.txt";

	filestr.open (fileName.c_str (), fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto ();

	copyFile.open (fileNameCopy.c_str (), fstream::in | fstream::out | fstream::app);


	copyFile << setw(5) << "ID" << setw(15) << "PALAVRA" << setw(15) << "DICA" << endl;

	for (unsigned x = 0; x < palavras.size () ; x++ ) {
		copyFile << setw(5) << palavras.at(x).getId() << setw(15) << palavras.at(x).getNome() << setw(15) << palavras.at(x).getDica() << endl; 
	}


	rename ("Palavras.txt", "Palavrastemp.txt"); //arquivo original vira arquivo temporário
	rename ("Palavrascopy.txt", "Palavras.txt");

	filestr.close ();
	copyFile.close ();

}

void  Arquivo::lerLInhasArquivo () {
	string line;

	filestr.open (fileName.c_str (), fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto ();

	while (!filestr.eof ()) {
		getline (filestr, line);
		cout << line << endl;
	}

	filestr.close ();
}

void  Arquivo::mostrarVectorPalavras () {

	for (unsigned i = 0; i < palavras.size(); i++) {
		cout << setw(5) << palavras.at(i).getId() << setw(15) << palavras.at(i).getNome()
			 << setw(15) << palavras.at(i).getDica() << endl;
		
	}
}


int  Arquivo::encontrarPalavra (string nome) {

	for (unsigned x = 0; x < palavras.size () ; x++ ) {
		if (nome == palavras[x].getNome())
			return palavras[x].getId(); 
	}

	return notFindData; //retorna -1 caso nao encontre */ 

}

void  Arquivo::removeElement (int id) {  

	for (unsigned i = 0; i < palavras.size (); i++) {
		if (palavras[i].getId() == id) {
			palavras.erase (palavras.begin() + i); //elimina o elemento que tem o identificador
		}
	}

}

int  Arquivo::limparArquivo () {
	if (!remove (fileName.c_str())) 
		return -50;
	else 
		return -51;
	
}

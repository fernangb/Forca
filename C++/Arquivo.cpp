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
			// 			 //a primeira linha do arquivo que contem "ID     USER    RATING"
			//sId = linhaArquivo.substr (0, 5); //string Id recebe os 5 primeiros caracteres do arquivo, pois sabe-se que 
			// 								  //o arquivo começa com o identificador e 5 espaços, e o identificador tem no max 2 caract.

			// //a linha abaixo remove os espaços em branco da string, portanto só havera a string contendo o numero de id
			//sId.erase(remove(sId.begin(), sId.end(), ' '), sId.end());
			// id = atoi (sId.c_str ()); //faz a conversão de string para inteiro

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
	// iniciarPalavras();
	// remove(nomeArquivo.c_str());
   	arquivo.open (nomeArquivo.c_str(), fstream::in | fstream::out | fstream::app);
	verificarArquivoAberto (); 
	arquivo <<setw(20) << nome << setw(20) << dica;//<<setw(20)<<dificuldade<<endl;

    // for (unsigned x = 0; x < palavra.size () ; x++ ) {
	// 	arquivo << setw(5) << palavra[x].getCodigo() << setw(20) << palavra[x].getNome() << setw(40) << palavra[x].getDica() << endl; 
	// }

    arquivo.close();




	// fstream copyFile;
	// string arquivoCopy = "Palavrascopy.txt";
	// string arquivoTemp = "Palavrastemp.txt";

	// arquivo.open (nomeArquivo.c_str (), fstream::in | fstream::out | fstream::app);
	// verificarArquivoAberto ();

	// copyFile.open (arquivoCopy.c_str (), fstream::in | fstream::out | fstream::app);


	// //copyFile << setw(5) << "ID" << setw(15) << "PALAVRA" << setw(15) << "DICA" << endl;

	// for (unsigned x = 0; x < palavra.size () ; x++ ) {
	// 	copyFile << setw(5) << palavra[x].getCodigo() << setw(20) << palavra[x].getNome() << setw(40) << palavra[x].getDica() << endl; 
	// }


	// rename ("Palavras.txt", "Palavrastemp.txt"); //arquivo original vira arquivo temporário
	// rename ("Palavrascopy.txt", "Palavras.txt");

	// arquivo.close ();
	// copyFile.close ();

}


// void Arquivo:: escreverArquivo(Palavra p) : palavra(p.getNome(), p.getDica()){
//     arquivo.open(nomeArquivo, fstream::in | fstream::out | fstream::app);


    
// //     // ofstream arquivo;


// //     // arquivo.open("bbb.txt",ios::app);
// //     // arquivo << "OLA\n";
// //     //     arquivo << "tudo\n";
// //     //             arquivo << "ok\n";
// //     // arquivo.close();

// //     // return 0;
// }

void Arquivo:: lerPalavras(){
    ofstream escrita;
    string linha;

    arquivo.open(nomeArquivo, fstream::in | fstream::out | fstream::app);
    verificarArquivoAberto();
    while(!arquivo.eof()){

    }


//       arquivo.open("bbb.txt");
//   while(!arquivo.eof()){
//     getline(arquivo,texto);
//     palavra = texto.substr(0,19);
//     palavra.erase(remove(palavra.begin(), palavra.end(), ' '), palavra.end());

//     // palavra = texto.substr(0,19);
//     // dica = texto.substr(20, texto.size());
//     // cout<<palavra<<endl;
//     // cout<<dica<<endl<<endl;
//     //cout<<texto<<endl;
//   }
//   arquivo.close();

}

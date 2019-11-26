
#include </usr/lib/x86_64-linux-gnu/perl/5.26.1/CORE/EXTERN.h>
#include </usr/lib/x86_64-linux-gnu/perl/5.26.1/CORE/perl.h>


#include <iostream>
#include <string>
#include <EXTERN.h>
#include <perl.h>

using namespace std;

class PerlParaCpp {

	public:

		PerlParaCpp (string);
		~PerlParaCpp ();
		void Interpretador ();

       void adicionarPalavra(string, string); //adicionar palavra
        void escolherDificuldade(string);//escolher nivel de dificuldade
        string escolherPalavra(string);//escolher palavra
        void salvarPontuacao(string, string);//salvar pontuacao
        int ranking(string);//ranking
        

		// string asteriscos (string);
		// string leetShift (string);
		// //retorna o numero de palavras censuradas
		// int countWords (string );
		// string censureText (string );
		
	private:

		PerlInterpreter *my_perl;
		char *my_argv[2];

};
//#include <stddef.h>
#include <string>
#include "PerlParaCpp.h"

using namespace std;


EXTERN_C void xs_init (pTHX);
EXTERN_C void boot_DynaLoader (pTHX_ CV* cv);
EXTERN_C void xs_init(pTHX) {
	static const char file[] =__FILE__;
	dXSUB_SYS;
	PERL_UNUSED_CONTEXT;
	newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file); }

PerlParaCpp::PerlParaCpp (string script = "tst") {


	int forca_argc = 0;
	char*** forca_env = 0;
	//char string[] = {};
	//char* dummy_argv[] = {string, &script[0]};
	PERL_SYS_INIT3(&forca_argc, forca_env, forca_env);
	my_perl = perl_alloc();
	perl_construct(my_perl);
	PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

}

PerlParaCpp::~PerlParaCpp () {

	perl_destruct(my_perl);
	perl_free(my_perl);
	PERL_SYS_TERM();

}

void PerlParaCpp::Interpretador () {

	char _MYARGV_PERL_MODULE_NAME [] = "Modulo.pl"; 
	char _MYARGV_NOTHING_NAME[] = "";
	char *my_argv[] = { static_cast<char*> (_MYARGV_NOTHING_NAME), 
			    static_cast<char*> (_MYARGV_PERL_MODULE_NAME)
			  }; 

	perl_parse (my_perl, xs_init, 2, my_argv, NULL);
	perl_run (my_perl);

}

void PerlParaCpp::adicionarPalavra (string palavra, string dica) {

	dSP;
	ENTER;
	SAVETMPS;
	PUSHMARK(SP);
 
	//string dadosCens;
 
	XPUSHs (sv_2mortal (newSVpv(palavra.c_str(), palavra.length())));
	
	PUTBACK;
 
	call_pv("adicionar_palavra", G_SCALAR);
	SPAGAIN;
  
	//dadosCens = POPp;
 
	PUTBACK;
	FREETMPS;
	LEAVE;

	//return dadosCens;

}

void PerlParaCpp::escolherDificuldade (string dificuldade) {

	dSP;
	ENTER;
	SAVETMPS;
	PUSHMARK(SP);
 
	//string dadosCens;
 
	XPUSHs (sv_2mortal (newSVpv(dificuldade.c_str(), dificuldade.length())));
	
	PUTBACK;
 
	call_pv("escolher_dificuldade", G_SCALAR);
	SPAGAIN;
  
	//dadosCens = POPp;
 
	PUTBACK;
	FREETMPS;
	LEAVE;

	//return dadosCens;

}

    //     void escolherPalavra()//escolher palavra

    string PerlParaCpp::escolherPalavra (string dificuldade) {

	dSP;
	ENTER;
	SAVETMPS;
	PUSHMARK(SP);
 
	string palavra;
 
	XPUSHs (sv_2mortal (newSVpv(dificuldade.c_str(), dificuldade.length())));
	
	PUTBACK;
 
	call_pv("escolher_palavra", G_SCALAR);
	SPAGAIN;
  
	palavra = POPp;
 
	PUTBACK;
	FREETMPS;
	LEAVE;

	return palavra;

}

    void PerlParaCpp::salvarPontuacao (string jogador, string pontos) {

	dSP;
	ENTER;
	SAVETMPS;
	PUSHMARK(SP);
 
	//string dadosCens;
 
	XPUSHs (sv_2mortal (newSVpv(jogador.c_str(), jogador.length())));
	
	PUTBACK;
 
	call_pv("salvar_pontuacao", G_SCALAR);
	SPAGAIN;
  
	//dadosCens = POPp;
 
	PUTBACK;
	FREETMPS;
	LEAVE;

	//return dadosCens;

}
int PerlParaCpp::ranking (string jogador) {

	dSP;
	ENTER;
	SAVETMPS;
	PUSHMARK(SP);
 
	int posicao;

	XPUSHs (sv_2mortal (newSVpv(jogador.c_str(), jogador.length())));
	
	PUTBACK;

	call_pv("ranking", G_SCALAR);
	SPAGAIN;

	posicao = POPi;

	PUTBACK;
	FREETMPS;
	LEAVE;

	return posicao;

}


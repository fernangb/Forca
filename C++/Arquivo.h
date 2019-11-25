#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include <stdio.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>

#include "Palavra.h"

using namespace std;

class Arquivo{
    public:
        Arquivo(string);
        void lerPalavras();
        void escreverPalavra(string, string, string);
        void verificarArquivoAberto();
        void iniciarPalavras();
        void lerLinhasArquivo();
        void mostrarVectorPalavras();
        string encontrarPalavra(string);
        int limparArquivo();
        // Palavra palavraEscolhida;   

        vector <Palavra> palavra;
    private:
        string nomeArquivo;
        fstream arquivo;
        // Palavra palavraEscolhida;   

};
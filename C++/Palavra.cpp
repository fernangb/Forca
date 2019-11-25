#include "Palavra.h"
#include <string>
#include <vector>
#include <cctype>

using namespace std;

Palavra::Palavra(string p, string d ){
    nome = p;
    dica = d;
    // for(unsigned i=0; i<p.size();i++)
    //     nome[i] = toupper(p[i]);
    // for(unsigned i=0; i<p.size();i++)
    //     dica[i] = toupper(d[i]);

    numLetras = p.size();
    // codigo = id;
    numLetrasDiferentes = calcularLetrasDiferentes();
    dificuldade = calcularDificuldade();
}

int Palavra:: getCodigo(){
    return codigo;
}
void Palavra:: setCodigo(int id){
    codigo = id;
}

string Palavra:: getNome(){
    return nome;
}

string Palavra:: getDica(){
    return dica;
}

string Palavra:: getDificuldade(){
    return dificuldade;
}

unsigned Palavra:: getNumLetrasDiferentes(){
    return numLetrasDiferentes;
}

unsigned Palavra:: getNumLetras(){
    return numLetras;
}

unsigned Palavra:: calcularLetrasDiferentes(){
    vector <char> letrasDiferentes;
    unsigned contaLetras;

    for (unsigned i=0; i<numLetras;i++){
        contaLetras=0;
        if(i==0)
            letrasDiferentes.push_back(nome[i]);
        else{
            for (unsigned j =0; j<letrasDiferentes.size(); j++)
                if(nome[i] != letrasDiferentes[j])
                    contaLetras++;
    
            if(contaLetras == letrasDiferentes.size()){
                letrasDiferentes.push_back(nome[i]);
            }
        }
    }

    return letrasDiferentes.size();
}


string Palavra:: calcularDificuldade(){
    int valor = numLetras*numLetrasDiferentes;
    
    if(valor<=FACIL)
        return "FACIL";

    if(valor<=MEDIO)
        return "MEDIO";

    return "DIFICIL";
}

bool Palavra:: VerificarPalavra(){
    string alfabeto = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    bool existeLetra;
    bool existePalavra = true;

    for(unsigned i=0; i<numLetras;i++){
        existeLetra = false;
        for(unsigned j=0; j<alfabeto.size(); j++)
            if(nome[i] == alfabeto[j])
                existeLetra = true;
        existePalavra = existePalavra && existeLetra;
    }
    return existePalavra;
}
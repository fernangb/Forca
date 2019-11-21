#include "Palavra.h"
#include <string>
#include <vector>

using namespace std;

Palavra::Palavra(string p, string d ){
    nome = p;
    numLetras = p.size();
    dica = d;
    numLetrasDiferentes = calcularLetrasDiferentes();
    dificuldade = calcularDificuldade();
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
    
    if(valor<=20)
        return "FACIL";

    if(valor<=50)
        return "MEDIO";

    return "DIFICIL";
}

bool Palavra:: VerificarPalavra(){
    string alfabeto = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    bool existeLetra;
    bool existePalavra = true;

    for(unsigned i=0; i<numLetras;i++){
        existeLetra = false;
        for(unsigned j=0; j<26; j++)
            if(nome[i] == alfabeto[j])
                existeLetra = true;
        existePalavra = existePalavra && existeLetra;
    }
    return existePalavra;
}
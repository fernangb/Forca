#include "Palavra.h"
#include <string>
#include <vector>
#include <cctype>

using namespace std;

Palavra::Palavra(string p, string d ){
    nome = p;
    dica = d;
    numLetras = p.size();
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
    unsigned vogais=0;

    for(unsigned i=0; i<numLetras; i++)
        if(nome[i] == 'A' || nome[i] == 'E' || nome[i] == 'I' || nome[i] == 'O' || nome[i] == 'U' )
            vogais++;

    int valor = (numLetras*(numLetrasDiferentes+1)) - vogais;
    
    if(valor<=FACIL)
        return "FACIL";

    if(valor<=MEDIO)
        return "MEDIO";

    return "DIFICIL";
}
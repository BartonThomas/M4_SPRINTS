// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int leComando(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){
  cout << "Digite o Comando (0 ou 1): ";
	int cmd = leComando();
	cout << "Comando Recebido: " << cmd << endl;
}
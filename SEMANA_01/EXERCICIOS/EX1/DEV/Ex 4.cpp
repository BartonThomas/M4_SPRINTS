// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string dirMaiorDist(int Vetor[]){
    if(Vetor[0]>Vetor[1]){
        if(Vetor[0]>Vetor[2]){
            if(Vetor[0]>Vetor[3]){
                string direction = "Direita";
                return direction;
            }
            else{
                string direction = "Tras";
                return direction;
            }
        }
        else{
            if(Vetor[2]>Vetor[3]){
                string direction = "Frente";
                return direction;
            }
            else{
                string direction = "Tras";
                return direction;
            }
        }
    }
    else{
        if(Vetor[1]>Vetor[2]){
            if(Vetor[1]>Vetor[3]){
                string direction = "Esquerda";
                return direction;
            }
            else{
                string direction = "Tras";
                return direction;
            }
        }
        else{
            if(Vetor[2]>Vetor[3]){
                string direction = "Frente";
                return direction;
            }
            else{
                string direction = "Tras";
                return direction;
            }
        }
    }
}

int maiorDist(int Vetor[]){
    if(Vetor[0]>Vetor[1]){
        if(Vetor[0]>Vetor[2]){
            if(Vetor[0]>Vetor[3]){
                return Vetor[0];
            }
            else{
                return Vetor[3];
            }
        }
        else{
            if(Vetor[2]>Vetor[3]){
                return Vetor[2];
            }
            else{
                return Vetor[3];
            }
        }
    }
    else{
        if(Vetor[1]>Vetor[2]){
            if(Vetor[1]>Vetor[3]){
                return Vetor[1];
            }
            else{
                return Vetor[3];
            }
        }
        else{
            if(Vetor[2]>Vetor[3]){
                return Vetor[2];
            }
            else{
                return Vetor[3];
            }
        }
    }
}

int main(){
  int posicoes [4] = {0, 20, 100, 50};
  
  cout << dirMaiorDist(posicoes) << endl;
  //valor esperado: Frente
  cout << maiorDist(posicoes) << endl;
  //valor esperado: 100
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes2 [4] = {95, 70, 80, 50};
  cout << dirMaiorDist(posicoes2) << endl;
  //valor esperado: Direita
  cout << maiorDist(posicoes2) << endl;
  //valor esperado: 95
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes3 [4] = {10, 0, 50, 60};
  cout << dirMaiorDist(posicoes3) << endl;
  //valor esperado: Tras
  cout << maiorDist(posicoes3) << endl;
  //valor esperado: 60
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes4 [4] = {54, 55, 30, 0};
  cout << dirMaiorDist(posicoes4) << endl;
  //valor esperado: Esquerda
  cout << maiorDist(posicoes4) << endl;
  //valor esperado: 55
}
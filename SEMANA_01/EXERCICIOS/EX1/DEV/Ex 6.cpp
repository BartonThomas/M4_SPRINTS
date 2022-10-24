// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos obaetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seaa enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções aá construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seaa 
// enviado pelo usuário. 

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int getMovement(int Numbers[]){
  int dist[4] = {};
  string loc[4] = {"Direita", "Esquerda", "Frente", "Tras"};
  string dir[4] = {};
  for (int i=0; i <=3; i++) {
    dist[i] = Numbers[i];
  }
  int x = 4;
    for(int i=0;i<x;i++){		
		for(int a=i+1;a<x;a++){
			if(dist[i]<dist[a])
			{
				int temp = dist[i];
        dir[i]= i;
				dist[i] = dist[a];
				dist[a] = temp;
        dir[i] = a;
			}
		}
	}
  for (int i = 0; i<=3; i++){
    for (int a =0; a<= 3; a++){
      if (dist[a] == Numbers[i]){
        dir[a] = loc[i];
      }
    }
  }
    cout<< dir[0] << " " << dir[1] << " " << dir[2] << " " << dir[3]<<endl;
    cout<< dist[0] << " " << dist[1] << " " << dist[2] << " " << dist[3]<<endl;
    return 0;
}

int main(){
  int x = 1;
  while(x==1){
    int array [4];
    cout << "Insira os quatro valores de movimento: ";
    scanf("%d %d %d %d", &array[0], &array[1], &array[2], &array[3]);
    cout << "\n\n" << getMovement(array);
    cout << "\nDeseja continuar? (1 - sim// 2 - nao)";
    scanf("%d", &x);
  }
}
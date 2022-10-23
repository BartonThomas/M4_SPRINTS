// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int continuar(){
    int x;
    cout << "Digite 1 para parar o mapeamento!" << endl;
    cin >> x;
    if(x==1){
        return 1;
    }
    return 0;
}

int main(){
    int parar = 0;

    while (parar == 0){
    parar = continuar();
    }
    //A função deve perguntar: "Digite 1 para parar o mapeamento!"
    //Se o usuário digitar 1, deve sair do loop while declarado acima
    // Em caso contrário, continua no loop acima e pergunta novamente
    return 1;
}
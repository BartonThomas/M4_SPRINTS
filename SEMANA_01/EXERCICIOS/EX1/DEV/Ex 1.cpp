// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int converteSensor(int medida, int min, int max){
    int a;
    a = (medida - min)/((max - min)/100);
    return a;
}

int main(){
  cout << "Teste Ex 1" << endl;
	cout << converteSensor(100,100,400) << endl;
  
	cout << converteSensor(400,100,400) << endl;
  
	cout << converteSensor(250,100,400) << endl;
}
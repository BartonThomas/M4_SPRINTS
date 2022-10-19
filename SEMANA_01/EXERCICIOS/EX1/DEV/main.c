// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

#include<stdio.h>

int main(){
    float x,y,a,z;
    printf("insira dois valores:\n");
    scanf("%f %f", &x, &y);
    printf("insira um valor do meio:\n");
    scanf("%f", &z);
    if(x>y){
        a = (z - y)/((x - y)/100);
        printf("O valor %d esta na porcentagem %d entre %d e %d", (int)z,(int)a,(int)y,(int)x);
    }
    else{
        a = (z - x)/((y - x)/100);
        printf("O valor %d esta na porcentagem %d entre %d e %d", (int)z,(int)a,(int)x,(int)y);
    }
}
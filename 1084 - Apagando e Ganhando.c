#include <stdio.h>

int main(){

    int digitos, apagar,apagou, topo, i, j;

    while(1){

        topo = -1;
        apagou = 0;
        i = 0; j = 0;
        char numeros[1000000];
        char sim_pilha[1000000];
        scanf("%d", &digitos);
        scanf("%d", &apagar);
        if(digitos == 0 && apagar == 0){
            return 0;
        }
        scanf("%s", numeros);


        for(i = 0; i < digitos; i++){
            while(topo > -1 && numeros[i] > sim_pilha[topo] && apagou < apagar){
                topo--;
                apagou++;
            }
            topo++;
            sim_pilha[topo] = numeros[i];
        }

        for(j = 0; j < digitos-apagar; j++){
            printf("%c", sim_pilha[j]);
        }
        printf("\n");
    }

    return 0;
}

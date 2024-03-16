#include <stdio.h>
#include <stdlib.h>

int merge(int tamanhotrem, int trem[], int s);

int main () {

    int casosdeteste, tamanhotrem, trem[50], contador;

    scanf("%d", &casosdeteste);
    
    for (int i=1; i<=casosdeteste; i++) {
        scanf("%d", &tamanhotrem);
        contador = 0;    
        for (int k=0; k<tamanhotrem; k++) {
            scanf("%d", &trem[k]);
        }
        merge (tamanhotrem, trem, contador);
    }
    return 0;
}

int merge(int tamanhotrem, int trem[], int contador){
    
    int direita, esquerda, auxiliar;
    for (direita = 0; direita < tamanhotrem; direita++) {
        for(esquerda = direita+1; esquerda < tamanhotrem; esquerda++){
            if ( trem[direita] > trem[esquerda] ){
                  auxiliar = trem[direita];
                  trem[direita] = trem[esquerda];
                  trem[esquerda] = auxiliar;
                  contador++;
              }
          }
     }
    printf("Optimal train swapping takes %d swaps.\n", contador);
}

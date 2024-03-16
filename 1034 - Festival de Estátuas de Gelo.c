#include <stdio.h>
#include <stdlib.h>

int main(){

  int casos, QuantidadeDeBlocos, ComprimentosDosBlocos[1000000], FOCOPARACONSEGUIR, TodosOsBlocos[25], i, j, k;

  scanf("%d", &casos);             

  for(i=0; i<casos; i++){
    scanf("%d", &QuantidadeDeBlocos);   
    scanf("%d", &FOCOPARACONSEGUIR);          
   
    for(j=0; j<QuantidadeDeBlocos; j++){ 
      scanf("%d", &TodosOsBlocos[j]);        
    }
    
    for(j=0; j<=FOCOPARACONSEGUIR; j++){ 
      ComprimentosDosBlocos[j] = j;
    }
   
    for(j = 1; j < QuantidadeDeBlocos; j++){

      for(k = 0; k <= FOCOPARACONSEGUIR; k++){

        if(k >= TodosOsBlocos[j]){

          if(ComprimentosDosBlocos[k] > ComprimentosDosBlocos[k-TodosOsBlocos[j]]+1){

            ComprimentosDosBlocos[k] = ComprimentosDosBlocos[k-TodosOsBlocos[j]]+1;
            
          }
        }
      }
    }
    printf("%d\n", ComprimentosDosBlocos[FOCOPARACONSEGUIR]);
  }

  return 0;
}

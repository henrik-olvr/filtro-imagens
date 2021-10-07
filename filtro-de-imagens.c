/* Este programa, dado o nome de um arquivo.ppm, gera um arquivo com o
   filtro negativo e um com o filtro sepia.
  
    Nome : Luiz Henrik Oliveira
    Disciplina : INF01202
    Data : 30/04/21   */

#include <stdio.h> 
#include <string.h> 
#define TAMARQ 50 

int main () { 

  // Arquivos de entrada e saída.
  
  FILE *arq_entrada = NULL ; 
  FILE *arq_negativo = NULL ; 
  FILE *arq_sepia = NULL ;  

  // Variáveis.
  
  char c ; 
  int v, coluna, linha, intensidade_max ; 
  int i = 0, j = 0 ;
  int r, g, b ; 
  int cr, cg, cb ; 
  int tr, tg, tb ; 
  char nome_arq[TAMARQ] ; 
 
    // Leitura do nome do arquivo. 
    
    printf("Informe o nome do arquivo: \n") ; 
    fgets(nome_arq, TAMARQ, stdin) ; 
    nome_arq[strlen(nome_arq)-1] = '\0' ; 

    // Abertura de arquivos. 
    
    arq_entrada = fopen(nome_arq, "r") ; 
    arq_negativo = fopen("negativo.ppm", "w") ; 
    arq_sepia = fopen("sepia.ppm", "w") ; 
    
    if(arq_entrada == NULL || arq_negativo == NULL || arq_sepia == NULL) { 

       printf("Erro na abertura dos arquivos de entrada e saída!\n") ; 
       
     }else{

     // Leitura do cabeçalho do arquivo. 
     
     fscanf(arq_entrada, "%c %d", &c, &v) ; 
     fscanf(arq_entrada, "%d %d", &coluna, &linha) ; 
     fscanf(arq_entrada, "%d", &intensidade_max) ; 
     
     // Impressão do cabeçalho no arq_negativo.
     
     fprintf(arq_negativo, "%c%d\n", c, v) ;
     fprintf(arq_negativo, "%d %d\n", coluna, linha) ;
     fprintf(arq_negativo, "%d\n", intensidade_max) ;
    
     // Impressão do cabeçalho no arq_sepia ;
     
     fprintf(arq_sepia, "%c%d\n", c, v) ;
     fprintf(arq_sepia, "%d %d\n", coluna, linha) ;
     fprintf(arq_sepia, "%d\n", intensidade_max) ;
     
     // Leitura e impressão dos pixels. 
     
     for(i = 0 ; i < linha ; i++) { 
        for(j = 0 ; j < coluna ; j++) { 

           fscanf(arq_entrada, "%d %d %d", &r, &g, &b) ;
           
           cr = 255 - r ;
           cg = 255 - g ;
           cb = 255 - b ;
          
           fprintf(arq_negativo, "%d %d %d ", cr, cg, cb) ;
          
           cr = 0 ;
           cg = 0 ;
           cb = 0 ;
          
           tr = (0.393 * r + 0.769 * g + 0.189 * b) ;
           tg = (0.349 * r + 0.686 * g + 0.168 * b) ;
           tb = (0.272 * r + 0.534 * g + 0.131 * b) ;
          
          if(tr > 255) {
             
             r = 255 ;
             fprintf(arq_sepia, "%d ", r) ;
             
          }else{
             
             r = tr ;
             fprintf(arq_sepia, "%d ", r) ;
            
          }
         
          if(tg > 255) {
            
            g = 255 ;
            fprintf(arq_sepia, "%d ", g) ;
            
          }else{
            
            g = tg ;
            fprintf(arq_sepia, "%d ", g) ;
            
          }
        
          if(tb > 255) {
             
             b = 255 ;
             fprintf(arq_sepia, "%d ", b) ;
            
          }else{
             
             b = tb ;
             fprintf(arq_sepia, "%d ", b) ;
            
          } 
         
           
        } fputs("\n", arq_negativo) ;
          fputs("\n", arq_sepia) ; 
     }
 

      printf("Arquivo negativo.ppm gerado com sucesso!\n") ; 
      printf("Arquivo sepia.ppm gerado com sucesso!\n") ; 
      
      fclose(arq_entrada) ; 
      arq_entrada = NULL ; 
      fclose(arq_negativo) ; 
      arq_negativo = NULL ; 
      fclose(arq_sepia) ; 
      arq_sepia = NULL ; 
    
     }
     
  return 0 ;
  
}
#include <stdio.h>

int main (){

  int N, k, l;
  FILE *in = fopen("input.txt","r");
  FILE *out = fopen("output.txt","w");

// lettura input
  fscanf(in, "%d\n", &N);
  int tria[N][N];
  for(k=0; k<N; k++)
    for(l=0; l<=k; l++){
      fscanf(in, "%d", &tria[k][l]);
    }
  
 
// nella matrice segno la somma massima su un percorso che arrivi a i,j partendo dalla radice
  int somma[N][N];
  int i, j, h, max;

  somma[0][0] = tria[0][0];
  for(i=1; i<N; i++){  
    for(j=0; j<=i; j++){
      if(j==0) somma[i][j]=somma[i-1][j]+tria[i][j];
      else {
        if(j==i) somma[i][j]=somma[i-1][j-1]+tria[i][j];
        else {
          if(somma[i-1][j-1]>somma[i-1][j])
            somma[i][j]=somma[i-1][j-1]+tria[i][j];
          else somma[i][j]=somma[i-1][j]+tria[i][j];
        
        }
      }
    }
  }
  
  max=somma[N-1][0];
  for(h=1; h<N; h++){
    if(max<somma[N-1][h]) max=somma[N-1][h];
  }   
  
  fprintf(out, "%d ", max);

  fclose(in);
  fclose(out);

  return 0;
}

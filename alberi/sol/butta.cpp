#include <stdio.h>

int i,j,k,x,radici[1000010];

void visita(int N, int *PRE, int *POST, int *SIMM )
{
     j=0;k=0;x=0;
     for (i=0;i<N;i++) {
       if (PRE[i]!=POST[j]) {radici[k]=PRE[i];k++;}
       else {
            SIMM[x]=PRE[i];x++;
            SIMM[x]=radici[--k];x++;
            j++;
       }
    }
    SIMM[x]=PRE[N-1];
    //~ for (i=0;i<N;i++) printf("%d ",SIMM[i]); 
    return;
}

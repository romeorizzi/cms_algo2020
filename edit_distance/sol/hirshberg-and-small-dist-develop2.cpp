// Questo codice che cerca di avvantaggiarsi del fatto che la distanza tra le due stringhe e` piccola non e` completo. Ad esempio, da` ancora errori su develop_input1.txt
#include <cstdio>
#include <cassert>
#include <cstring>

const int LEN_MAX = 1000;

int N, M; // lunghezza delle stringhe S e T
char S[LEN_MAX + 2], T[LEN_MAX + 2]; // indicizzate con 1..N e 1..M

int mymin(int a, int b) {return (a<b) ? a : b; }
int mymax(int a, int b) {return (a>b) ? a : b; }

int distSimpleDPcomputation() {
  /* this DP algorithm is only meant to compute the distance between string S and T, without producing any optimal alignment.
     We preferred to give it for a few reasons:
       1. to illustrate the underlying recursive decomposition of the problem in subproblems before introducing all complications of the full Hirshberg's algorithm;
       2. though Hirshberg's algorithm also computes the distance, and yes, it could actually discover its value already with the first call to its subroutine magic_break,
          still meeting the requirement of the exercise (i.e., first output the dist value and then give an optimal alignment afterwars) would have spoiled the code.
       3. we also considered that having a double solution could be exploited for a cross-validation.   
       4. in this procedure you can appreciate another trick which allows to take profit of the possibility that the distance is much smaller than the two strings.
          The fact is that if we were told in advance that the distance is small, say at most UB, then we could avoid spending O(NM) time and O(N UB) would suffice since
          the DP matrix would be essentially square (M-UB <= N <= M+UB) and it would be enough to compute the DP values on a width 2UB strip around the main "diagonal".
          The IDEA of this further trick is then to consider exponentially growing values for the upper-bound UB = 0,1,2,4,8, ... and stop as soon as a DP computation
          on the restricted DP matrix is successful.
  */    
  int UB = 0; //upper bound on the true distance value (see point 4. in the description above)
  if(M>N) UB = M-N; else UB = N-M;

      fprintf(stderr, "UB = %d \n", UB);

  int D[LEN_MAX + 2][2*UB]; // D[i][j  -i+UB] = cost of aligning prefix S[1..i] against prefix T[1..j]
                            // this can be <= UB only for i-UB <= j <= i+UB
  for(int p = 0; p <= UB; p++) {
      D[0][p] = 0;
      D[0][p   -0+UB] = p;
  }    
  for(int i = 1; i <= N; i++) {
    for(int j = mymin(0, i-UB); j <= mymax(M, i+UB); j++) {
      if(j==0) D[i][j  -i+UB] = i;
      else if(j==i-UB) { // la domanda e` se T[1..j] sia una sottosequenza di S[1..i]
	D[i][j  -i+UB] = UB+1; // ipotizziamo che no
	if(D[i-1][j  -(i-1)+UB] == UB)
	  D[i][j  -i+UB] = UB; // in questo caso si
	if(S[i] == T[j] && D[i-1][j-1  -(i-1)+UB] == UB)
	  D[i][j  -i+UB] = UB; // altro caso di si	  
      }	
      else {
	if(S[i] == T[j])  D[i][j  -i+UB] = D[i-1][j-1  -(i-1)+UB];
        else {
          D[i][j  -i+UB] = D[i-1][j-1  -(i-1)+UB] + 1; // ipotesi modifica carattere
	  if( D[i][j-1  -i+UB] + 1 < D[i][j  -i+UB]) // ipotesi del car in T (ins in S)
	    D[i][j  -i+UB] = D[i][j-1  -i+UB] + 1;
	  if( j  -(i-1)+UB <= 2*UB && D[i-1][j  -(i-1)+UB] + 1 < D[i][j  -i+UB]) // ipotesi del car in S
	    D[i][j  -i+UB] = D[i-1][j  -(i-1)+UB] + 1;
	}
      }
      fprintf(stderr, "%d ", D[i][j  -i+UB]);
    }
    fprintf(stderr, "\n");
  }
    /* fprintf(stderr, "   -");
    for(int j = 1; j <= M; j++)
      fprintf(stderr, " %c", T[j]);
    fprintf(stderr, "\n");
    for(int i = 0; i <= N; i++) {
      if(i == 0)
        fprintf(stderr, " -");
      else
        fprintf(stderr, " %c", S[i]);
      for(int j = 0; j <= M; j++)
        fprintf(stderr, " %d", D[i][j]);
      fprintf(stderr, "\n");
      } */ 
    return D[N][M  -N+UB];
}



int distanza = 0;
void allinea_singolo(int index_S, int start_T, int end_T) {
  //allinea un singolo carattere di S contro un intervallo di T  
    assert(1 <= index_S && index_S <= N);
    assert(1 <= start_T && start_T <= end_T+1 && end_T <= M);

    if(start_T == end_T+1) { // se l'intevallo di T e` vuoto
        printf("%c - C %d\n", S[index_S], index_S);
	distanza++;
        return;
    }

    if(S[index_S] == T[start_T]) {
        printf("%c %c A %d-%d\n",
                S[index_S], T[start_T], index_S, start_T);
        for(int i = start_T+1; i <= end_T; i++) {
            printf("- %c I %d\n", T[i], i);
	    distanza++;
        }
        return;
    }

    if(start_T == end_T) { // intervallo di T composto da un singolo carattere
        printf("%c %c R %d-%d\n",
                S[index_S], T[start_T], index_S, start_T);
	distanza++;
        return;
    }

    printf("- %c I %d\n", T[start_T], start_T);
    distanza++;
    allinea_singolo(index_S, start_T+1, end_T);
}

int L[LEN_MAX+2][LEN_MAX+2];
int R[LEN_MAX+2][LEN_MAX+2];

int magic_break(int start_S, int mid_S, int end_S, int start_T, int end_T) {
    // restituisce indice mid_T
    // tale che il sottoproblema S[start_S..end_S] versus T[start_T..end_T]
    // si spezza nei sottoproblemi
    // S[start_S..mid_S] versus T[start_T..mid_T]
    //  e
    // S[mid_S+1..end_S] versus T[mid_T+1..mid_T]
    
    /*
        L[i][j] := edit_distance(
            S[start_S..i],
            T[start_T..j]
        )

        R[i][j] := edit_distance(
            S[i..end_S],
            T[start_T..j]
        )
    */

    for(int j = start_T-1; j <= end_T; j++)
      L[start_S-1][j] = j-start_T+1;
    for(int i = start_S; i <= mid_S; i++)
      L[i][start_T-1] = i-start_S+1;
    for(int i = start_S; i <= mid_S; i++)
      for(int j = start_T; j <= end_T; j++)
	if(S[i] == T[j])  L[i][j] = L[i-1][j-1];
        else {
          L[i][j] = L[i-1][j-1] + 1; // ipotesi modifica carattere
	  if( L[i-1][j] + 1 < L[i][j]) // ipotesi del car in S
	    L[i][j] = L[i-1][j] + 1;
	  if( L[i][j-1] + 1 < L[i][j]) // ipotesi del car in T (ins in S)
	    L[i][j] = L[i][j-1] + 1;
	}
    for(int j = end_T+1; j >= start_T; j--)
      R[end_S+1][j] = end_T+1 -j;
    for(int i = end_S; i > mid_S; i--)
      R[i][end_T+1] = end_S-i+1;
    for(int i = end_S; i > mid_S; i--)
      for(int j = end_T; j >= start_T; j--)
	if(S[i] == T[j])  R[i][j] = R[i+1][j+1];
        else {
          R[i][j] = R[i+1][j+1] + 1; // ipotesi modifica carattere
	  if( R[i+1][j] + 1 < R[i][j]) // ipotesi del car in S
	    R[i][j] = R[i+1][j] + 1;
	  if( R[i][j+1] + 1 < R[i][j]) // ipotesi del car in T (ins in S)
	    R[i][j] = R[i][j+1] + 1;
	}

    int best_mid_T = start_T -1;
    int best_price = L[mid_S][best_mid_T] + R[mid_S+1][best_mid_T+1];
    for(int mid_T = start_T; mid_T <= end_T; mid_T++)
      if( L[mid_S][mid_T] + R[mid_S+1][mid_T+1] < best_price) {
	best_mid_T = mid_T;
        best_price = L[mid_S][mid_T] + R[mid_S+1][mid_T+1];
      }	

    /*
    fprintf(stderr, "start_S = %d, mid_S = %d, end_S = %d\n", start_S, mid_S, end_S);
    fprintf(stderr, "start_T = %d, end_T = %d, MID_T = %d, BEST_PRICE = %d\n", start_T, end_T, best_mid_T, best_price);
    fprintf(stderr, "   -");
    for(int j = start_T; j <= end_T; j++)
      fprintf(stderr, " %c", T[j]);
    fprintf(stderr, " -\n");      
    for(int i = start_S-1; i <= end_S+1; i++) {
      if(i == start_S-1 || i == end_S+1)
        fprintf(stderr, " -");
      else
        fprintf(stderr, " %c", S[i]);
      for(int j = start_T -1; j <= end_T +1; j++)
	if(i <= mid_S)
          fprintf(stderr, " %d", L[i][j]);
        else
          fprintf(stderr, " %d", R[i][j]);
      fprintf(stderr, "\n");      
    } */
    
    return best_mid_T;
}

void genera_alignment(int start_S, int end_S, int start_T, int end_T) {
    // riceve un intervallo non-vuoto di S ad un qualsiasi intervallo di T
    // stampa lista mosse per trasformare
    // S[start_S..end_S] in T[start_T..end_T]
    assert(1 <= start_S && start_S <= end_S   && end_S <= N);
    assert(1 <= start_T && start_T <= end_T+1 && end_T <= M);
    
    if (start_S == end_S) {
        allinea_singolo(start_S, start_T, end_T);
        return;
    }
    
    int mid_S = (start_S + end_S) / 2;
    int mid_T = magic_break(
            start_S, mid_S, end_S, start_T, end_T);
    
    genera_alignment(start_S, mid_S, start_T, mid_T);
    genera_alignment(mid_S+1, end_S, mid_T+1, end_T);
}


int main() {
    scanf("%d %s", &N, &S[1]);
    assert(strlen(&S[1]) == N);
    fprintf(stderr, "Ho letto S: '%s'\n", &S[1]);
    
    scanf("%d %s", &M, &T[1]);
    assert(strlen(&T[1]) == M);
    fprintf(stderr, "Ho letto T: '%s'\n", &T[1]);

    
    printf("%d\n", distSimpleDPcomputation() );
    genera_alignment(1, N, 1, M);
    assert( distanza == distSimpleDPcomputation() );
}


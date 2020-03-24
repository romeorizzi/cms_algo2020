#include "ourLibToPlay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define PATT_SIZE 100
#define TEXT_SIZE 100000

int preProcessing(char *pattern, int patt_len, int h[], int next[], int shift[]) {
   int i, k, nd, q, r, s;
   int hmax[PATT_SIZE], kmin[PATT_SIZE], sNoHoles[PATT_SIZE], rmin[PATT_SIZE];

   /* Calcolo hmax: tabella usata per calcolare kmin e rmin */
   i = k = 1;
   do {
      while (pattern[i] == pattern[i - k]) {
         i++;
	  }
      hmax[k] = i;
      q = k + 1;
      while (hmax[q - k] + k < i) {
         hmax[q] = hmax[q - k] + k;
         q++;
      }
      k = q;
      if (k == i + 1) {
         i = k;
	  }
   } while (k <= patt_len);

   /* Calcolo kmin: numero di salti nell'algoritmo di KMP */
   memset(kmin, 0, patt_len*sizeof(int));
   for (i = patt_len; i >= 1; --i) {
      if (hmax[i] < patt_len) {
         kmin[hmax[i]] = i;
	  }
   }

   /* Calcolo h: buchi e non-buchi */
   s = -1;
   r = patt_len;
   for (i = 0; i < patt_len; ++i) {
      if (kmin[i] == 0) {
         h[--r] = i;
      } else {
         h[++s] = i;
	  }
   }
   nd = s; // numero totale di non buchi

   /* Calcolo sNoHoles: sNoHoles[i] numero di non-buchi più piccoli di i*/
   s = 0;
   for (i = 0; i < patt_len; ++i) {
      sNoHoles[i] = s;
      if (kmin[i] > 0) {
         ++s;
      }
   }

   /* Calcolo rmin: rmin[i] è il più piccolo periodo del pattern maggiore di i */
   for (i = patt_len - 1; i >= 0; --i) {
      if (hmax[i + 1] == patt_len) {
         r = i + 1;
      }
      if (kmin[i] == 0) {
         rmin[i] = r;
      } else {
         rmin[i] = 0;
      }
   }
 
   /* Calcolo lo shift: quanto spostare la finestra di confronto */
   for (i = 0; i <= nd; ++i) {
      shift[i] = kmin[h[i]];
   }
   for (i = nd + 1; i < patt_len; ++i) {
      shift[i] = rmin[h[i]];
   }
   shift[patt_len] = rmin[0];


   /* Calcolo next*/
   for (i = 0; i <= nd; ++i) {
      next[i] = sNoHoles[h[i] - kmin[h[i]]];
   }
   for (i = nd + 1; i < patt_len; ++i) {
      next[i] = sNoHoles[patt_len - rmin[h[i]]];
   }
   next[patt_len] = sNoHoles[patt_len - rmin[h[patt_len - 1]]];

   return(nd);
}

void solve(char *pattern, int patt_len, int text_len) {
   int i, j, k, e, last, nd, nmatches;
   int h[PATT_SIZE], next[PATT_SIZE], shift[PATT_SIZE];
   char heavy;
   int output[TEXT_SIZE];

   for (e = 0; pattern[e] == pattern[e + 1]; e++);

   if (e == patt_len - 1) {
      /* Searching for a power of a single character */
      for (j = e = 0; j < text_len; ++j) {
          if(charCompare(pattern[0], j)) {
             ++e;
             if (e >= patt_len)
                output[nmatches] = (j - patt_len + 1);
				nmatches++;
          }
          else {
             e = 0;
          }
      }
   } else {
      /* Preprocessing */
      nd = preProcessing(pattern, patt_len, h, next, shift);

      /* Searching */
      i = j = heavy = 0;
      last = -1;
      while (j <= text_len - patt_len) {
         if (heavy && i == 0) {
            k = last - j + 1;
            while (charCompare(pattern[0], j+k)) {
               k++;
            }
            if (k <= e || !charCompare(pattern[e + 1], j + k)) {
               i = 0;
               j += (k + 1);
               last = j - 1;
            }
            else {
               i = 1;
               last = j + k;
               j = last - (e + 1);
            }
            heavy = 0;
         }
         else {
            while (i < patt_len && last < j + h[i] && charCompare(pattern[h[i]], j+h[i])) {
               ++i;
            }
            if (i >= patt_len || last >= j + h[i]) {
               output[nmatches] = j;
               i = patt_len;
				nmatches++;
            }
            if (i > nd) {
               last = j + patt_len - 1;
            }
            j += shift[i];
            i = next[i];
         }
         heavy = (j > last ? 0 : 1);
      }
   }
	int* risposta = (int*)malloc(sizeof(int)*nmatches);
	for (i = 0; i < nmatches; i++) {
		risposta[i] = output[i];
	}
	pensoCheMatchingSia(risposta, nmatches);
}


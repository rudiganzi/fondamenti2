#include <stdio.h>
#include <stdlib.h>

#define N 5
#define DOUBLE_MAX 1000000

typedef struct {
  double costo;     
  int stazione[N];  
} piano;



void pianifica(double M, int n, double *d, double *p, int i, double dist, piano c, piano *b, double PercorsoDaUltimoRifornimento)
{

	  if(i==n) {
	    printf("\n\nTrovata soluzione (%.2f), (percorsi %.2f km)\n",c.costo, dist);
	      for(int i=0;i<n;i++)
			 printf("%d ",c.stazione[i]);
		//getchar();
	    if(c.costo<b->costo) {
	      b->costo=c.costo;  
	     
	      for(int i=0;i<n;i++){
		     b->stazione[i] = c.stazione[i];
			
	      }
		}
	    return;
	  }

  	dist+=d[i];
	PercorsoDaUltimoRifornimento+=d[i];


	
	if (PercorsoDaUltimoRifornimento > 600)
			return;

		c.stazione[i]=0;
       
		pianifica(M,n,d,p,i+1,dist,c,b,PercorsoDaUltimoRifornimento);

		c.costo += PercorsoDaUltimoRifornimento * 0.05 * p[i]; 
        c.stazione[i]=1;
		PercorsoDaUltimoRifornimento=0;
		
		pianifica(M,n,d,p,i+1,dist,c,b,PercorsoDaUltimoRifornimento);
}



void main()
{
	double M = 0;
	piano corrente, best;
	int n = N;
	double distanza[N], prezzo[N];

	for (int i=0; i<N;i++){
		corrente.stazione[i] = 0;
		best.stazione[i] = 0;
		prezzo[i] = i + 35 - i*i ;
		distanza[i] = 260 + i * 24;
		M+=distanza[i];
		printf("\nstazione %d,  km %.2f, prezzo %.2f",i, distanza[i], prezzo[i]);
	}

  corrente.costo=0;
  best.costo=DOUBLE_MAX;

  printf("\nInizio la pianificazione (percorso %.2f)", M);
  getchar();

  pianifica(M,n,distanza,prezzo,0,0,corrente,&best,0);

  if(best.costo==DOUBLE_MAX)
    printf("\nImpossibile raggiungere la meta");
  else {
    printf("\n\nConviene fare il pieno nelle stazioni: ");
    for(int i=0;i<n;i++)
      if(best.stazione[i]==1)
				printf("\n%d",i);
	printf("\nCosto totale: %.2f ", best.costo);
  }
}



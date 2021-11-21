#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
/********** I N I Z I O M A I N **********/


int main ()
{
/*
int cielo [10][10]={0}; */

srand((unsigned int)time(0));//rende casuale la funzione rand perchè prende in considerazione l'orologio di sistema

for(k=1;k<=5;k++){
int cielo [10][10]= { {0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0} };

int coste[4][3]={{1,0,1},
{0,1,0},
{1,0,1},
{1,0,1}};

int x,y;
int i,j;
int indice=0;// indiceRow,indiceCol
for (i=0;i<=25;i++)//genero x e y come numeri casuali tra 0 e 10 e,se in cielo[x][y]. Se c'è 1 allora decremento i

{ //e ricalcolo di nuovo x,y...altrimenti assegno 1 a cielo[x][y]
//il ciclo for itera 25 volte in modo tale da inserire all'interno della matrice cielo, un
//numero di '1' pari proprio al numero di iterazioni (in questo caso inserisce 25 stelle)

x=rand()%11;
y=rand()%11;

if (cielo[x][y]==1)
i=i-1;
else
cielo[x][y]=1;
}

for (i=0;i<10;i++) //stampa della matrice cielo
{
for (j=0;j<10;j++)
printf("%d ",cielo[i][j]);
printf("\n");
}

printf("\n\n");
for (i=0;i<4;i++)//stampa della matrice coste (cioè della costellazione)
{
for (j=0;j<3;j++)
printf("%d ",coste[i][j]);
printf("\n");
}

printf("\n");

matching_migliore (cielo, coste, 10, 3, 4);

}

}

/********** F I N E M A I N **********/



void stampaMatrice (int mx[][10] , int col , int row)
{
int i,j;
printf("MATRICE RISULTATO :\n");
printf("-------------------\n");
for (i = row ; i < 4+row ; i++)
{
for(j = col ; j < 3+col ; j++)
{
printf("%d " , mx[i][j]);
}
printf("\n");
}

}


int punteggio_migliore (int a[][10] , int b[][3] , int c , int col_cost , int row_cost , int iColx , int iRowx)
{
int iC, iR , n_caratteri_uguali;
n_caratteri_uguali=0; //questa variabile conterrà il numero di stelle in comune tra cielo e costellazione
//Ovviamente viene inizializzata a 0 perchè all'inizio non ci sono stelle in comune
for (iR=iRowx ; iR < 4 + iRowx ; iR++)
{
for (iC=iColx ; iC < 3 + iColx ; iC++)
{
// printf ("==== iR : %d iC : %d a : %d b : %d \n ",iR,iC,a[iR][iC],b[iR-iRowx][iC-iColx]);
if (a[iR][iC] == b[iR-iRowx][iC-iColx])
{
n_caratteri_uguali++;
}
/*Con questo IF si verifica se la stella della costellazione appartiene o meno al cielo:
- se appartiene, viene incrementato il valore della variabile 'n_caratteri_uguali'
- se non appartiene, il ciclo for continua a iterare senza aumentare il valore della variabile */
}
}
// printf("Punt : %d iCol : %d iRow : %d \n" , n_caratteri_uguali , iColx , iRowx);
return n_caratteri_uguali;
}

/* In questo function viene 'sfruttato' il lavoro della function 'punteggio_migliore' per riuscire ad ottenere
il match migliore. In pratica, si verifica, ad ogni passo, se il punteggio ottenuto è maggiore del punteggio
massimo corrente:
- se lo è, allora viene aggiornato il contenuto della varibile punteggio_max, resultRow e resultCol
- se non lo è, allora il contenuto della tre variabili rimane immutato */

void matching_migliore (int a[][10] , int b[][3] , int c , int col_cost , int row_cost)
{
int iCol , iRow , resultCol , resultRow , punteggio_max, punteggio;

punteggio_max=0;

for (iRow=0 ; iRow <= (c - row_cost) ; iRow++)
{
for (iCol=0 ; iCol <= (c - col_cost) ; iCol++)
{

punteggio=punteggio_migliore (a , b , c , col_cost , row_cost , iCol , iRow );
if (punteggio > punteggio_max)
{
punteggio_max=punteggio;
resultRow=iRow;
resultCol=iCol;
// printf("--------> iRow : %d iCol : %d ", iRow, iCol);
}
}
}

printf("TEST NUMERO %d\n\n",k);
stampaMatrice(a , resultCol , resultRow);
printf("\nCol : %d Row : %d Numero coincidenze : %d\n\n" , resultCol+1 , resultRow+1 , punteggio_max);

}


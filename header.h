


// PROTOTIPO FUNCTION


/* Questa function ricerca all'interno dell'osservazione la costellazione che meglio la rappresenta.
In pratica, mediante due cicli for innestati si riesce a raggiungere il nostro scopo: quello di
trovare la posizione iniziale della costellazione inserita.
Questa function presenta al suo interno anche un richiamo alla function 'punteggio_migliore' */


void matching_migliore (int a[][10] , int b[][3] , int c , int col_cost , int row_cost);




/* Questa � una function che serve alla function 'matching migliore' per trovare il numero di stelle
in comune tra l'osservazione (cio� il cielo) e la costellazione (cio� coste).
Ovviamente il numero minimo che ritorner� questa function � pari a:
- 0, quando l'osservazione e la costellazione non hanno stelle in comune
- cxr, quando tutte le stelle della costellazione appartengono all'osservazione */


int punteggio_migliore (int a[][10] , int b[][3] , int c , int col_cost , int row_cost , int iColx , int iRowx);


/* Questa function viene utilizzata per stampare a video l'osservazione e la costellazione perch�
in entrambi i casi si tratta di matrici, in particolare, l'osservazione avr� dimensioni pari a nxm
mentre la costellazione avr� dimensioni pari a cxr */


void stampaMatrice (int mx[][10] , int col , int row);



int k=0;



/* L'idea � quella di scomporre il problema in queste fasi:
1) Si genera l'osservazione (variabile cielo) mediante l'uso della funzione rand
2) La costellazione con la quale verr� effettuato il matching � gia nota (quindi non � generata casualmente)
3) Una volta che abbiamo a disposizione entrambe le matrici, le stampiamo a video
4) Richiamando la function 'matching migliore' ci ricaviamo la posizione iniziale da dove inizia la
costellazione con il match migliore contando, con dei cicli for, quante stelle della costellazione
appartengono all'osservazione*/




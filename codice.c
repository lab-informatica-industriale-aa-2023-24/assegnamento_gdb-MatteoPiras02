/* 
 * codice per insertion sort
 * descrizione: https://it.wikipedia.org/wiki/Insertion_sort
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 10

void estrai_dati(int ac, char **av, int *vett, int *lung)
{
	*lung = ac - 1;
	for (int i = 0; i < *lung; ++i)
		vett[i] = atoi(av[i+1]);
}

void fai_spazio(int posizione, int *vett, int lung)
{
	printf("Fai Spazio\n");
	for (int j = posizione; j <lung ; ++j)  {
		vett[j] = vett[j-1];
		//printf("%d ", vett[j]);
	}
}

void inserisci(int nuovo_dato, int num_dati_ord, int *vett)
{ 
	if (num_dati_ord == 0)  
	{ // il vettore è vuoto, facile
		vett[0] = nuovo_dato;
		//printf("%d ", nuovo_dato);
		return;
	}
	for (int i = 0; i < num_dati_ord; ++i)  
	{
		printf("%d, %d\n", nuovo_dato, vett[i]);
		if (nuovo_dato<vett[i])  
		{
			
			// sposta da vett[i] in poi di un posto sulla destra
			// prima di inserire il nuovo_dato
			fai_spazio(i, vett, num_dati_ord);
			vett[i]=nuovo_dato;
			return;
		}
		vett[i+1] = nuovo_dato;
		return;
	}
}

void ordina_dati(const int *dati_non_ordinati, int *dati_ordinati, int argc)
{
	for (int i = 0; i < argc-1; ++i){
		inserisci(dati_non_ordinati[i], i, dati_ordinati);
		printf("%d\n", i);
	}
}

void stampa_vettore(int *vett, int lung)
{
	for (int i = 0; i < lung; ++i)
		printf("%d ",vett[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc > MAX_INPUT) 
	{
		printf("Numero massimo di input %d\n", MAX_INPUT);
		return -1;
	}
	
	int dati_input[MAX_INPUT] = {0};
	int dati_ordinati[MAX_INPUT] = {0};
	int num_dati = 0;
	estrai_dati(argc, argv, dati_input, &num_dati);
	ordina_dati(dati_input, dati_ordinati, argc);
	stampa_vettore(dati_ordinati, num_dati);
	return 0;
}

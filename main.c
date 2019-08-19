#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* Estruturas do TAD LISTA_ENC_EST */ 
  struct nodo
{
  
float info;
   
int prox;
 
};

 
typedef struct nodo Nodo;

 
struct lista
{
  
int ind_pri_ele;
   
int ind_nodo_livre;
   
Nodo elementos[MAX];	/* #define max 100, por exemplo */
 
};

 
typedef struct lista LISTA_ENC_EST;

 
void inicializa (LISTA_ENC_EST * l)
{
  
int i;
  
l->ind_pri_ele = -1;
  
l->ind_nodo_livre = 0;
  
for (i = 0; i < MAX - 1; i++)
    
l->elementos[i].prox = i + 1;
  
l->elementos[i].prox = -1;

}


 
int vazia (LISTA_ENC_EST * l)
{
  
return (l->ind_pri_ele == -1);

}


 
int tam (LISTA_ENC_EST * l)
{
  
int cont = 0, ind = l->ind_pri_ele;
  
 
while (ind != -1)
    {
      
cont++;
      
ind = l->elementos[ind].prox;
    
}
  
 
return cont;

}


 
void ins (LISTA_ENC_EST * l, int pos, float val)
{
  
if (pos < 1 || pos > tam (l) + 1)
    {
      
printf ("\nPosicao invalida!");
      
exit (1);
    
}
  
  else
    {
      
if (l->ind_nodo_livre != -1)
	{
	  
int aux;
	  
if (pos == 1)
	    {
	      
l->elementos[l->ind_nodo_livre].info = val;
	      
aux = l->elementos[l->ind_nodo_livre].prox;
	      
l->elementos[l->ind_nodo_livre].prox = l->ind_pri_ele;
	      
 
l->ind_pri_ele = l->ind_nodo_livre;
	      
 
l->ind_nodo_livre = aux;
	    
}
	  
	  else
	    {
	      
int ind;
	      
for (ind = l->ind_pri_ele; --pos - 1;
		    ind = l->elementos[ind].prox);
	      
 
l->elementos[l->ind_nodo_livre].info = val;
	      
aux = l->elementos[l->ind_nodo_livre].prox;
	      
l->elementos[l->ind_nodo_livre].prox = l->elementos[ind].prox;
	      
 
l->elementos[ind].prox = l->ind_nodo_livre;
	      
l->ind_nodo_livre = aux;
	    
}
	
}
      else
	{
	  
printf
	    ("\nImpossivel inserir novos elementos.\nMemoria insuficiente.");
	  
exit (2);
	}
    }
}


 
float recup (LISTA_ENC_EST * l, int pos) 
{
  
if (pos < 1 || pos > tam (l))
    
    {
      
printf ("\nPosicao invalida!");
      
exit (1);
    
}
  
  else
    
    {
      
int ind = l->ind_pri_ele;
      
while (--pos)
	
ind = l->elementos[ind].prox;
      
return l->elementos[ind].info;
    
}

}


 
int main ()
{

 
}


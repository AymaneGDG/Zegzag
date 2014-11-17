#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (a>b? a:b)

typedef struct noeud *ptr_arbre ; 
 struct noeud {
    int cle ; 
    int d ;	  
	ptr_arbre filsD ; 
    ptr_arbre filsG ;
	 } ; 
	 
void inser_rec(ptr_arbre &A , int x){
	if(A!=NULL)
	 { if(x>A->cle) inser_rec(A->filsD ,x);
	   else if(x<A->cle)  inser_rec(A->filsG ,x);
	    else if(x==A->cle)  inser_rec(A->filsG ,x);
	 }
	 else 
	 { A=(ptr_arbre)malloc(sizeof(struct noeud));
		 A->cle = x ; A->filsD = NULL ; A->filsG = NULL ;
	 }
	
	}


void inordre(ptr_arbre A)
{   if(A!=NULL)
    {
	inordre(A->filsG) ;
	printf("[%d]",A->cle);
	inordre(A->filsD);
    }
}

void prenordre(ptr_arbre A)
{   if(A!=0)
   {
	printf("[%d]",A->cle); 
    prenordre(A->filsG) ;
	prenordre(A->filsD);
   }
}

int hauteur(ptr_arbre A)
{ if(A==0) return 0 ; 
  return (1+max(hauteur(A->filsG) ,hauteur(A->filsD))) ;	
	
}

/*****************Exercice 3**************************/

int desequilibre(ptr_arbre A)
{ if(A==0) return 0 ;
  if((A->filsD==0) && (A->filsG)==0) return 0 ;
  if((A->filsD==0) || ((A->filsG)==0))  return hauteur(A) ; 
  return (hauteur(A->filsG)-hauteur(A->filsD)) ;

}
int somme_noeud(ptr_arbre A)
{ if(A!=0) 
	return (A->cle + somme_noeud(A->filsG) +somme_noeud(A->filsD)) ;
  else 
    return 0 ;	
}

int main(){
	
	
	
ptr_arbre arbre=NULL;
inser_rec(arbre,12);
inser_rec(arbre,8);
inser_rec(arbre,20);
inser_rec(arbre,4);
inser_rec(arbre,9);
inser_rec(arbre,14);
inser_rec(arbre,24);


printf("somme noeud=%d\n",somme_noeud(arbre));
printf("\nsomme hauteur=%d\n",hauteur(arbre));
printf("\nAfficheage de l'arbre en preordre\n");
prenordre(arbre) ; 
printf("\n\nle desequilibre est %d\n",desequilibre(arbre));



	
	return 0 ;}

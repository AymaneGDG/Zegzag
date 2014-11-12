#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct noeud *ptr ; 
typedef char information;
struct noeud {
	 int cle ;
	 information info ; 
	 ptr filsG ; 
	 ptr filsD ; 
	
	} ; 
	
void inser_rec(int x,ptr &A)
{ if(A!=0) 
    if(A->cle > x) inser_rec(x,A->filsG) ; 
	 else if(A->cle <x) inser_rec(x,A->filsD) ;
	  else printf("\ncle existant\n");
  else
   {A=(ptr)malloc(sizeof(struct noeud));
    A->cle = x ; A->filsD = NULL ; A->filsG= NULL ;
   
   }
}

ptr copie_arbre(ptr A)
{ ptr B ; 
 if(A==NULL) return NULL ; 
 else
 { 
  B=(ptr)malloc(sizeof(struct noeud));
  B->cle = A->cle ; 
  B->filsD = copie_arbre(A->filsD) ;   
  B->filsG = copie_arbre(A->filsG) ; 
  return B ;
 }

}

int max_arbre(ptr A)
{   
if(A!=0)  
   if(A->filsD == 0)  return A->cle ; 
   else  
    return max_arbre(A->filsD) ;
	  
else return -99 ;

}
 
int min_arbre(ptr A)
{ if(A!=0)  
   if(A->filsG == 0)  return A->cle ; 
   else  
    return min_arbre(A->filsG) ;
	  
else return -99 ;

}

int egale_arbre(ptr A, ptr B)
{ if(A==0 && B==0) return 1 ; 
   else if ((A!=0) && (B!=0))
     if(A->cle == B->cle && egale_arbre(A->filsG , B->filsG) && egale_arbre(A->filsD , B->filsD) )  
      return 1 ; 
     else return 0; 
   
    else return 0 ;	 
 	
}

int profondeur(ptr A, int x)
{   
	if(A==NULL) return (-99) ;
  if(A->cle == x) return 1 ; 
   else if(A->cle>x) return (profondeur(A->filsD,x)+1) ; 
    else return (profondeur(A->filsG,x) +1); 

}

ptr rech_ite(ptr A , int x)
{ while(A!=NULL)
   if(A->cle==x)  return A ; 
    else if(x>A->cle)  A=A->filsD ; 
     else A=A->filsG ;

return NULL ;
}


void inter_arbre(ptr A, ptr B, ptr &C)
{  if(A!=NULL) 
	 { if(rech_ite(B,A->cle)) inser_rec(A->cle, C);
      inter_arbre(A->filsD, B, C) ;
      inter_arbre(A->filsG, B, C) ; 
	} 
}

void inordre(ptr A)
{ if(A!=NULL)
  {inordre(A->filsG) ;
  printf("[%d] ",A->cle);
  inordre(A->filsG) ;   
  }
}

int main() {
 ptr A=0;
//~ ptr AC;
inser_rec(2,A);
inser_rec(3,A);
inser_rec(5,A);
inser_rec(7,A);
inser_rec(11,A);
inser_rec(12,A);
inser_rec(14,A);
inser_rec(16,A);
inser_rec(17,A);
inser_rec(24,A);
inser_rec(33,A);
inordre(A);	
	
	
	return 0 ; }

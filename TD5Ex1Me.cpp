#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct noeud *ptr_arbre ; 
 struct noeud{
	  char nom[50] ; 
	  ptr_arbre filsD ; 
	  ptr_arbre filsG ; 
	 
	 } ;
void ins_rec(ptr_arbre &A , char ch[80])
{ if(A!=NULL)
    { if (strcmp(ch,A->nom) < 0) ins_rec(A->filsG, ch);
     else if (strcmp(ch,A->nom) > 0) ins_rec(A->filsD, ch);
	   else if (strcmp(ch,A->nom) == 0) ins_rec(A->filsG, ch);
	}
  else
    { A=(ptr_arbre)malloc(sizeof(struct noeud)); 
	  strcpy(A->nom,ch) ; 
	  A->filsD = NULL ; A->filsG = NULL ;
		
	}
	}




void creation_fichier(char name_file[12])
{ FILE *f ;
 char ch[80] ; 
  int nb , i=0; 
  if( (f=fopen(name_file,"wt")) == 0) { printf("Echec d'insertion File Not Found"); return ; }
  printf("Donner le nombre des chaines a inserer dans le fichier\n") ; 
  scanf("%d",&nb);
  printf("Veuillez saisir %d chaines \n",nb);
  while(i<nb){
	  scanf("%s",ch); 
	  if(strcmp(ch,"")!=0) 
	     { fprintf(f,"%s\n",ch);
	       i++ ;
	     }
	  }
  fclose(f) ;
}

void remplir_arbre(char name_file[12], ptr_arbre &A)
{ FILE *f ;
  char ch[80] ;
  A=NULL ; 
  if((f=fopen(name_file,"r"))==0) 
  {
    printf("Echec d'ouverture fichier") ; 
    return  ;
   } 
   
	while(!feof(f)) {
	 fscanf(f,"%s",ch) ;
	 ins_rec(A,ch); 	
     printf("\n");
		}
 fclose(f) ;
}

void inordre (ptr_arbre A)
{if (A!=NULL)
{inordre(A->filsG);
printf("%s\n",A->nom);
inordre(A->filsD);
}
}

int cherche(ptr_arbre A, char mot[20])
{ if(A==NULL) return 0 ; 
  else if(strcmp(A->nom,mot) == 0) return 1 ; 
   else 
      if(strcmp(A->nom,mot) > 0)   
       return cherche(A->filsG, mot) ; 
	  else 
	   return cherche(A->filsD, mot) ;
}

void sauvegarde(ptr_arbre A, FILE * f)
{ 
 if (A!=NULL)
 {sauvegarde(A->filsG,f);
 fprintf(f,"%s\n",A->nom);
 sauvegarde(A->filsD,f);
 }	
}

int feuilles(ptr_arbre A, FILE *f)
{  if(A==0) {fprintf(f,"\n") ; return 0 ; }
   else if((A->filsG == 0) && (A->filsD == 0))	{ fprintf(f,"%s ",A->nom) ;return 1 ;} 
      return (feuilles(A->filsG,f)+feuilles(A->filsD,f)) ;
	
}

void inverse(ptr_arbre A)
{ ptr_arbre temp ; 
   if(A!=NULL)
	{  temp = A->filsD ;
	   A->filsD  = A->filsG;
	   A->filsG = temp ;
	inverse(A->filsG) ;
	inverse(A->filsD) ;

    }
}

void liberer(ptr_arbre &A)
{  
	if(A!=NULL) 
   {
	liberer(A->filsG) ;
	liberer(A->filsD) ;
	free(A) ;
   }

}

int nb_noeuds(ptr_arbre A)
{
    if(A==0) return 0 ; 
    else return (nb_noeuds(A->filsG)+nb_noeuds(A->filsD)+1) ;


}
/******************************************************** Exercice 2 ******************************************************/ 

int main() {
	ptr_arbre A ;
	creation_fichier("TD5.txt") ;
	remplir_arbre("TD5.txt",A); 
	FILE *f ;
	f=fopen("TD5.txt","wt") ;
	//sauvegarde(A,f) ;
	printf("%d",feuilles(A,f));
	fclose(f) ;
	
	//printf("",cherche(A, "ayman") ) ;
	
	
	return 0 ;}

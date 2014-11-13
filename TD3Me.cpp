#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef char str[80];

typedef struct noeud *ptr ;
struct noeud {str ch; 
         ptr suiv;
         };
typedef ptr tab_ptr[40];

void inser_fin(ptr &L, str S)
{ ptr p , fin;
  p=(ptr)malloc(sizeof(struct noeud)) ;  
 if(p==NULL) { printf("Echec d'insertion fin \n"); exit(1); } 
  strcpy(p->ch,S) ;
  p->suiv = NULL ; 
  if(L==NULL) L=p ;  
else
{fin=L;
 while(fin->suiv!=0) // recherche de la derniere noeud 
 fin=fin->suiv;
   fin->suiv=p;
 
}
}
void inser_tete(ptr &L, str S)
{ ptr p ; 
  p=(ptr)malloc(sizeof(struct noeud));
  if(p==NULL) {printf("Echex d'indertion tete \n"); exit(1) ;}
  strcpy(p->ch,S) ; 
  p->suiv = NULL ; 
  if(L==NULL) L=p ; 
  else 
   {  p->suiv = L ; 
      L= p ; 	
	
   }
}
int recherche_liste(ptr L, str S)
{  ptr p ; 
 for(p=L ; p!=NULL ; p=p->suiv)
 	if (strcmp(p->ch,S)==0) return 1; 
 	return 0 ; 

}
int liste_occurrence_car(ptr L, char c)
{ int cmp=0 ; 
   ptr p  ; 
   int i ; 
  for(p=L ; p!=NULL ; p=p->suiv)
	for(i=0 ; i<strlen(p->ch) ; i++) 
	 if(p->ch[i] == c) cmp ++ ; 
	return cmp ; 
	
}

char* concat_chaine_liste(ptr L)
{ ptr p ; 
 char *ch ;
 ch=(char*)malloc(100*sizeof(char)) ;
 if(ch==0) {printf("pas d espace memoire"); exit(1) ; }
  if(L==0) strcpy(ch,"");
 else 
{ strcpy(ch,L->ch);

for(p=L->suiv;p!=0;p=p->suiv)
{strcat(ch," ");
strcat(ch,p->ch); 
}
} 
  return ch ;
} 
void affiche_liste(ptr L)
{  
  	
	while(L!=NULL)
	  { printf("%s ",L->ch) ; 
	  L=L->suiv ; 
      }
  printf("\n") ;   
}
int nb_noeud(ptr L)
{ int cmp = 0  ; 
  while(L!=NULL)  
  { cmp++ ;
   L=L->suiv ; 
  }
  return cmp ;
}


void tri_liste(ptr L)
{ptr p  ;
 str temp ; 
 int n , a  ;
 n=  nb_noeud(L) ;
do{
a=0 ;  
for(p=L ; p->suiv!=NULL ; p=p->suiv) 
  if(strcmp(p->ch,p->suiv->ch) >0)
     { strcpy(temp,p->suiv->ch);
        strcpy(p->suiv->ch,p->ch) ;
        strcpy(p->ch,temp) ; 
       
		 
      
 a=1 ; 
 }
 n--; 
 
}while(a==1);
}
int palindrome(str S)
{ int i, j ; 
  int n = strlen(S) ; 
   for(i=0, j=n-1 ; i<j ; i++ ,j--)
    if(S[i]!=S[j]) return 0 ; 
	return 1 ;
	}

void liste_palindrome(ptr L, ptr &LP)
{ ptr p ;
   LP=0 ; 
   if(L==0) printf("la lsite est vide \n");
  else 
   for(p=L ; p!=NULL ; p=p->suiv)
    if(palindrome(p->ch)) 
     inser_fin(LP,p->ch);
}

int liste_palindrome(ptr L)
{
ptr p ; 
   if(L==0) printf("la lsite est vide \n");
  else 
   for(p=L ; p!=NULL ; p=p->suiv)
    if(!palindrome(p->ch)) return 0 ; 
     return 1; 
	
}

void tab_liste_palindrome(tab_ptr T, int n, tab_ptr &TP, int np)
{ int i , j=0   ; 
  ptr  p ; 
  for(i=0 ; i<n ; i++)
   if(liste_palindrome(T[i])) 
   { TP[j] = 0 ;
     for(p=T[i] ; p!=0 ; p=p->suiv)
      inser_fin(TP[j], p->ch); 
	  j++ ;  
	}  

}
int nombre(str S)
{
int i;
for(i=0;i<strlen(S);i++)
if (!isdigit(S[i]) ) return(0);

return(1);    
}

void liste_nombre(ptr L, ptr &LN)
{ LN = 0 ; 
  ptr p  ; 
 for(p=L ; p!=0 ; p=p->suiv)
   if(nombre(p->ch))  
    inser_fin(LN ,p->ch); 

}

int identificateur(str S)
{
int i;
if (!isalpha(S[0]) ) return(0);

for(i=1;i<strlen(S);i++)
if (!isalnum(S[i])) return(0);

return(1);    
}

void liste_identificateu(ptr L, ptr &LI)
{ 	
LI = 0 ; 
  ptr p  ; 
 for(p=L ; p!=0 ; p=p->suiv)
   if(identificateur(p->ch))  
    inser_fin(LI ,p->ch); 	
}

int liste_egale(ptr L1, ptr L2)
{  
if(nb_noeud(L1)!=nb_noeud(L2)) return (0) ; 

while((L1!=0) && (L2!=0))
  {
  if(strcmp(L1->ch,L2->ch) != 0) return (0);
  L1=L1->suiv ; 
  L2=L2->suiv ;
  }
  return (1) ;
	
	
}

int main(){
	ptr L1 =0, L2 =0 ,L3 = 0 , L4 = 0 , LN , LI; 
	str p , t ,f  ; 
	tab_ptr T , TP ; 
	int i ;
	 
	strcpy(p,"Googler");
	strcpy(t,"the");
	strcpy(f,"Aymane");
	
	inser_tete(L1, "Goo23r56gler") ; 
	inser_tete(L1, "457656") ; 
	inser_tete(L1, "Aymane") ;  
	inser_tete(L1, "su2014g45mmit") ; 
	inser_tete(L1, "2222454") ; 
	inser_tete(L1, "cv1ll34l") ;  
	liste_nombre(L1, LN) ;
	liste_identificateu(L1,LI) ; 
	affiche_liste(LI) ;
    //inser_tete(liste , "fffff") ;
    inser_tete(L3 , "maddam") ;
    //inser_tete(liste2 , "aymane") ;
    inser_tete(L3 , "abcddcba") ;
    //inser_tete(liste2 , "cool") ;
    inser_tete(L3 , "cooc") ;
    //inser_tete(liste2 , "the") ;
    inser_tete(L2, "bbbbb") ; 
	inser_tete(L2, "lol") ; 
	inser_tete(L2, "kinddnik") ; 
	
	inser_tete(L4, "summit") ; 
	inser_tete(L4, "MENAT") ; 
	inser_tete(L4, "Istanbul") ; 
	
	T[0] = L1;
	T[1] = L2;
	T[2] = L3;
	T[3] = L4;
	 
	tab_liste_palindrome(T, 4, TP,2) ;
	 for(i=0 ; i<2 ; i++)
	  //affiche_liste(TP[i]) ; 
	//printf("\n%d\n",nb_noeud(liste)) ; 
	//~ printf("\n%d",recherche_liste(liste, "Ayma")) ; 
	//~ printf("\n%d",liste_occurrence_car(liste,'e')) ; 
	//printf("\n%s",concat_chaine_liste(liste));
	//tri_liste(liste) ;
	//affiche_liste(liste2) ;
	 //int pa = liste_palindrome(liste2) ;
	 //printf("\n pa = %d",pa);
    
	 
	return 0 ;}

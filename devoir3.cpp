#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 8


//______________________________________________ DEVOIR 3 : ACHE _____________________________________________________

typedef struct S {
	 int indI ; 
	 int indJ ;
	 int dim ;
	 float moy ;
	
	} bloc_homog ; 
	



typedef int MatI[max][max] ; 
int n , m , s=0  , cmp = 0;  // pour compter le nombre des 
float seuil = 5 , y ; 
MatI M , N ;
MatI *tab ;
bloc_homog *T ; 
FILE *f ; 

int M1[8][8]={ {10,10,20,20,40,40,40,40},
{10,10,20,20,40,40,40,40},
{30,30,50,50,40,40,40,40},
{30,30,50,50,40,40,40,40},
{60,60,60,60, 5, 5,20,20},
{60,60,60,60, 5, 5,20,20},
{60,60,60,60,20,20, 7,5},
{60,60,60,60,20,20, 7, 7}};





void saisi() ; 
float cal_moy(MatI M , int k , int l , int taille) ; 
float ecart_type(MatI M , int k , int l , int taille) ; 
int test_homogene(MatI M , int  k , int l , int taille) ;
void etudier_mat(MatI M , int k , int l , int dim) ;
void affiche_mat(MatI M , int n) ;
void change_block_ligne(MatI M , int dim) ;
void change_block_colone(MatI M , int dim) ;
void change_block_lateral(MatI M , int dim) ;
void affich_blocs_homog(bloc_homog *y , int n  ) ;
void mat_approximative(bloc_homog *T) ;
void remplir_mat_fichier(FILE *f) ;

 int main() {
	  n = 8 ;
	 int k = 0 , l= 0 ,dim  ;
	 
	 //________________________________________QUESTION 1________________________________________________________________
	 
	 saisi() ; 
	 dim = n ;
	 // La fonction qui remplit le tableau des blocs homogénes
	 etudier_mat(M1, k , l , dim) ;
	 // La fonction qui affiche le tableau des blocs homogénes
	  affich_blocs_homog(T,s);
   //________________________________________QUESTION 2________________________________________________________________
   
   
   
	 // La fonction qui génére la matrice approximative
	mat_approximative(T) ;
	
 //__________________________________________QUESTION 3________________________________________________________________
 
 
 
 	
	// La fonction qui reemplit la matrice à partir d'un fichier
    remplir_mat_fichier(f) ;
    // Refaire le travail avec la matrice remplit du fichier 
	etudier_mat(N, k , l , dim) ;
	//  Affichage des blocs homogénes de la matrice N (remplit à partir du fichier)
	affich_blocs_homog(T,s);
     
   

  
	 return 0 ; 
	 }

void saisi() {
	//int i , j ; 
	// Saisi de la dimension
	b :
	printf("Donner la dimension n \n") ; 
	scanf("%d",&n) ; 
	
	if(n%2 != 0)  goto b ;
    
    //Allocation dynamique 
    
     T=(bloc_homog*)malloc(20*sizeof(bloc_homog)) ;     	  

	  //Saisi de la matrice
	printf("Donner les elements de la matrice M \n") ; 
	 for(i=0 ; i<n ; i++)
	   for(j=0 ; j<n ; j++)
	    //printf("[%d][%d] = ",i,j) ; 
	       M[i][j] = rand()% n ; 
	    }
	printf("\n Voila la matrice saisi \n ") ; 
	 for(i=0 ; i<n ; i++)
	   {for(j=0 ; j<n ; j++)
	    { printf("%d",M[i][j]) ; 
	     printf("\t") ;
	    }
	    printf("\n") ;
	 }
	 */
	}	 
	 

float cal_moy(MatI M , int k , int l , int taille) {
	int i , j ; 
	float moy ; 
	for(i=k  ;  i<taille+k ; i++)
	 for( j=l ;  j<taille+l ;  j++)
	 moy+=M[i][j] ;
	 moy/=taille*taille ; 
	  return moy ; 
	
	}
	
float ecart_type(MatI M , int k , int l , int taille) {
	int i , j ; 
	double ecat_type  = 0 ;
	y = cal_moy(M , k, l, taille) ;
	
	 for(i=k ;  i<taille+k ; i++)
	   for( j=l ;  j<taille+l ;  j++)
	  ecat_type+=pow((M[i][j]-y),2) ;
	ecat_type = ecat_type*1/(taille*taille) ; 
	ecat_type=sqrt(ecat_type) ;
     return ecat_type ;	     
	
	}
	
int test_homogene(MatI M , int  k , int l , int taille){
	float r = ecart_type(M , k, l, taille) ;
	if(r<seuil)
	 return 1 ; 
	 else 
	 return 0 ;

	}
	

	
	
	
void etudier_mat(MatI M , int k , int l , int dim){
      
    
    if(test_homogene(M,k,l,dim) == 1) 
    {
		
	
	 
		
		T[s].indI = k ; 
		T[s].indJ = l ; 
		T[s].dim = dim; 
		T[s].moy = cal_moy(M,k,l,dim) ; 
		s++;
		printf(" \n  s = %d \n",s);
		
    }		
    else
    {
	 dim = dim /2 ;
	 if(dim>=2)
        
      {
		etudier_mat(M,k,l,dim);  
		etudier_mat(M,k,l+dim,dim);
        etudier_mat(M,k+dim,l,dim);
        etudier_mat(M,k+dim,l+dim,dim);
	   }
	  
      }
    
  
 }
	

void affiche_mat(MatI M , int n)
{  int  i , j ; 
  for(i=0 ; i<n ; i++)
	   {for(j=0 ; j<n ; j++)
	    { printf("%d",M[i][j]) ; 
	     printf("\t") ;
	    }
	    printf("\n") ;
	 }
	
	}	
	
	
void affich_blocs_homog(bloc_homog *y , int n  ){
	int i ; 
	 for(i=0;i<n;i++)
	printf("\n {%d %d %d %f} \n",y[i].indI,y[i].indJ,y[i].dim,y[i].moy); 
	
	}
	
void mat_approximative(bloc_homog *T){
	int i = 0 , j = 0  , k;
	  for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	     M[i][j] = 0 ;
	     for(k=0;k<20;k++) 
	     { 
			  
	      for(i=T[k].indI;i<T[k].dim;i++) 
	        {for(j=T[k].indJ;j<T[k].dim;j++)   
       	     M[i][j]+=T[k].moy ;
		    }
		    T[k+1].dim+=T[k+1].dim ;
         } 
         
         
     affiche_mat(M ,n);
	}	
	
void remplir_mat_fichier(FILE *f){
		   int b  , i ,j   ;
	  f= fopen("fich.txt","r+");
	  
	 
	 // for(i=0;i<n;i++)
	   // for(j=0;j<n;j++)
	     // N[i][j] =  0 ;
	    //{  //fscanf(f, "%d", &b);
	//    while(!feof(f))
	  // {    fscanf(f, "%d", &b);
	    //   printf(" \n %d \n", b);
	    
	  
	     
	     for(i=0;i<n;i++)
	      for(j=0;j<n;j++)
	   
	    {  fscanf(f, "%d", &b);
	       N[i][j] = b ;
	       printf(" \n %d \n", N[i][j]);
	    
	     }
	 
 
	      fclose(f) ; 
	     affiche_mat(N,n);
       
         
   
}
	
	
	
	
	
	
	
//----------------------------------------------------------FIN-------------------------------------------------------	
	
	
	
/*
 
void change_block_ligne(MatI M , int dim){
	int i, j , temp ; 
	 for(i=0 ; i<dim ; i++)
	   {for(j=dim ; j<m ; j++) 
	     { temp = M[i][j-dim] ;
	      M[i][j-dim] = M[i][j] ;
	      M[i][j] = temp ;
	    }	  
	   }
	affiche_mat(M ,n) ;
	
	}
void change_block_colone(MatI M , int dim){
	int i, j , temp ; 
	 for(i=dim ; i<m ; i++)
	   {for(j=0 ; j<dim ; j++) 
	     { temp = M[i-dim][j] ;
	      M[i-dim][j] = M[i][j] ;
	      M[i][j] = temp ;
	    }	  
	   }
	affiche_mat(M ,n) ;
	
	}

void change_block_lateral(MatI M , int dim){
	int i, j , temp ; 
	 for(i=dim ; i<m ; i++)
	   {for(j=dim ; j<m ; j++) 
	     { temp = M[i-dim][j-dim] ;
	      M[i-dim][j-dim] = M[i][j] ;
	      M[i][j] = temp ;
	    }	  
	   }
	affiche_mat(M ,n) ;
	
	}


	
	int  cmp = 0 ; 
	  n=n/2 ;  
    	   
		 if(n>=2)
		  { 
		   if(test_homogene(M,n) == 1)    {cmp++ ; printf("bloc homogene : {%d , %d , %d , %f} \n",n,0,0,cal_moy(M,0,0,n)); }
		   //n=n/2 ;
		   //change_block_ligne(M , n) ;
		   etudier_mat( n); 
		   
			  
		hange_block_ligne(M , n) ;
		      //etudier_mat(4*nbr_blocs , n);
		        if(test_homogene(M,n) == 1)  {  cmp++ ;printf("bloc homogene : {%d , %d , %d , %f} \n",n,0,0+n,cal_moy(M,0,0,n)); }
			   
			   change_block_colone(M , n) ;
		      //etudier_mat(4*nbr_blocs , n);
		        if(test_homogene(M,n) == 1)  {  cmp++ ;printf("bloc homogene : {%d , %d , %d , %f} \n",n,0+n,0,cal_moy(M,0,0,n)); }
			
			   change_block_lateral(M , n) ;
		      //etudier_mat(4*nbr_blocs , n);
		        if(test_homogene(M,n) == 1)  {  cmp++ ;printf("bloc homogene : {%d , %d , %d , %f} \n",n,0+n,0+n,cal_moy(M,0,0,n)); }
			   
	    }
     
	  printf(" \n le nmb des blocs homogenes est : %d \n",cmp);    
    */
    
    
    
    
    









	
	
	
	
	

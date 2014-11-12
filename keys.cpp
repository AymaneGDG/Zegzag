#include<stdio.h>
#include<stdlib.h> 


  typedef struct S {
	  int id ;
	  int rm  ; 
	  } ligne ; 

int re(int a , int n , int b[100]) {
	int i  ;
	 for(i=0 ; i<n ; i++)
	  if(a == b[i]) return 1 ;
	  return 0 ; 
 }

int main() {
	freopen("keys.in","rt",stdin) ; 
	freopen("keys.out","wt",stdout) ; 

	  
  
 int TT , j , k=0 , cmp , l = 0 ;
 scanf("%d",&TT) ; 
 int i = 1 ;  
 while(TT--){
	  cmp = 0 ;
	 int N, M, H ; 
	 scanf("%d%d%d",&N,&M,&H);
	 ligne T[H] ;
	  
	  int    t1[M] , t2[H]  ; 
	  
	  int e = H ; 
	 while(H--){
		
		
		
		 scanf("%d%d",&T[k].id,&T[k].rm); 
		
			
			k++ ;  
		  
       }
       
 
		 
	 for(j=0 ; j<M ; j++)  t1[j]= N-j ; 
	 for(j=0 ; j<e ; j++)  t2[j]= 0 ; 
	 
	 for(j=0 ; j<e ; j++) 
	   
	   if(T[j].rm >= t1[M-1] && re(T[j].id , e , t2) == 0)
	      {
		    
	
	       
	       t2[l] = T[j].id ;
	       cmp++ ;
	       l++ ;
	       
	      }
	    
	  
	printf("Case %d: %d\n",i,cmp);
	    	 
	    
	   i++ ; 
	   l=0 ;
	   k=0;
	   j=0; 
	   	 
	
	 }
 
 
 
 return 0 ; }

#include <bits/stdc++.h>




using namespace std;

typedef struct S{
	
	int time1 ;
	int time2 ;
	
	} jour;


void tri(jour T[] , int n){
	int j , l ; 
	for(l=1 ; l<n ; l++)
	{for(j=1 ; j<n ; j++)
	{
		 if(T[j].time1 < T[j-1].time1)
	  {
	    swap(T[j].time1,T[j-1].time1) ; 
	    swap(T[j].time2,T[j-1].time2) ; 
	  }
	}
    }
	}

void max(jour T[] , int n , int y[3]){
   
	int j , max = 0 ; 
	int   heure_dep = 10 ;
	 int  min_dep = 0 ; 
	 
	  
	    max = T[0].time1-10*60 ;
	for(j=1 ; j<n ; j++)
	   { 
	    
	   
	      
	    
		if(max<T[j].time1-T[j-1].time2)
	  
	     { max = T[j].time1-T[j-1].time2 ; 
	       heure_dep = T[j-1].time2/60  ;
		   min_dep = (int)T[j-1].time2%60 ;
	     }
	   
	   }
	    if(max<18*60-T[n-1].time2)
	    { 
		  max=18*60-T[n-1].time2 ;
	      heure_dep = T[n-1].time2/60  ;
		  min_dep = (int)T[n-1].time2%60 ;
	     }
	 
	     
	     y[0] = max ;
	      y[1] = heure_dep ;
	       y[2] = min_dep ;
	      
	        
	}



int main() {
	freopen("in.txt","rt",stdin) ; 
	freopen("out1.txt","wt",stdout) ;
int n , i , k = 1  ,h1 ,m1 , h2 , m2 , e , h3 ,m3;
 
string s ; 
while(scanf("%d",&n) != EOF)
{
i=0 ;
jour T[n] ;  
int y[3] ;

e = n  ;

while(n--){
	
	scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
	getline(cin , s) ;
	if((h1 > h2) || (h1<10)  || (h1>18) || (m1>60) || (h2<10)  || (h2>18) || (m2>60)) goto fin  ;  
	T[i].time1  = h1*60+m1 ; 
	T[i].time2 = h2*60+m2 ; 
	
	 i++ ;
    
	
   }
	tri(T, e) ;
	
	
	max(T,e,y) ;

   

	   h3 = y[0]/60 ; 
		m3 = y[0]%60  ;
		
   		if(y[2] == 0)
		 {
	
	if(h3 == 0)	
	printf("\nDay #%d: the longest nap starts at %d:%d%d and will last for %d minutes.",k,y[1],0,y[2],m3) ; 	
	else if(m3==0)
	printf("\nDay #%d: the longest nap starts at %d:%d%d and will last for %d hours and 0 minutes.",k,y[1],0,y[2],h3) ;
	else
	printf("\nDay #%d: the longest nap starts at %d:%d%d and will last for %d hours and %d minutes.",k,y[1],0,y[2],h3,m3) ;
	  
		
		}
		
		
		   		else if(0<y[2] && y[2]<10)
		 {
	
	if(h3 == 0)	
	printf("\nDay #%d: the longest nap starts at %d:0%d and will last for %d minutes.",k,y[1],y[2],m3) ; 	
	else if(m3==0)
	printf("\nDay #%d: the longest nap starts at %d:0%d and will last for %d hours and 0 minutes.",k,y[1],y[2],h3) ;
	else
	printf("\nDay #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.",k,y[1],y[2],h3,m3) ;
	  
		
		}
		
	else	
	 {
		 if(h3 == 0)	
	printf("\nDay #%d: the longest nap starts at %d:%d and will last for %d minutes.",k,y[1],y[2],m3) ; 	
	else if(m3==0)
	printf("\nDay #%d: the longest nap starts at %d:%d and will last for %d hours and 0 minutes.",k,y[1],y[2],h3) ;
	else
	printf("\nDay #%d: the longest nap starts at %d:%d and will last for %d hours and %d minutes.",k,y[1],y[2],h3,m3) ;
		 
		 
		 }	 
		
		
	k++ ;
	
	
	
    }
	 



 fin :

return 0; }

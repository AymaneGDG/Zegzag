#include <bits/stdc++.h>




using namespace std;

int main() {
	freopen("inin.in","rt",stdin) ; 
	freopen("outout.out","wt",stdout) ; 
	
int T , i ,j=1 , v , k ; 
scanf("%d",&T) ;
string s ;
while(T--){

	
	int N,M;
	scanf("%d%d",&N,&M) ; 
	 cin>> s;
//for(int i=0;i<(int)s.size();i++)
//cout << s[i]<<endl;
//cout << s[0]<<endl ;
	
	
    if(M%2==0) v= N/M ; 
    else v=N/M -1; 
    //i =0;
     k =0;
    // printf("%c\t",s[0]);
	 // printf("%c\n",s[N-(k+1)*M]);
    while(k<v)
    {
 
	for(i=0 ; i<M ; i++)
	{
	if(s[i+k*M] != s[i+N-(k+1)*M]) 
	  { printf("Case %d: No\n",j);
        break ;
      }
	 
    }

    k++  ;
     
	  printf("Case %d: Yes\n",j);
    
    }
   // l :
    
   j++ ;
  //  
}
	return 0 ;} 

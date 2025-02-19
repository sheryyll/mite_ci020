/*Apples and oranges
Rushitote went to a programming contest to distribute apples and oranges to the contestants.
He has N apples and M oranges, which need to be divided equally amongst the contestants. 

Find the maximum possible number of contestants such that:
	Every contestant gets an equal number of apples; and Every contestant gets an equal number of oranges.
Note that every fruit with Rushitote must be distributed, there cannot be any left over.

For example, 
2 apples and 4 oranges can be distributed equally to two contestants, where each one receives 1 apple and 2 oranges.
However, 2 apples and 5 oranges can only be distributed equally to one contestant.*/
// WITHOUT FUNCTION
#include <stdio.h>

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	    int n,m;
	    scanf("%d%d",&n,&m);
	    
	    while(m!=0){
	        int temp = m;
	        m = n%m;
	        n = temp;
	        
	    }
	    printf("%d\n",n);
	}
//WITH FUNCTION
#include <stdio.h>

int gcd(int n,int m){
    while(m!=0){
	        int temp = m;
	        m = n%m;
	        n = temp;
	        
	    }
	    return abs(n);
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	    int n,m;
	    scanf("%d%d",&n,&m);
	    
	   int ppl = gcd(n,m);
	   printf("%d\n",ppl);
	}
}

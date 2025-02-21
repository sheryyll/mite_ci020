/*Remove Duplicates
You are given an array A1,A2,…,An of length N sorted in non-decreasing order.
Your task is to remove all the duplicates and find the sorted increasing array of
distinct elements consisting of all distinct elements present in A.\

Input Format
	*The first line of input will contain a single integer T, denoting the number of test cases.
	*The first line of each test case contains an integer N - the length of the array A.
	*The second line of each test case contains N space-separated integers A1,A2,…,An.
Output Format
For each test case, output two lines:
	*The first line should contain a single integer M - the size of the array.
	*The second line should contain M space-separated integers denoting the elements of the array.*/
#include <stdio.h>
int logic(int n,int a[]);
void printingsorted(int a[],int sorted);

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
    while(t--){
        int n;
	    scanf("%d",&n);
      
	    int* a =(int *)malloc(n *sizeof(int));
	    
        for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    }
	    int sorted = logic(n,a);
	    printf("%d\n",sorted);
	    printingsorted(a,sorted);
	    free(a);
    }
    return 0;

}
int logic(int n,int a[]){
    int idx =0;
    for(int i=1;i < n;i++){
        if(a[idx]!=a[i]){
            idx++;
            a[idx] = a[i];
        }
    }
    return idx+1;
}
void printingsorted(int a[],int sorted){
    for(int i=0; i<sorted ;i++){
	        printf("%d ",a[i]);
	    }
	    printf("\n");
}


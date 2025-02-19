
/*1. Memory Management for Student Marks (Using Dynamic Memory Allocation)"
"Problem Statement:"  
A school wants to dynamically allocate memory for "N students" and store their "marks" using "malloc()".  

1. Read "` students’ marks.  
2. Find the "average marks".  
3. Free the allocated memory using "free()".  

"Function Prototype Example:"  
    void inputMarks(int *marks, int n);
    float calculateAverage(int *marks, int n);

Sample Test Case:
Input: 
Enter number of students: 3  
Enter marks: 78 85 90  
Output: 
Average Marks: 84.33  
*/

#include<stdio.h>
void inputmarks(int *marks, int n){
    printf("Enter marks: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&marks[i]);
    }
}

float calculateAverage(int *marks, int n){
    int sum = 0;
    for(int i = 0 ; i< n; i++){
        sum += marks[i];
    }
    float average = (float)sum / (float)n;
    return average;
}
int main(){
    int n;
    int marks[1000];
    printf("Number of subjects: ");
    scanf("%d",&n);
    
    inputmarks(marks,n);
    float average = calculateAverage(marks,n);
    printf("Average Marks: %.2f\n",average);
    return 0;
}
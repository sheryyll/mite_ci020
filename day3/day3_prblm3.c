/*2. Student Marks Sorting (Using 2D Arrays)
"Problem Statement:"  
A college stores student marks in a "2D array" where:  
- "Rows represent students"  
- "Columns represent subjects"  
1. Read marks for "N students" across "M subjects".  
2. Calculate and display each student's "total marks".  
3. Sort students in "descending order of total marks".  

"Function Prototypes:"  
    void calculateTotalMarks(int marks[][M], int n, int totalMarks[]);
    void sortStudents(int totalMarks[], int n); */

#include<stdio.h>
#define max_subjects 10


void calculateTotalMarks(int marks[][max_subjects], int studentCount,int subjectCount, int totalMarks[]){
    for(int i=0;i<studentCount;i++){
        totalMarks[i] = 0;
        for(int j=0; j<subjectCount;j++){
            totalMarks[i]+=marks[i][j];
        }
    }
}

void swap(int *first, int *second){
    int temp = (*first);
    (*first) = (*second);
    (*second) = temp;
}

void sortStudents(int totalMarks[], int studentCount){
    int isSwapped =0 ;

    do{
        isSwapped = 0;
        for(int i=0; i< studentCount-1;i++){
            if(totalMarks[i]<totalMarks[i+1]){
                swap(&totalMarks[i],&totalMarks[i+1]);
            }   isSwapped = 1;
        }
        studentCount--;
    }while(isSwapped);
}

void inputMarks(int marks[][max_subjects],int studentCount, int subjectCount){
    printf("\nEnter marks: ");
    for(int i=0; i<studentCount; i++){
        printf("\nStudent %d: ",i+1);
        for(int j=0; j<subjectCount;j++);{
            scanf("%d",&marks[i][j]);
        }
    }

}
void printTotalMarks(int totalMarks[], int studentCount){
    for(int i=0;i<studentCount;i++){
        printf("Total Marks: %d\n",totalMarks[i]);
    }
}

int main(){
    int subjectCount, studentCount;
    int marks[1000][max_subjects];
    int totalMarks[1000] = { };
    printf("Enter number of students:");
    scanf("%d",&studentCount);
    printf("\nEnter the Subject count: ");
    scanf("%d",&subjectCount);

    inputMarks(marks,studentCount,subjectCount);
    calculateTotalMarks(marks,studentCount,subjectCount,totalMarks);
    sortStudents( totalMarks,studentCount);
    printTotalMarks(totalMarks,studentCount);
    return 0;
}
/*
1. Employee Database using Structures 
"Problem Statement:"  
Create a structure "Employee" with the following fields:  
- "ID" (integer)  
- "Name" (string)  
- "Salary" (float)  
- "Department" (string)  

Write a program that:  
1. Reads "N employees" and stores them in an array of structures.  
2. Displays all employee details.  
3. Finds and displays the employee with the "highest salary".  

"Function Prototypes:"  
    void readEmployees(Employee emp[], int n);
    void displayEmployees(Employee emp[], int n);
    Employee findHighestSalary(Employee emp[], int n);


"Sample Test Case:"  
"Input:"  
Enter number of employees: 3  
Enter details (ID, Name, Salary, Department):  
1 John 50000 IT  
2 Alice 60000 HR 
3 Bob 55000 Sales  

"Output:"  

Employee with Highest Salary: Alice, 60000 (HR)  */

#include<stdio.h>
struct Employee{
    int id;
    char name[250];
    float salary;
    char department[50];
};

typedef struct Employee Employee;

void readEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);

int main(){
    int employeeCount;
    printf("Enter the number employees: ");
    scanf("%d",&employeeCount);

    Employee employees[1000];
    readEmployees(employees,employeeCount);
    displayEmployees(employees,employeeCount);
    Employee higheshtSalaried = findHighestSalary(employees,employeeCount);
    printf("Employee with highest salary: %s, %2.f (%s)\n",higheshtSalaried.name,
        higheshtSalaried.salary,higheshtSalaried.department);

    return 0;

}
void readEmployees(Employee emp[], int n){
    for(int i=0;i<n;i++){
        printf("Enter the employee %d details (ID,Name,salary,department): \n",i+1);
        scanf("%d%s%f%s",&emp[i].id,emp[i].name
            ,&emp[i].salary,emp[i].department);
    }   
}

void displayEmployees(Employee emp[], int n){
    printf("\nEmployee Details: ");
    for(int i=0;i<n;i++){
        printf("Employee %d: %d %s %s %f\n",i+1,emp[i].id,emp[i].name
            ,emp[i].department,emp[i].salary);
    }
}
q
Employee findHighestSalary(Employee emp[], int n){
    Employee highestSalaried = emp[0];
    for(int i=0;i<n;i++){
        if(emp[i].salary > highestSalaried.salary){
            highestSalaried = emp[i];
        }
    }
    return highestSalaried;
}
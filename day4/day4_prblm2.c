/*1. Employee Database using Structures
"Problem Statement:"  
Create a structure `Employee` with the following fields:  
- "ID" (integer)  
- "Name" (string)  
- "Salary" (float)  
- "Department" (string)  

Write a program that:  
1. Reads "N employees" and stores them in an array of structures.  
1.1 Write N employees into text file "employees.txt" (space separated fields 
    and write each employee in new line)
1.2 Read N employees from employees.txt file
2. Displays all employee details.  
3. Finds and displays the employee with the "highest salary".  

"Function Prototypes:"  
    void readEmployees(Employee emp[], int n);
    void saveEmployees(Employee emp[], int n);
    void loadEmployees(Employee emp[], int n);
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
struct Employee_t {
    int id;
    char name[255];
    float salary;
    char department[50];
};
typedef struct Employee_t Employee;
void readEmployees(Employee emp[], int n);
void saveEmployees(Employee emp[], int n);
void loadEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);
int main() {
    int employeeCount;
    printf("Enter number of employees:");
    scanf("%d", &employeeCount);
    Employee employees[1000];
    readEmployees(employees, employeeCount);
    saveEmployees(employees, employeeCount);
    loadEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);
    Employee highestSalariedEmployee = findHighestSalary(employees, employeeCount);
    printf("Employee with highest salary: %s, %.2f (%s)\n",
        highestSalariedEmployee.name,
        highestSalariedEmployee.salary,
        highestSalariedEmployee.department);
    return 0;
}
void readEmployees(Employee emp[], int n) {
    printf("Enter details (ID, Name, Salary, Department):\n");
    for(int i = 0; i < n; i++) {
        scanf("%d%s%f%s", &emp[i].id, emp[i].name, 
                          &emp[i].salary, emp[i].department);
    }
}
void saveEmployees(Employee emp[], int n) {
    FILE* file = fopen("employees.txt", "w");
    if(file == NULL) {
        printf("Cannot create file.\n");
        return;
    }
    
    for(int i= 0; i< n; i++) {
        fprintf(file, "%d %s %.2f %s\n", emp[i].id, emp[i].name, 
                                emp[i].salary, emp[i].department);
    }
    
    fclose(file);
}
void loadEmployees(Employee emp[], int n) {
    FILE* file = fopen("employees.txt", "r");
    if(file == NULL) {
        printf("Cannot read file.\n");
        return;
    }
    
    for(int i = 0; i < n; i++) {
        fscanf(file, "%d %s %f %s\n", &emp[i].id, emp[i].name, 
            &emp[i].salary, emp[i].department);
    }
    
    fclose(file);
}
void displayEmployees(Employee emp[], int n) {
    printf("Employees:\n");
    for(int i = 0; i < n; i++) {
        printf("%d - %s - %.2f - %s\n", emp[i].id, emp[i].name, 
                                emp[i].salary, emp[i].department);
    }
}
Employee findHighestSalary(Employee emp[], int n) {
    Employee highestSalaried =  emp[0];
    for(int i = 1; i < n; i++) {
        if(emp[i].salary > highestSalaried.salary) {
            highestSalaried = emp[i];
        }
    }
    return highestSalaried;
}

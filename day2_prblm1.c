#include<stdio.h>
#include<string.h>
int main()
{
    int days_admitted;
    char name[100], ward_type[20];
    float base_bill = 0.0f,discount = 0.0f ,total_bill = 0.0f;
    // INPUT DATA
    printf("Enter the Patient Name: ");
    scanf("%s",name);
    printf("\nEnter Ward Type (G/S/P): ");
    scanf("%s",ward_type);
    printf("\nEnter the number of days: ");
    scanf("%d",&days_admitted);
     
    //logic
    if(strcmp(ward_type,"G")==0){
        base_bill = 1000 * days_admitted;
    }
    else if (strcmp(ward_type,"S")==0){
        base_bill = 2000 * days_admitted;
    }
    else if (strcmp(ward_type, "P")== 0 ){
        base_bill = 5000 * days_admitted;
    }
    
    if(days_admitted >= 7){
        discount = (base_bill) * (5.0f/100.0f);
    }
    else{
        discount = 0.0f;
    }

    total_bill = base_bill - discount;
    
    //OUTPUT
    printf("Patient Name: %s \n",name); 
    printf("Total Bill Before Discount: %f\n",base_bill);
    printf("Discount Applied: %f\n",discount); 
    printf("Final Bill Amount: %f\n",total_bill);  

    return 0;
}
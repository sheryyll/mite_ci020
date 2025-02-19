/*"1. Electricity Bill Calculation"  
"Problem Statement:"  
A power distribution company wants to automate electricity bill generation based on the following rules:  

1. "Fixed charge = ₹100" for all consumers.  
2. "Rate per unit:"  
   - "Up to 100 units" → ₹5 per unit  
   - "101 to 300 units" → ₹7 per unit  
   - "Above 300 units" → ₹10 per unit  
3. "If the total bill exceeds ₹1000, add a 5% surcharge."  
4. The program should display 
"customer details, total units consumed, 
bill amount, and surcharge (if any)."  

Requirements: 
1. Input:  
   - Customer Name  
   - Customer ID  
   - Total Units Consumed  
2. Output: 
   - Base Bill  
   - Surcharge (if applicable)  
   - Total Bill  
  */


#include<stdio.h>

int main()
{
    int id,units;
    char name[299];

    //input data

    printf("INPUT DATA\n");
    printf("ENter Customer Id:");
    scanf("%d",&id);
    printf("\nEnter the Customer Name:");
    scanf("%s",name);
    printf("\nEnter the Total Units Consumed :");
    scanf("%d",&units);

    //bill
    float base_amount = 100.0f, total_amount = 0.0f, surgeamount = 0.0f;

    //logic
    if(units>100){
        base_amount += (100.0f * 5.0f); //first 100 units
    }
    else{
        base_amount += (units * 5.0f);
    }
    
    if(units>100 && units<300){
        base_amount += ((units - 100.0f) * 7.0f);
    }
    else if(units >300){
        base_amount += (200.0f * 7.0f);
    }

    if(units>300)
    {
        base_amount += (units - 300.0f)*10.0f;
    }

    if(base_amount >= 1000.0f){
        surgeamount = (base_amount / 100.0f) * 5.0f;
    }

    total_amount = base_amount + surgeamount;

    //printing
    printf("\nEB DETAILS\n");
    printf("\t Customer Name: %s\n", name);  
    printf("\tCustomer ID: %d\n",id);
    printf("\tUnits Consumed: %d\n",units);
    printf("\tBase Bill:₹ %.2f\n",base_amount);
    printf("\tSurcharge: ₹ %.2f\n",surgeamount);
    printf("\tTotal Bill:₹ %.2f\n",total_amount); 
}
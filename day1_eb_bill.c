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

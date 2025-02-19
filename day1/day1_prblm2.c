/*2. Toll Tax Calculation for Vehicles 
Problem Statement:  
A highway toll management system needs a program to calculate toll tax based on "vehicle type and distance traveled":  

1. `Vehicle Type & Base Charges:`  
   - Car → ₹5 per km  
   - Truck → ₹10 per km  
   - Bus → ₹8 per km  
2. If a "truck" travels "more than 500 km", a "10% discount" applies.  
3. If a "bus" travels "more than 300 km", a "5% discount" applies.  

Requirements:
1. Input: 
   - Vehicle Type (Car/Truck/Bus)  
   - Distance Traveled (km)  
2. Output:  
   - Total Toll Tax  
*/

#include<stdio.h>
#include<string.h>
int main()
{
    char vehicle_type[255];
    float distance;
    printf("INPUT DATA\n");
    printf("\nEnter Vehicle Type (Car/Truck/Bus): ");
    scanf("%s", vehicle_type);
    printf("\nEnter Distance Traveled (km): ");
    scanf("%f",&distance);

    float base_charge = 0.0f,discount = 0.0f, total_toll_tax = 0.0f;

    if (strcmp(vehicle_type, "Car") == 0) 
    {
        base_charge += distance * 5.0f;
    }
    else if (strcmp(vehicle_type, "Truck")== 0)
    {
        base_charge += distance * 10.0f;
    }
    else if (strcmp(vehicle_type, "Bus") == 0)
    {
        base_charge += distance * 8.0f;
    }
    else{
        printf("Invalid type");
    }

    if(strcmp(vehicle_type,"Truck")== 0 && distance >= 500.0f ){
        discount = (base_charge) * ( 10.0f / 100.0f);
    }
    if(strcmp(vehicle_type, "Bus") == 0 && distance >= 300.0f ){
        discount = (base_charge) * (5.0f / 100.0f);
    }

    total_toll_tax = base_charge - discount;


    //output
    printf("\nOUTPUT DETAILS:\n");
    printf("\tVehicle Type: %s\n",vehicle_type); 
    printf("\tDistance Traveled: %f\n",distance);
    printf("\tBase Charge: %f\n",base_charge); 
    printf("\tDiscount: %f\n",discount);
    printf("\tTotal Toll Tax: %f\n",total_toll_tax);

}
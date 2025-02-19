/*Reverse a String (With Built Functions)*/

#include<stdio.h>
#include<string.h>
void reversestring(char *str){
    int len = strlen(str);
    for(int left = 0,right = len - 1; left < right; left ++, right --){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
}

int main(){
    char str[255];
    printf("Enter a string\n");
    scanf("%s",str);
    printf("BEFORE REVERSING: %s\n",str);
    reversestring(str);
    printf("AFTER REVERSING: %s\n",str);
    return 0;

}
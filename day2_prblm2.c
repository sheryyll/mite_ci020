#include<stdio.h>
#include<string.h>
int findlength(char *str){
    int length = 0;
    for( char *p_ch = str; (*p_ch)!= '\0';p_ch++){
        length++;
    }
    return length;
}
void reversestring(char *str){
    int len = findlength(str); 
    for(int left = 0,right = len - 1; left < right; left ++, right --){
        char temp = str[left]; //*(str + length) = str[length]
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
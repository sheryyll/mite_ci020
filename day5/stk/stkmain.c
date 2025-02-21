#include<stdio.h>
#include "stack.h"
#define STACK_SIZE 1000

typedef float T;
typedef struct{
   T elements[STACK_SIZE];
   int size;
   int top;
}Stack;

void StackInit(Stack* stk);
void StackPush(Stack* stk, T element);
int StackEmpty(Stack* stk);
T StackTop(Stack* stk);
void StackPop(Stack* stk);

int main() {

    float salaries[] = {50000,48000,40000,23000,2000};
    Stack stk;
    StackInit(&stk);
    for(int i=0;i<5;i++){
        StackPush(&stk,salaries[i]);
    }
    printf("Salaries from stack: \n");
    while(!StackEmpty(&stk)){
        float sal = StackTop(&stk);
        printf("%f ",sal);
        StackPop(&stk);
    }

    return 0;
}
void StackInit(Stack* stk){
    stk->size= 0;
    stk->top =-1;
}

void StackPush(Stack* stk, T element){
    stk->elements[stk->size] = element;
    stk->size++;
    stk->top++;
}

int StackEmpty(Stack* stk){
    return (stk->top == -1);

}

T StackTop(Stack* stk){
    return stk->elements[stk->top];
}

void StackPop(Stack* stk){
    if(StackEmpty(stk)){
        printf("Stack is empty\n");
        return;
    }
    stk->top--;
    stk->size--;
}

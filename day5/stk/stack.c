#include<stdio.h>
#include "stack.h"
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

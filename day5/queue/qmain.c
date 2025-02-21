#include<stdio.h>
#define QUEUE_SIZE 1000

typedef float T;
typedef struct{
   T elements[QUEUE_SIZE];
   int size;
   int front;
   int back;

}Queue;

void QueueInit(Queue* stk);
void QueuePush(Queue* stk, T element);
int QueueEmpty(Queue* stk);
T QueueFront(Queue* stk);
T QueueBack(Queue* stk);
void QueuePop(Queue* stk);

int main() {

    float salaries[] = {50000,48000,40000,23000,2000};
    Queue stk;
    QueueInit(&stk);
    for(int i=0;i<5;i++){
        QueuePush(&stk,salaries[i]);
    }
    printf("Salaries from stack: \n");
    while(!QueueEmpty(&stk)){
        float sal = QueueFront(&stk);
        printf("%f ",sal);
        QueuePop(&stk);
    }

    return 0;
}
void QueueInit(Queue* stk){
    stk->size= 0;
    stk->front =-1;
    stk->back = -1;
}

void QueuePush(Queue* stk, T element){
    stk->back++;
    stk->elements[stk->back] = element;
    stk->size++;
    if(stk->front == -1){
        stk->front =0;
    }
}

int QueueEmpty(Queue* stk){
    return (stk->front == -1);

}

T QueueFront(Queue* stk){
    return stk->elements[stk->front];
}

T QueueBack(Queue* stk){
    return stk->elements[stk->front];
}

void QueuePop(Queue* stk){
    if(QueueEmpty(stk)){
        printf("Queue is empty\n");
        return;
    }
    
    if(stk->front == stk->back){
        stk->front = -1;;
        stk->back = -1;
        stk->size=0;
    }
    else{
        stk->front++;
    }

}

#include<stdio.h>
#include<stdlib.h>

tydef float T;
struct Node_t{
    T element;
    struct Node_t* next;
};
typdef struct Node_t Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
}List;

void ListInit(List* list);
Node* CreateNode(T element);
void ListPushFront(List* list,T element);
void ListPushBack(List* list,T element);
int ListInit(List* list);
T ListFront(List* list);
T ListBack(List* list);
void ListPopFront(List* list,T element);
void ListPopBack(List* list,T element);

int main(){
    float salaries[] = {50000,48000,40000,23000,2000};
    List list;
    ListInit(&list);
    for(int i=0;i<5;i++){
        ListPushBAck(&list,salaries[i]);
    }
    printf("Salaries from List: \n");
    for(Node* node = list.head;node!=NULL;node=node->next){
        printf("%.2f ",sal);
    }

    return 0;
}

void ListInit(List* list){
    list->head = NULL;
    list->tail=NULL:
    list->size=0;
}

Node* CreateNode(T element){
    Node* node = (Node*)malloc(sizeof(Node));
    Node->element = element;
    Node->prev = NULL;
    Node->next = NULL;
}

void ListPushFront(List* list,T element){

}

void ListPushBack(List* list,T element){
    Node* node = CreateNode(element);
    if(list->head == NULL){
        list->head = node;
        liat->tail = node;
    }
    else{
        list->tail->next = node;
        node->prev = list->tail;
    }
}

int ListInit(List* list){

}

T ListFront(List* list){

}

T ListBack(List* list){

}

void ListPopFront(List* list,T element){

}

void ListPopBack(List* list,T element){

}


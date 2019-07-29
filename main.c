#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
}NODE, *PNode;

typedef struct Stack {
    PNode pTop;
    PNode pBottom;//指向栈底的下一个没有含义的元素
}STACK, *pStack;

void init(pStack);
void push(pStack ,int );
int* pop(pStack pS) ;
bool empty(pStack pS);
void clear(pStack pS);
void showLog(pStack);

int main () {
    printf("Hello world\n");
    pStack S ;
    init(S);
    showLog(S);
    push(S , 11);
    push(S , 22);
    push(S , 33);
    push(S , 44);
    showLog(S);

    int *popValue = pop(S);
    printf("pop stack element is %d \n",*popValue);
    showLog(S);
    clear(S);
    showLog(S);
    return 0;
}

PNode creatNode() {
    PNode pN = (PNode )malloc(sizeof(NODE));
    return pN;
}

void init(pStack stack) {
    stack ->pBottom = creatNode;
    stack->pTop = stack->pBottom ;
}

void push(pStack pS ,int data) {
    // PNode pNew = (PNode )malloc(sizeof(NODE));
    PNode pNew = creatNode();
    pNew ->data = data;
    pNew ->next = pS ->pTop;
    pS ->pTop = pNew;
}

bool empty(pStack pS) {
    if (pS -> pTop == pS ->pBottom  )
    {
        printf("\n The STACK is empty !\n");
        return true;
    }
    return false;
}

int* pop(pStack pS) {
    PNode pN = pS ->pTop;
    int value = pN ->data;
    pS ->pTop = pS ->pTop ->next;
    free(pN);
    return &value;
}

void clear(pStack pS) {
    if (!empty(pS))
    {
        PNode temp = pS ->pTop;
        while (temp != pS ->pBottom)
        {
            pS ->pTop = pS ->pTop ->next;
            free(temp);
            temp = pS ->pTop;
        }   
    }
}

void showLog(pStack pS) {
    
   if (!empty(pS)) {
    PNode topNode = pS ->pTop;
    while (pS ->pBottom != topNode)
    {
        printf ("%d ->",topNode -> data);
        topNode = topNode ->next;
    }
   }

}


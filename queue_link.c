//
// Created by 임수현 on 24/08/2020.
//
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
    int size;
}queue;

void init_queue(queue* q);
void enqueue(queue* q, int x);
void dequeue(queue *q);

int main(){
    int n, i, x;
    char command[10];
    queue q;

    init_queue(&q);
    scanf("%d",&n);

    for(i=0;i<n;i++){
        getchar();
        scanf("%s", command);

        if(command[0] == 'e'){
            scanf("%d", &x);
            enqueue(&q, x);
        }
        else if(command[0] == 'd'){
            dequeue(&q);
        }
        else if(command[0] == 's'){
            printf("%d\n", q.size);
        }
        else{
            printf("%d\n", q.front->data);
        }

    }

}

void init_queue(queue* q){
    node* new = (node*)malloc(sizeof(node));
    new->next = NULL;
    q->front = new;
    q->rear = new;
    q->size = 0;
}

void enqueue(queue *q, int x){
    if(q->size == 0){
        q->rear->data = x;
    }
    else{
        node* new = (node*)malloc(sizeof(node));
        new->data = x;
        new->next = NULL;

        q->rear->next = new;
        q->rear = new;
    }
    q->size++;
}

void dequeue(queue *q){
    if(q->size == 0){
        return;
    }
    else{
        node* tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
    q->size--;
}

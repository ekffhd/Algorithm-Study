//
// Created by 임수현 on 24/08/2020.
//
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct queue{
    int* data;
    int front;
    int rear;
    int maxSize;
    int size;
}queue;

void queue_init(queue* q, int n);
void enqueue(queue* q, int x);
void dequeue(queue* q);

int main(){

    int n, i, x;
    char command[10];
    queue q;

    scanf("%d",&n);

    queue_init(&q, n);

    for(i=0;i<n;i++){
        getchar();
        scanf("%s", command);

        if(command[0] == 'e'){
            scanf("%d",&x);
            enqueue(&q, x);
        }
        else if(command[0] == 'd'){
            dequeue(&q);
        }
        else if(command[0] == 's'){
            printf("%d\n", q.data[q.size]);
        }
        else{
            printf("%d\n", q.data[q.front]);
        }

    }


    return 0;
}

void queue_init(queue* q, int n){
    q->data = (int*)malloc(sizeof(int) * n);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->maxSize = n;
}

void enqueue(queue* q, int x){
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % q->maxSize;
    q->size++;
}

void dequeue(queue* q){
    if(q->size == 0) return;
    q->front = (q->front + 1) % q->maxSize;
    q->size--;
}

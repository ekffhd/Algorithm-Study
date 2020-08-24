//
// Created by 임수현 on 24/08/2020.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct Stack{
    node* top;
    int size;
}Stack;

void init_stack(Stack* s);
void push_stack(Stack* s, int x);
void pop_stack(Stack* s);

int main(){
    int n, i, x;
    char command[5];

    Stack s;

    init_stack(&s);
    scanf("%d",&n);

    for(i = 0; i<n;i++){
        scanf("%s", command);
            if(command[1] == 'u'){
                scanf("%d",&x);
                push_stack(&s, x);
            }
            else if(command[0] == 'p' && command[1] == 'o'){
                pop_stack(&s);
            }
            else if(command[0] == 't'){
                if(s.size != 0){
                    printf("%d\n",s.top->data);
                }
            }
            else if(command[0] == 's'){
                printf("%d\n", s.size);
            }
        }

    return 0;
}

void init_stack(Stack* s){
    node* new = (node*)malloc(sizeof(node));
    new->data = 0;
    new->next = NULL;
    s->top = new;
    s->size = 0;
}

void push_stack(Stack* s, int x){
    node* new = (node*)malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    if(s->size == 0){
        s->top = new;
    }
    else{
        new->next = s->top;
        s->top = new;
    }
    s->size++;
}

void pop_stack(Stack* s){
    if(s->size == 0) return;
    node* now = s->top;
    s->top = s->top->next;
    now->next = NULL;
    free(now);
    s->size--;
}
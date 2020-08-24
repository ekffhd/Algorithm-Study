//
// Created by 임수현 on 24/08/2020.
//

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

typedef struct Stack{
    int* data;
    int maxsize;
    int top;
}Stack;

void init_stack(Stack* s, int maxsize);
void push_stack(Stack *s, int x);
void pop_stack(Stack *s);

int main(){

    int n, i, x;
    char command[5];
    Stack s;

    scanf("%d",&n);

    init_stack(&s, n);

    for(i=0;i<n;i++){
        getchar();
        scanf("%s", command);

        if(command[1] == 'u'){
            scanf("%d",&x);
            push_stack(&s, x);
        }
        else if(command[0] == 'p' && command[1] == 'o'){
            pop_stack(&s);
        }
        else if(command[0] == 't'){
            printf("%d\n",s.data[s.top]);
        }
        else if(command[0] == 's'){
            printf("%d\n", s.top+1);
        }

    }

    return 0;
}

void init_stack(Stack* s, int maxsize){
    s->top = -1;
    s->maxsize = maxsize;
    s->data = (int*)malloc(sizeof(int) * s->maxsize);
}

void push_stack(Stack *s, int x){
    if(s->top + 1 == s->maxsize) return;
    s->top++;
    s->data[s->top] = x;

}

void pop_stack(Stack *s){
    if(s->top == -1) return;
    s->data[s->top] = 0;
    s->top--;
}
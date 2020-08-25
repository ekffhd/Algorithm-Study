//
// Created by 임수현 on 25/08/2020.
//

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct node{
    struct node*    next;
    int             value;
}node;

void init_list(node* list, int v);
void link_list(node* list, int v);
void print_list(node* list, int i);

int main(){


    int i, j, v;
    int** arr;
    node* list;

    scanf("%d",&v);


    arr = (int**)malloc(sizeof(int*)*v);
    for(i=0; i<v; i++){
        arr[i] = (int*)malloc(sizeof(int)*v);
    }

    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    list = (node*)malloc(sizeof(node)*v);

    init_list(list, v);

    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            if(arr[i][j] == 1){
                link_list(list+i, j+1);
            }
        }
    }

    for(i=0; i<v; i++){
        print_list(list+i, i+1);
        printf("\n");
    }
    return 0;
}

void init_list(node* list, int v){
    int i=0;

    for(i=0;i<v;i++){
        (list+i)->next = NULL;
        (list+i)->value = i+1;
    }
}

void link_list(node* list, int v){
    node* new = (node*)malloc(sizeof(node));
    new->next = NULL;
    new->value = v;
    node* now = list;

    while(now->next != NULL){
        now = now->next;
    }
    now->next = new;
}

void print_list(node* list, int i){

    printf("%d: ", i);
    list = list->next;
    while(list != NULL){
        printf("%d ",list->value);
        list = list->next;
    }
}
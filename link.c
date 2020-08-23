#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
    struct node* next;
    int value;
}node;

typedef struct list{
    node* head;
    node* tail;
    int size;
}list;

void init_list(list* mylist);
void push_back(list* mylist, int data);
int get_value(list* mylist, int n);
int count_value(list* mylist, int n);
void clear_list(list* mylist);
void free_node(node* now);


int main() {
    int n, i, value;
    char command[10];
    list mylist;
    init_list(&mylist);
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%s", command);

        if(command[0] == 'p'){
            scanf("%d", &value);
            push_back(&mylist, value);
        }
        else if(command[0] == 'g'){
            scanf("%d", &value);
            printf("%d\n", get_value(&mylist, value));
        }
        else if(command[0] == 's'){
            printf("%d\n",mylist.size);
        }
        else if(command[1] == 'o'){
            scanf("%d", &value);
            printf("%d\n",count_value(&mylist, value));
        }
        else{
            clear_list(&mylist);
        }
    }

    return 0;
}

void init_list(list* mylist){
    mylist->head = (node*)malloc(sizeof(node));
    mylist->head->next = NULL;
    mylist->tail = mylist->head;
    mylist->size = 0;
}

void push_back(list* mylist, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    mylist->tail->next = newNode;
    mylist->tail = newNode;
    mylist->size++;
}

int get_value(list* mylist, int n){
    int i;
    node* now = mylist->head;

    for(i=0;i<n;i++){
        now = now->next;
    }
    return now->next->value;
}

int count_value(list* mylist, int n){
    int i;
    int cnt = 0;
    node* now = mylist->head->next;

    for(i=0;i<mylist->size;i++){
        if(now->value == n){
            cnt++;
        }
        now = now->next;
    }
    return cnt;
}

void clear_list(list* mylist){
    free_node(mylist->head);
    init_list(mylist);
}

void free_node(node* now){
    if(now->next != NULL){
        free_node(now->next);
    }

    free(now);
}
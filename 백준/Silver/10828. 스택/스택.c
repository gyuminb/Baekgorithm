#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node* top = NULL;
int count = 0;

int is_empty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int push(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        return -1;
    }
    
    new_node->value = value;
    new_node->next = top;
    top = new_node;
    
    count++;
    return 0;
}

int pop(){
    if(is_empty()){
        return -1;
    }
    else{
        struct node* temp = top;
        int value = top->value;
        count--;
        top = top->next;
        free(temp);
        return value;
    }
}

int main() {
    int n;
    char input[1024];
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf(" %[^\n]s", input);
        if(strncmp(input, "push", 4) == 0){
            int value = atoi(input+5);
            push(value);
        }
        else if(strcmp(input, "pop") == 0){
            printf("%d\n", pop());
        }
        else if(strcmp(input, "size") == 0){
            printf("%d\n", count);
        }
        else if(strcmp(input, "empty") == 0){
            printf("%d\n", is_empty());
        }
        else if(strcmp(input, "top") == 0){
            if(top != NULL){
                printf("%d\n", top->value);
            }
            else{
                printf("-1\n");
            }
        }
        else{
            printf("Invalid Command!\n");
        }
    }
    return 0;
}
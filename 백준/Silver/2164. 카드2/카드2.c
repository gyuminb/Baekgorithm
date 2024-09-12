#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node* front = NULL;
struct node* back = NULL;
int count = 0;

int is_empty(){
    if(front == NULL){
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
    new_node->next = NULL;
    
    if(is_empty()){
        front = new_node;
        back = new_node;
    }
    else{
        back->next = new_node;
        back = new_node;
    }
    count++;
    return 0;
}

int pop(){
    if(is_empty()){
        return -1;
    }
    else{
        struct node* temp = front;
        int value = front->value;
        count--;
        
        if(front->next != NULL){
            front = front->next;
            free(temp);
            return value;
        }
        else{
            front = front->next;
            free(temp);
            back = NULL;
            return value;
        }
    }
}

int main() {
    int n;
    int temp;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        push(i+1);
    }
    
    while(count != 1){
        pop();
        temp = pop();
        push(temp);
    }
    
    printf("%d\n", front->value);
    return 0;
}
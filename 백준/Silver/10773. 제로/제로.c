#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct stack{
    struct node* top;
};

void init_stack(struct stack* s){
   s->top = NULL;
}

int get_size(struct stack* s){
    struct node* temp = s->top;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int is_empty(struct stack* s){
    if(s->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack* s, int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        return -1;
    }
    
    new_node->value = value;
    new_node->next = s->top;
    s->top = new_node;
    
    return 0;
}

int pop(struct stack* s){
    if(is_empty(s)){
        return -1;
    }
    else{
        struct node* temp = s->top;
        int value = s->top->value;
        s->top = s->top->next;
        free(temp);
        return value;
    }
}

int main() {
    int n, num, result = 0;
    struct stack s;
    init_stack(&s);
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(!num){
            pop(&s);
        }
        else{
            push(&s, num);
        }
    }
    
    while(!is_empty(&s)){
        result += pop(&s);
    }
    
    printf("%d\n", result);
    return 0;
}
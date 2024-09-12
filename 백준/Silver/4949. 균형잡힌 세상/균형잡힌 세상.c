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
    char input[102];

    while(1){
        
        fgets(input, sizeof(input), stdin);
        int len = strlen(input);
        if(strcmp(input, ".\n") == 0){
            break;
        }
        else{
            struct stack s;
            init_stack(&s);
            
            for(int i=0; i<len-1; i++){
                
                if(input[i] == '('){
                    push(&s,'(');
                }
                else if(input[i] == '['){
                    push(&s,'[');
                }
                else if(input[i] == ')'){
                    if(pop(&s) == '('){
                        continue;
                    }
                    else{
                        printf("no\n");
                        break;
                    }
                }
                else if(input[i] == ']'){
                    if(pop(&s) == '['){
                        continue;
                    }
                    else{
                        printf("no\n");
                        break;
                    }
                }
                else if(i == len-2){
                    if(is_empty(&s)){
                        printf("yes\n");
                    }
                    else{
                        printf("no\n");
                    }
                }
                else{
                    continue;
                }
            }
            
        }
    }
    return 0;
}
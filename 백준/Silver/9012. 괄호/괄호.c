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
    int n;
    char input[101];
    
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++){
        scanf("%[^\n]s", input);
        // printf("%s\n", input);
        int len = strlen(input);
        struct stack s;
        init_stack(&s);
        int vps=1;
        
        for(int j=0; j<len; j++){
            
            if(input[j] == '('){
                // printf("push (\t");
                push(&s,'(');
            }
            else if(input[j] == ')'){
                if(pop(&s) == '('){
                    // printf("pop (\t");
                    continue;
                }
                else{
                    // printf("fail\t");
                    vps=0;
                    break;
                }
            }
            else{
                continue;
            }
        }
        
        if(!vps){
            printf("NO\n");
        }
        else{
            if(is_empty(&s)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        getchar();
    }
    return 0;
}
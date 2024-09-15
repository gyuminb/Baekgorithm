#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int id;
    int prio;
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

int push(int id, int prio){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        return -1;
    }
    
    new_node->id = id;
    new_node->prio = prio;
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

struct node* pop(){
    if(is_empty()){
        return NULL;
    }
    else{
        struct node* temp = front;
        count--;
        
        if(front->next != NULL){
            front = front->next;
            return temp;
        }
        else{
            front = front->next;
            back = NULL;
            return temp;
        }
    }
}
int main() {
    int n, N, M, prio;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &N, &M);
        for(int j=0; j<N; j++){
            scanf("%d", &prio);
            push(j, prio);
        }
        
        int result = 1;
        struct node* pos;
        struct node* temp;
        
        while(!is_empty()){
            int check = 1;
            // 더 큰게 있는지 확인
            for(pos=front->next; pos!=NULL; pos=pos->next){
                if(front->prio < pos->prio){
                    temp = pop();
                    push(temp->id, temp->prio);
                    check = 0;
                    break;
                }
            }
            
            if(check){
                temp = pop();
                if(temp->id == M){
                    printf("%d\n", result);
                }
                else{
                    result++;
                }
            }
        }
        
    }
    return 0;
}
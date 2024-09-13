#include <stdio.h>

int main() {
    int start, end;
    int array[1000001];
    scanf("%d %d", &start, &end);
    array[0] = 0;
    array[1] = 0;
    for(int i=2; i<=end; i++){
        array[i] = 1;
    }
    
    for(int i=2; i*i<=end; i++){
        if(array[i]){
            int temp = 2;
            while(i*temp<=end){
                array[i*temp]=0;
                temp++;
            }
        }
    }
    
    for(int i=start; i<=end; i++){
        if(array[i]){
            printf("%d\n", i);
        }
    }
    return 0;
}
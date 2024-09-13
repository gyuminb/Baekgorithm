#include <stdio.h>


int main() {
    int n, num;
    int standard = 10000000;
    int array[20000001];
    
    for(int i=0; i<20000001; i++){
        array[i]=0;
    }
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d ", &num);
        array[num+standard]++;
    }
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d ", &num);
        printf("%d ", array[num+standard]);
    }
    return 0;
}
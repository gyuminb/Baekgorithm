#include <stdio.h>


int main() {
    int n, k;
    int left, count, pos, i;
    int array[1000]={0, };
    int result[1000];
    
    scanf("%d %d", &n, &k);
    left = n;
    pos = k-1;
    i=0;
    count = k-1;
    while(left !=0){
        if(array[pos] == 0){
            count++;
            // printf("pos: %d, count: %d\n", pos+1, count);
            if(count == k){
                array[pos] = -1;
                result[i++] = pos+1;
                
                count = 0;
                left--;
            }
        }
        pos = (pos+1) % n;
    }
    
    printf("<");
    for(i=0; i<n-1; i++){
        printf("%d, ", result[i]);
    }
    printf("%d>\n", result[n-1]);
    return 0;
}
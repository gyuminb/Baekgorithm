#include <stdio.h>

// dp + greedy 
int main() {
    int n;
    int dp[6] ={-1, -1, -1, 1, -1, 1};
    int temp = 6;
    
    scanf("%d", &n);
    
    if(n > 5){
        while(temp <= n){
            if( (dp[(temp-3)%6] != -1) && (dp[(temp-5)%6] != -1)){
                if(dp[(temp-3)%6] <= dp[(temp-5)%6]){
                    dp[temp%6] = dp[(temp-3)%6] + 1; 
                }
                else{
                    dp[temp%6] = dp[(temp-5)%6] + 1;
                }
            }
            else if(dp[(temp-3)%6] != -1){
                dp[temp%6] = dp[(temp-3)%6] + 1; 
            }
            else if(dp[(temp-5)%6] != -1){
                dp[temp%6] = dp[(temp-5)%6] + 1;
            }
            else{
                dp[temp%6] = -1;
            }
            temp++;
            // for(int i=0; i<6; i++){
            //     printf("%d\t", dp[i]);
            // }
            // printf("\t->%d\n", temp-1);
        }
        printf("%d\n", dp[n%6]);
    }
    else{
        printf("%d\n", dp[n]);
    }
    
    return 0;
}
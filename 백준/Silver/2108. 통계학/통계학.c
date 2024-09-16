#include <stdio.h>
int temp[500000];

void merge(int array[], int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    
    while(i<=mid && j<=right){
        if(array[i] <= array[j]){
            temp[k++] = array[i++];    
        }
        else{
            temp[k++] = array[j++];
        }
    }
    
    if(i>mid){
        while(j<=right){
            temp[k++] = array[j++];
        }
    }
    else{
        while(i<=mid){
            temp[k++] = array[i++];
        }
    }
    
    for(k=left; k<=right; k++){
        array[k] = temp[k];
    }
}

void merge_sort(int array[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    int n;
    int sum = 0;
    int array[500000];
    int count[8001] = {0, };
    int mode[8001];
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
        sum += array[i];
        count[array[i]+4000]++;
    }
    
    int max = 0;
    int pos = 0;
    for(int i=0; i<8001; i++){
        if(max < count[i]){
            max = count[i];
        }
    }
    
    for(int i=0; i<8001; i++){
        if(count[i] == max){
            mode[pos++] = i - 4000;
        }
    }
    
    merge_sort(array, 0, n-1);
    
    if(sum >= 0){
        printf("%d\n", (int)((double)sum/n + 0.5));
    }
    else{
        printf("%d\n", (int)((double)sum/n - 0.5));    
    }
    
    printf("%d\n", array[n/2]);
    
    if(pos > 1){
        printf("%d\n", mode[1]);
    }
    else{
        printf("%d\n", mode[0]);
    }
    
    printf("%d\n", array[n-1] - array[0]);
    
    
    return 0;
}
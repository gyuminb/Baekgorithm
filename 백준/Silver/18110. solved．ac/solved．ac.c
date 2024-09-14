#include <stdio.h>
int temp[300000];

void merge(int array[], int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    
    while(i<=mid && j<= right){
        if(array[i]<=array[j]){
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
    int array[300000];
    int omit, avg = 0;
    
    scanf("%d", &n);
    if(n == 0){       
        printf("0\n");
    }
    else{
        omit = (int)((n * 0.15) + 0.5);
        
        for(int i=0; i<n; i++){
            scanf("%d", &array[i]);
        }
        
        merge_sort(array, 0, n-1);
        
        for(int i=omit; i<n-omit; i++){
            avg += array[i];
        }
        
        avg = (int)((double)avg/(n-omit-omit) + 0.5);
        printf("%d\n", avg);
    }
    
    return 0;
}
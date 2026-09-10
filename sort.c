#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int *arr,size_t arr_len){
    //continus swapping selection sort
    size_t ref = 0;
    while(ref < arr_len){
        
        for(int i=ref+1;i<arr_len;i++){
            if(arr[i] < arr[ref]) swap(&arr[i],&arr[ref]);
        }

        ref++;
    }
}

void bubble_sort(int *arr,size_t arr_len){
    for(size_t i=0;i<arr_len;i++){
        for(size_t j=0;j<arr_len-1;j++){
            if(arr[j] > arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
    }
}

void insertion_sort(int *arr,size_t arr_len){
    
}



int main(){

    int arr[5] = {1,4,2,6,3};
    printf("Before sorting\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    bubble_sort(arr,5);
    printf("After sorting\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }printf("\n");


    return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sort_public.c"

int getrand(int max){
    if(max == 0 || max == 1){
        return 0;
    }
    else {
        srand(time(NULL));
        return rand() % max;
    }
}
void quicksort(int *plist,int length, int start, int end){
    if(start <  end && length > 0){
        int pivotIndex = getrand(length) + start;
        swap(plist, pivotIndex, end);
        int k = start;
        int i;
        for(i = start; i < end; i++){
            if(*(plist + i) <=  *(plist + end)){
                swap(plist, i, k);
                k++;
            }
        }
        swap(plist, k, end);

        quicksort(plist, k - start, start, k - 1);
        quicksort(plist, end -k, k + 1, end);
    }
}
void main(){
    int arr[] = {5, 5, 3, 8, 1, 8, 3, 9, 0, 7, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, length, 0, length -1);
    output(arr, length);
}

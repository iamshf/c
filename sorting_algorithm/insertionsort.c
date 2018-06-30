#include <stdio.h>
#include "sort_public.c"

/*普通插入排序算法*/
void insertion_sort(int *plist, int length) {
    int i;
    int j;
    for(i = 1; i < length; i++){
        for(j = i; j > 0; j--){
            if(*(plist + j - 1) > *(plist + j)){
                swap(plist, (j - 1), j);
            }
            else {
                break;
            }
        }
    }
}
/*采用二分查找得插入排序*/
void insertion_sort_v2(int *plist, int length) {
    int i;
    int j;
    int mid;
    int start = 0;
    int end;
    
    for(i = 1; i < length; i++){
        end = i;
        do {
            mid = (end - start > 2 ? ((end - start) % 2 == 0 ? (end - start) / 2 : (end - start -1) / 2) : 1);
            if(*(plist + mid) > *(plist + i)){
                end = mid; 
            }
            else {
                start = mid;
            }
        }
        while(*(plist + mid) <= *(plist + i) && *(plist + mid + 1) >= *(plist + i));

        for(j = i; j > mid; j--) {
            swap(plist, j, (j - 1));
        }
    }
}
void main(){
    int arr[] = {3, 7, 5, 4, 1, 10, 2, 8, 9, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("before sort:");
    output(arr, length);
    insertion_sort(arr, length);

    printf("after sort:");
    output(arr, length);
}

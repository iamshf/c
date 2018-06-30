#include <stdio.h>
#include "sort_public.c"
void bubblesort(int *plist, int length){
    if(length > 1){
        int i;
        for(i = 0; i < length - 1; i++){
            if(*(plist + i) > *(plist + i + 1)){
                swap(plist, i, i + 1);
            }
        }
        bubblesort(plist, length - 1);
    }
}
int main(){
    int a[] = {3, 8, 1, 9, -2, 5, 8, 4, 6, 7};
    bubblesort(a, 10);
    output(a, 10);
    return 1;
}

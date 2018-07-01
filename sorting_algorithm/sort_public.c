void swap(int *plist, int i, int j){
    if(i != j){
        int tmp = *(plist + i);
        *(plist + i) = *(plist + j);
        *(plist + j) = tmp;
    }
}
void output(int *plist, int length){
    int i;
    printf("after sort result:");
    for(i = 0; i < length; i++){
        printf("%d,", *(plist + i));
    }
    printf("\n");
}

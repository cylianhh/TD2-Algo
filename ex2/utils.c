#include "utils.h"

void swap_int(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

bool is_sorted_nondecreasing(int *arr, int n){
    for (int k=0;k<n-1;k++){
        if (arr[k]>arr[k+1]) return 0;
    return 1;
    }
}

void copy_array(int *src, int *dst, int n){
    for (int k=0;k<n;k++) dst[k]=src[k];
}
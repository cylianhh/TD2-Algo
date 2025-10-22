#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target){
    for (int k=0; k<n; k++){
        if (arr[k]==target) return k;
    }
    return -1;
}

int jump_search(int *arr, int n, int target){
    int jump = (int)sqrt(n);
    int prev=0;
    while (prev < n && arr[(jump < n ? jump : n) - 1] < target) { //min entre n et jump
        prev = jump;
        jump += (int)sqrt(n);
        if (prev >= n) return -1;
    } 
    int index = linear_search(arr + prev, (jump < n ? jump : n) - prev, target);
    if (index == -1) return -1;
    return prev + index;  // décaler l'indice du nb de jumps
}

int binary_search(int *arr, int n, int target){
    int inf = 0;
    int sup = n-1;

    while (inf <= sup){
        int moy = (inf+sup)/2;
        if (arr[moy]==target) {
            return moy;
        } 
        else if (arr[moy]<target){
            inf = moy+1;
        }
        else{
            sup = moy-1;
        }
    }
    return -1;
}
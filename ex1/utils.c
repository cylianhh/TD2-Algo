#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n){
    for (int k=0;k<n-1;k++){
        if (arr[k]>=arr[k+1]) return 0;
    return 1;
    }
}
int min_int(int a, int b)
{ if (a<b) return a;
    return b;
}
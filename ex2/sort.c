#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n){
    for (int i=0;i<n-1;i++){
        int min=i;
        for (int k=i+1;k<n;k++){
            if (arr[k]<arr[min]) min=k;
        }
        if (min!=i) swap_int(&arr[i],&arr[min]);
    }
}

void insertion_sort(int *arr, int n){
    for (int k=0;k<n;k++){
        int cle=arr[k];
        int j=k-1;
        while (j>=0 && arr[j]>cle){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=cle;
    }
}

void bubble_sort(int *arr, int n){
    for (int k=n-1;k>0;k--){
        for (int i=0;i<k;i++){
            if (arr[i]>arr[i+1]) swap_int(&arr[i],&arr[i+1]);
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r){
    int i=l;
    int j=m;
    int k=l;
    while (i<m && j<r){
        if (arr[i]<=arr[j]){
            tmp[k]=arr[i];
            i+=1;
        }
        else{
            tmp[k]=arr[j];
            j+=1;
        }
        k+=1;
    }
    while (i<m){
    tmp[k]=arr[i];
    k+=1;
    i+=1;
    }

    while (j<r){
    tmp[k]=arr[j];
    k+=1;
    j+=1;
    }
    copy_array(tmp+l, arr+l, r-l);
}

void mergesort_rec(int *arr, int *tmp, int l, int r){
    if (l >= r-1) return;
    else{
        int m=(r+l)/2;
        mergesort_rec(arr,tmp,l,m);
        mergesort_rec(arr,tmp,m,r);
        merge(arr,tmp,l,m,r);
    }
}

void merge_sort(int *arr, int n){
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r){
    int pivot=arr[r];
    int i=r;
    for (int k=r-1;k>=l;k--){
        if (arr[k]>pivot){
            i-=1;
            swap_int(&arr[i],&arr[k]);
            
        }
    }
    if (i!=r) swap_int(&arr[i], &arr[r]);
    return i;
}

void quick_sort_rec(int *arr, int l, int r){
    if (l<r){
        int p=partition(arr,l,r); 
        quick_sort_rec(arr,l,p-1); 
        quick_sort_rec(arr,p+1,r);
    }
}

void quick_sort(int *arr, int n){
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}
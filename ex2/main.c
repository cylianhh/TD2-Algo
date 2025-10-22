#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"
#define N 10000

int main(){
    
    int *arr = malloc(N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire\n");
        return EXIT_FAILURE;
    }
    
    for (int i =0; i<N; i++) {
        arr[i] =rand()%100; 
    }

    clock_t start = clock();
    merge_sort(arr, N);
    clock_t end = clock();
    
    /*for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n");*/

    double temps_ecoule = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Temps ecoule : %f secondes\n", temps_ecoule);
    int a=is_sorted_nondecreasing(arr, N);
    printf("tableau trie : %i\n",a);

    free(arr);
    return 0;
}

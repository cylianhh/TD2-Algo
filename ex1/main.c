#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"
#define N 100000000

int main(){
    int *arr = malloc(N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = i * 2;  //nb pairs
        };
    
    if ( !is_sorted_nondecreasing(arr, N)) {
        printf("Le tableau n'est pas trie\n");
        return -1;
    }

    int target = 58032412;
    clock_t start = clock(); 
    int index = linear_search(arr, N, target);
    
    if (index != -1)
        printf("trouve à l'indice : %d\n", index);
    else
        printf("non trouve\n");
    
    clock_t end = clock();
    double temps_ecoule = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Temps ecoule : %f secondes\n", temps_ecoule);
    free(arr);
    return 0;
}
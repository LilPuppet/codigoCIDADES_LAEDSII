#ifndef HASH_CPP
#define HASH_CPP

#include "cidade.cpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tamanho do vetor
#define SIZE 1024

// Vetor de ponterios do tipo dataItem
typedef dataItem *hash[SIZE];

int divisao(dataItem *d) {
    return d->key % SIZE;
}

void init(hash &H) {
    for (int i = 0; i < SIZE; i++) {
        H[i] = 0;
    }
}

int inserirNovo(hash H, dataItem d) {
   
    dataItem *copy = (dataItem*)malloc(sizeof(dataItem));
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    *copy = d;
    int resto = divisao(copy);
    novo->data = d;
    novo->prox = 0;
    
    if (H[resto] == 0) {;
        H[resto] = copy;
        return 0;
    }else if(H[resto] != 0){
        novo->prox = H[resto]->inicio;
        H[resto]->inicio = novo;
        return 0;
    } 
    
   return -1;
}



/*
void escrever(hash H){
    for (int i = 0; i < SIZE; i++) {
        printf("P-> %d KEY-> %d\n", i, H[i]->data.key);
    }
}
*/

#endif
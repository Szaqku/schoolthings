/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   new.c
 * Author: szaqk
 *
 * Created on 24 listopada 2018, 22:45
 */

#include <stdio.h>
#include <stdlib.h>

void sortWstawianie(int *tab){
    int n = sizeof(tab)/sizeof(int);
    int min;
    int tmp;
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = 0; j < n-1;j++){
            if(tab[min] > tab[j]){
                min = j;
            }
        }
        if(min != i){
            tmp = tab[i];
            tab[i] = tab[min];
            tab[min] = tmp;
        }
    }
}

void printArray(int tab[]){
    int n = sizeof(tab)/sizeof(int);
    printf("\n");
    for(int i = 0 ; i < n ; i++)
        printf(" %d |",tab[i]);
    printf("\n");
}

int main(int argc, char** argv) {

    int tab[] = {1,5,2,3,4,1,1,1};
    printArray(tab);
    sortWstawianie();
    
    return (EXIT_SUCCESS);
}


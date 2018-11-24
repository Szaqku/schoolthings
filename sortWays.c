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

void sortWstawianie(int *tab, int n){
    int min;
    int tmp;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++){
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

void printArray(int *tab,int n){
    printf("\n");
    for(int i = 0 ; i < n ; i++)
        printf(" %d |",tab[i]);
    printf("\n");
}

int main(void) {

    int tab[] = {1,5,2,3,4,1,1,1};
    int n = sizeof(tab)/sizeof(int);
    printArray(tab,n);
    sortWstawianie(tab,n);
    printArray(tab,n);    
    return (EXIT_SUCCESS);
}


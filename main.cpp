#include "ordenacao.hpp"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

    Ordenacao *x;
    x = new Ordenacao();

    for(int i=0;i<20;i++){
      cout << "hueee  "<< x->vetor[i] << endl;
    }
    //x->bublesort();
    //x->selectionsort();
    //x->insertionSort();
    x->mergeSort();
    for(int i=0;i<20;i++){
      cout << "arrumou:  "<< x->vetor[i] << endl;
    }




};

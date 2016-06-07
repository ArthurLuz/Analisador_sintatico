#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;
//modela classe
class Ordenacao{
  public:
  int x,z;
   int vetor[20];
   int inicio,fim;
  //int meio=10;

  Ordenacao(){
    srand((unsigned int)time(NULL));

    for(int i=0;i<20;i++){
		    vetor[i] = rand()%100+1;
	   }
     inicio=0;
     fim=20;
  };
  //~bubbles(){};

  void bublesort(){
    z=20;
    do{
      for (int i=0;i<20;i++){
        if(i+1<=20){
              if(vetor[i]>vetor[i+1]){
                x=vetor[i+1];
                vetor[i+1]=vetor[i];
                vetor[i]=x;
              }
        }
      }
      z--;
    } while(z!=0);

  };
//________________________________________________________________________________________
  void selectionsort(){
    for (int i=0;i<20;i++){
      z=vetor[i];
      for (x=i+1;x<20;x++){
        if(vetor[x]<z){
          z=vetor[x];
          vetor[x]=vetor[i];
          vetor[i]=z;
        }
      }
      vetor[i]=z;
    }

  };

  //_____________________________________________________________________________________
  void insertionSort() {
        int key;

      for (x = 1; x < 20; x++){
        key = vetor[x];
          for (z = x - 1; (z >= 0) && (vetor[z] > key); z--){
             vetor[z + 1] = vetor[z];
          }
            vetor[z + 1] = key;
      }
  };
//_________________________________________________________________________________________
  void mergeSort() {

  if (fim <= inicio) {
		return;
	}
	int meio = (inicio + fim) / 2;
	meio++;
	//mergeSort();
	int A [meio - inicio + 1];
	int B [fim - meio];
	for (int i = 0; i <= meio - inicio; i++) {
		A[i] = vetor[inicio + i];
	}
	for (int i = 0; i <= fim - meio - 1; i++) {
		B[i] = vetor[meio + 1 + i];
	}
  mergeSort();
	int i = 0;
	int j = 0;
	for (int k = inicio; k <= fim; k++) {
		if (i < meio - inicio + 1 && j < fim - meio) {
			if (A[i] < B[j]) {
				vetor[k] = A[i++];
			} else {
				vetor[k] = B[j++];
			}
		} else if (i < meio - inicio + 1) {
			vetor[k] = A[i++];
		} else if (j < fim - meio) {
			vetor[k] = B[j++];
		}
	}
}



};

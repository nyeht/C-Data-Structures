#include <stdio.h>

void bubbleSort(int* const array, const size_t size);
void swap(int *el1P, int *el2P);

int main(){

    int arr[5] = {3,4,2,5,1};

    bubbleSort(arr, 5);

    for(size_t i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubbleSort(int* const array, const size_t size) {
    for(int pass = 0; pass < size - 1; pass++) {
        for(int k = 0; k < (size - pass - 1); k++) {
            if(array[k] > array[k+1]) {
                swap(&array[k], &array[k+1]);
            }
        }
    }
}

void swap(int *el1P, int *el2P) {
    int temp = *el1P;
    *el1P = *el2P;
    *el2P = temp; 
}
#include <stdio.h>

void selectionSort(int * const array, int size);
void swap(int *el1P, int *el2P);

int main() {

    int arr[5] = {3,4,2,5,1};

    selectionSort(arr, 5);

    for(size_t i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void selectionSort(int * const array, int size){
    int *sm;
    for(int tur = 0; tur < size; tur++) {
        sm = &array[tur];
        for(int i = tur; i < size; i++) {
            if(*sm > array[i]) {
                sm = & array[i];
            }
        }

        swap(sm, &array[tur]);

    }
}

void swap(int *el1P, int *el2P) {
    int temp = *el1P;
    *el1P = *el2P;
    *el2P = temp; 
}
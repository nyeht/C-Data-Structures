#include <stdio.h>

#define MAXSIZE 10
#define STACK_EMPTY 0

void push(char arr[], char item, int *index_last_item, int max_size);
char pop(char arr[], int *index_last_item);
char retrieve(const char arr[], int *index_last_item);
void printStack(const char arr[], int *index_last_item);

int main() {
    
    char arr[MAXSIZE];
    int index_last_item = -1;

    push(arr, 'c', &index_last_item, MAXSIZE);
    push(arr, '2', &index_last_item, MAXSIZE);
    push(arr, '5', &index_last_item, MAXSIZE);
    push(arr, 'd', &index_last_item, MAXSIZE);

    printf("Before pop\n");
    printStack(arr, &index_last_item);

    pop(arr, &index_last_item);
    pop(arr, &index_last_item);

    printf("After pop\n");
    printStack(arr, &index_last_item);

    return 0;
}

void push(char arr[], char item, int *index_last_item, int max_size) {
    if (*index_last_item < max_size - 1) {
        ++(*index_last_item);
        arr[*index_last_item] = item;
    }  
}

char pop(char arr[], int *index_last_item) {
    char item;
    if(*index_last_item >= 0) {
        item = arr[*index_last_item];
        --(*index_last_item);
    } else {
        item = STACK_EMPTY;
    }
    return item;
}

char retrieve(const char arr[], int *index_last_item) {
    char item;
    if(*index_last_item >= 0) {
        item = arr[*index_last_item];
    } else {
        item = STACK_EMPTY;
    }
    return item;
}

void printStack(const char arr[], int *index_last_item) {
    for(int i = *index_last_item; i >= 0; i--) {
        printf("%c\n", arr[i]);
    }
}
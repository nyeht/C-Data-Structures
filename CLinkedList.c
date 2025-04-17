#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
     int userID;
     int itemID;
     float rating;
     struct Node* next;
} Node;

void insertItem(int userID, int itemID, float rating);
void removeItem(int userID, int itemID);
void ratingSpecific(int userID, int itemID);
void averageItems(int itemID);

Node* head = NULL;

int main() {
    char command[10];
    int userID, itemID;
    float rating;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "INSERT") == 0) {
            scanf("%d %d %f", &userID, &itemID, &rating);
            insertItem(userID, itemID, rating);
        } else if (strcmp(command, "REMOVE") == 0) {
            scanf("%d %d", &userID, &itemID);
            removeItem(userID, itemID);
        } else if (strcmp(command, "RATING") == 0) {
            scanf("%d %d", &userID, &itemID);
            ratingSpecific(userID, itemID);
        } else if (strcmp(command, "AVERAGE") == 0) {
            scanf("%d", &itemID);
            averageItems(itemID);
        }
    }

    return 0;
}

void insertItem(int userID, int itemID, float rating) {
    Node* temp = head;
    // If the user already rated the item control it and update that item
    while(temp != NULL) {
        if(temp->userID == userID && temp->itemID == itemID) {
            temp->rating = rating;
            printf("Customer rating (%d, %d) is updated\n", userID, itemID);
            return;
        }
        temp = temp->next;
    }
    // New item add
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->itemID = itemID;
    newNode->rating = rating;
    newNode->userID = userID;
    newNode->next = head;
    head = newNode;
    printf("Customer rating (%d, %d) is added successful\n", userID, itemID);
}

void removeItem(int userID, int itemID) {
    Node* temp = head;
    Node * prev;
    if(temp == NULL) {
        printf("Customer rating (%d, %d) does not exist", userID, itemID);
        return;
    }
    while (temp != NULL) {
        if(temp->userID == userID && temp->itemID == itemID) {
            // node found (prev  temp  temp->next)
            prev->next = temp->next;
            free(temp);
            printf("Customer rating (%d, %d) is removed successful\n", userID, itemID);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Customer rating (%d, %d) does not exist\n", userID, itemID);
    
}

void ratingSpecific(int userID, int itemID) {
    Node* temp = head;

    if(temp == NULL) {
        printf("Customer rating (%d, %d) is: 0\n", userID, itemID);
        return;
    }
   
    while (temp != NULL) {
        if(temp->userID == userID && temp->itemID == itemID) {
            // rating found
            printf("Customer rating (%d, %d) is: %0.1f\n", userID, itemID, temp->rating);
            return;
        }
        temp = temp->next;
    }

    printf("Customer rating (%d, %d) is: 0.0\n", userID, itemID);
}

void averageItems(int itemID) {
    Node* temp = head;
    float sum = 0.0;
    float num = 0.0;
    float avg = 0.0;
   
    while (temp != NULL) {
        if(temp->itemID == itemID) {
            // rating found
            sum += temp->rating;
            num++;
            avg = sum / num;
        }
        temp = temp->next;
    }

    printf("Average rating (%d) is: %0.1f\n", itemID, avg);
}
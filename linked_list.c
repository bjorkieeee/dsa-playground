// TODO
// insertAtIndex(): Insert a new node at any specific index.
// findByValue(): Find the index of a node with a given value.
// reverseList(): Reverse the entire list.
// getLength(): Get the total number of nodes in the list.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* initializeLinkedList(){
    return NULL;
}

struct Node* getLastItemInLinkedList(struct Node* list){
    while (list->next != NULL){
        list = list->next;
    }
    return list;
}

bool isEmpty(struct Node* list){
    if (list == NULL){
        return true;
    } else {
        return false;
    }
}

void push(struct Node** list, int data){ // list is an address of struct Node type
    // We have two parts. If the linked list is NULL, and if it's not NULL
    if (isEmpty(*list)){ // if that address == NULL meaning we have no items yet
        // first item
        *list = (struct Node*)malloc(sizeof(struct Node)); // creating a new address in memory
        (*list)->data = data; // updating the data at that address
        (*list)->next = NULL; // Upsdating the next at that address
    } else {
        // not first item
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        struct Node* lastItem = getLastItemInLinkedList(*list);
        lastItem->next = newNode;
    }
}

void deleteByIndex(struct Node** list, int index){
    // Delete by index, starting with 0 like regular arrays
    // if our item is in the beginning, just delete it, we will point to a new head. We know it's first by checking if index is 0 
    // if our item is last, update previous item to point to NULL. We know it's last by checking if it points to NULL
    // if our item is in the center, update the previous item to point to the next items address. We know it's in the center if the
    // above two conditions don't get hit What if our list == null?
    // What if the index is NULL?
    // don't forget to free the memory
    if (isEmpty(*list)){
        printf("The list is empty, we can't delete something from an empty list.\n");
        return; // don't do anything? there is nothing to delete?
    }
    else if (index == 0){
        struct Node* temp = *list;
        *list = (*list)->next; // we need to ensure our head is pointing to the new head before we free
        free(temp);
        return;
    } 

    struct Node* current = *list;
    struct Node* previous = NULL;
    int count = 0;
    while (count != index && current != NULL){
        if (count == index - 1){
            previous = current;
        }
        count += 1;
        current = current->next;
    }
    if (current == NULL){
        printf("Seems like you've entered an index that is out of bounds and does not exist. Did not delete anything.\n");
    } else if (current->next == NULL){
        // At the end
        free(current);
        previous->next = NULL;
    } else {
        // In the middle
        struct Node* next = current->next;
        previous->next = next;
        free(current);
    }
}

int getDataByIndex(struct Node** list, int index){
    // Index could be out of bounds
    // What if list is null?
    if (isEmpty(*list)){
        printf("Seems like the linked list is empty, so I can't get you any data. Insert some data into your linked list first.\n");
        return -1;
    } 
    int count = 0;
    struct Node* current = *list;
    while (count != index && current != NULL){
        count += 1;
        current = current->next;
    } 
    if (current == NULL){
        printf("Seems like you've entered an index that is out of bounds and does not exist. Returned -1 to indicate that there was an error.\n");
        return -1;
    } else {
        return current->data;
    }
}

void printAllNodes(struct Node** list){\
    int itemNum = 0;
    while ((*list)->next != NULL){
        itemNum += 1;
        printf("Data of item %d: %d\n", itemNum, (*list)->data);
        printf("Address of next item is: %p\n\n", (*list)->next);
        *list = (*list)->next;
    }
    itemNum += 1;
    printf("Addess of item %d: %p\n", itemNum, *list);
    printf("Data of item %d: %d\n", itemNum, (*list)->data);
    printf("Address of next item is: %p\n\n", (*list)->next);
}

    

int main(){
    struct Node* myLinkedList = initializeLinkedList();
    push(&myLinkedList, 100);
    push(&myLinkedList, 200);
    push(&myLinkedList, 300);
    push(&myLinkedList, 400);
    push(&myLinkedList, 500);

    deleteByIndex(&myLinkedList, 1);
    int myData = getDataByIndex(&myLinkedList, 0);
    printf("My data is %d\n", myData);

    printAllNodes(&myLinkedList);

   return 0;
}

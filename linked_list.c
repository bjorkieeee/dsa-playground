// TODO
// Make it so that we tell the user what the length was so they can understand why their index was of
// Clean up comments and code
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

struct Node* getLastItemInLinkedList(struct Node* head){
    struct Node* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    return current;
} 

bool isEmpty(struct Node* head){
    if (head == NULL){
        return true;
    } else {
        return false;
    }
}

int getLength(struct Node** pHead){
    if (isEmpty(*pHead)) {
        return 0;
    } else {
        int count = 0;
        struct Node* current = *pHead;
        while (current->next != NULL){
            count += 1;
            current = current->next;
        }
        count += 1;
        return count;
    }
}

int findByValue(struct Node** pHead, int data){
    // Return -1 if list is empty
    // Return -1 if not found
    // if found return that index
    // We can only return the first instance of that value. So if the value 100 is stored in multiple nodes
    // we will only get the first occurrence
    if (isEmpty(*pHead)){
        printf("The list is empty, we can't find something from an empty list.\n");
        return -1;
    } 

    int count = 0;
    struct Node* current = *pHead;
    while (current != NULL && current->data != data ){
        current = current->next;
        count += 1;
    }
    if (current == NULL){
        return -1;
    }
    return count;
}

void push(struct Node** pHead, int data){ // list is an address of struct Node type
    // We have two parts. If the linked list is NULL, and if it's not NULL
    if (isEmpty(*pHead)){ // if that address == NULL meaning we have no items yet
        // first item
        *pHead = (struct Node*)malloc(sizeof(struct Node)); // creating a new address in memory
        (*pHead)->data = data; // updating the data at that address
        (*pHead)->next = NULL; // Upsdating the next at that address
        return;
    } else {
        // not first item
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        struct Node* lastItem = getLastItemInLinkedList(*pHead);
        lastItem->next = newNode;
        return;
    }
}

void deleteByIndex(struct Node** pHead, int index){
    // Delete by index, starting with 0 like regular arrays
    // if our item is in the beginning, just delete it, we will point to a new head. We know it's first by checking if index is 0 
    // if our item is last, update previous item to point to NULL. We know it's last by checking if it points to NULL
    // if our item is in the center, update the previous item to point to the next items address. We know it's in the center if the
    // above two conditions don't get hit What if our list == null?
    // What if the index is NULL?
    // don't forget to free the memory
    if (isEmpty(*pHead)){
        printf("The list is empty, we can't delete something from an empty list.\n");
        return; // don't do anything? there is nothing to delete?
    }
    else if (index == 0){
        struct Node* temp = *pHead;
        *pHead = (*pHead)->next; // we need to ensure our head is pointing to the new head before we free
        free(temp);
        return;
    } 

    struct Node* current = *pHead;
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
        return;
    } else if (current->next == NULL){
        // At the end
        free(current);
        previous->next = NULL;
        return;
    } else {
        // In the middle
        struct Node* next = current->next;
        previous->next = next;
        free(current);
        return;
    }
}

int getDataByIndex(struct Node** pHead, int index){
    // Index could be out of bounds
    // What if list is null?
    if (isEmpty(*pHead)){
        printf("Seems like the linked list is empty, so I can't get you any data. Insert some data into your linked list first.\n");
        return -1;
    } 
    int count = 0;
    struct Node* current = *pHead;
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

void insertAtIndex(struct Node** pHead, int data, int index){
    // handle if our list is empty
    // handle if our index is out of bounds
    // handle if our index is 0, which means we need to update our head node in the heap. Which means this new head node
    // needs to point to our old head node
    // handle if our index is in the middle, which means our previous needs to point to our new node, and our new node needs to point to next node
    // handle if our index is last, means we can just call the "push" method
    if (isEmpty(*pHead)){
        push(pHead, data);
        return;
    } else if (index == 0){
        struct Node* newNext = *pHead;
        *pHead = (struct Node*)malloc(sizeof(struct Node));
        (*pHead)->data = data;
        (*pHead)->next = newNext;
        return;
    } 
    int count = 0;
    struct Node* current = *pHead;
    struct Node* previous = NULL;
    while (count != index && current->next != NULL && current != NULL){
        if ( count > 0 && count == index - 1){
            previous = current;
        }
        current = current->next;
        count += 1;
    }
    if (index >= getLength(pHead) || index < 0){
        // index out of bound
        printf("Seems like you've entered an index that is out of bounds and does not exist. Can't insert at an index that has no items in it.\n");
        return;
    } else if (current->next == NULL){
        //last item
        push(pHead, data);
        return;
    } else {
        // in the middle
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = current;
        previous->next = newNode;
        return;
    }
}

void reverseList(struct Node** pHead){
    // if list length is greater than 1, reverse, else don't do anything
    // What is a reverse? 
    // We just need our next, to point to our previous
    // When we get to the last item
    // We need to update our original last to be the head item
    // We need to update our original head to point to null
    if (getLength(pHead) > 1){
        //reverse
        int count = 0;
        struct Node* currentNode = *pHead; // point to current node
        struct Node* nextNode = currentNode->next; // Point to next node
        struct Node* tempOriginalNextNode = NULL;
        while (currentNode->next != NULL){ // while not at last item
            // Adjust the nextNode to point to current node
            tempOriginalNextNode = nextNode->next; // save what the next node was initially pointing to 
            nextNode->next = currentNode; // Update next node next to be current node 
            // Handle the first node to behave as if it were the last node
            if (count == 0){
                currentNode->next = NULL;
                currentNode = nextNode;
                nextNode = tempOriginalNextNode; // adjust next node to be the old next node
                count += 1;
            } else if (tempOriginalNextNode == NULL){
                break;
            } else {
                // Update currentNode to be the next node in list
                currentNode = nextNode;
                nextNode = tempOriginalNextNode; // adjust next node to be the old next node
                count += 1;
            }
        }
        // update current to be the new head "nextNode should be last"
        *pHead = nextNode;
    } else {
        // do nothing
        return; 
    }
}

void printAllNodes(struct Node** pHead){\
    int itemNum = 0;
    struct Node* current = *pHead;
    while (current->next != NULL){
        itemNum += 1;
        printf("Address of item %d: %p\n", itemNum, current);
        printf("Data of item %d: %d\n", itemNum, current->data);
        printf("Address of next item is: %p\n\n", current->next);
        current = current->next;
    }
    itemNum += 1;
    printf("Address of item %d: %p\n", itemNum, current);
    printf("Data of item %d: %d\n", itemNum, current->data);
    printf("Address of next item is: %p\n\n", current->next);
}

int main(){
    // Creating linked list
    struct Node* myLinkedList = initializeLinkedList();

    // Adding items 
    push(&myLinkedList, 100);
    push(&myLinkedList, 200);
    push(&myLinkedList, 300);
    push(&myLinkedList, 400);
    push(&myLinkedList, 400);
    push(&myLinkedList, 500);
    push(&myLinkedList, 600);

    // Deleting items
    deleteByIndex(&myLinkedList, 1);

    // Getting data at an index
    int myData = getDataByIndex(&myLinkedList, 0);
    printf("My data is %d\n", myData);

    // Finding the index of a value
    int myValue1 = findByValue(&myLinkedList, 400);
    printf("The index at value 400 is: %d\n", myValue1);

    // Inserting
    insertAtIndex(&myLinkedList, 69, 2);

    // Get length
    int lengthOfLinkedList = getLength(&myLinkedList);
    printf("The length of my linked list is: %d\n", lengthOfLinkedList);

    // Print all current nodes for reference
    printAllNodes(&myLinkedList);
    
    printf("Performing reverse\n");
    reverseList(&myLinkedList);
    
    // Print all current nodes for reference REVERSED
    printAllNodes(&myLinkedList);


    printf("REVERSING back to original\n");
    reverseList(&myLinkedList);
    
    // Print all current nodes for reference REVERSED
    printAllNodes(&myLinkedList);

   return 0;
}

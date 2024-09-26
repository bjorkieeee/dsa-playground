// This is a static stack. So no dynamic stack yet. Maybe in the future
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX_STACK_SIZE = 10;

struct Stack {
    int* data;
    int topIndex;
    int currentSize;
    int maxSize; 
};

struct Stack* initializeStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = (int *)malloc(10 * sizeof(int));
    stack->currentSize = 0;
    stack->topIndex = -1;
    stack->maxSize = 10;
    return stack;
}

void push(struct Stack* stack, int data){
    stack->currentSize += 1;
    if (stack->currentSize <= stack->maxSize){
        stack->topIndex += 1;
        stack->data[stack->topIndex] = data; 
    } else {
        printf("You have reached the stack size limit. Sorry!\n");
    }
}

int pop(struct Stack* stack){
    if (stack->currentSize > 0){
        int topData = stack->data[stack->topIndex];
        stack->currentSize -= 1;
        stack->topIndex -= 1;
        return topData;
    } else {
        printf("Your stack is empty, nothing to pop here!");
        return -1;
    }
}

int peek(struct Stack* stack){
    if (stack->currentSize > 0){
        return stack->data[stack->topIndex];
    } else {
        return -1;
    }
}

bool isEmpty(struct Stack* stack){
    if (stack->currentSize == 0){
        return true;
    } else {
        return false;
    }
}

bool isFull(struct Stack* stack){
    if (stack->currentSize == MAX_STACK_SIZE){
        return true;
    } else {
        return false;
    }
}

int length(struct Stack* stack){
    return stack->currentSize;
}

void printStack(struct Stack* stack){
    printf("Stacks Current Size: %d\n", length(stack));
    printf("Stacks Top Index: %d\n", stack->topIndex);
    for (int i = stack->topIndex; i >= 0; i--){
        printf("\n\nData Value: %d\n", stack->data[i]);
        printf("Pointer/address to top element of array: %p\n\n", &stack->data[i]);
    }
}

int main(){
    struct Stack* myStack = initializeStack();
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    push(myStack, 50);
    push(myStack, 60);
    push(myStack, 70);
    push(myStack, 80);
    push(myStack, 90);
    push(myStack, 100);

    printf("Last Item Popped: %d\n", pop(myStack));
    printf("Last Item Peeking: %d\n", peek(myStack));
    printf("Is this array empty: %s\n", isEmpty(myStack) ? "true" : "false");
    printf("Is this array full: %s\n", isFull(myStack) ? "true" : "false");
    
    printStack(myStack);
}

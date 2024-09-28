#include <stdio.h>

void countdown(int i){
    // Basic recursion example
    printf("%d\n", i);

    if (i <= 0){
        // base case
        return;
    } else {
        // recursive case
        countdown(i - 1);
    }
}

void stackOverflow(int x){
    printf("%d\n", x);
    stackOverflow(x-1);
}

int factorial(int x){
    if (x == 1){
        return 1;
    } else {
        return x * factorial(x - 1);
    }
}

int sumArray(int *data, int length){
    if (length <= 0){
        // base case
        return 0;
    } else {
        // recursive case
        return data[0] + sumArray(data + 1, length-=1);
    }
}

int main(){
    //countdown(21);

    //stackOverflow(50);
    
    //printf("Value: %d\n", factorial(5));
    
    //int testArray[] = {2, 4, 6};
    int testArray[] = {5, 5, 6, 6};
    //int testArray[] = {10};
    //int testArray[] = {};
    int length = sizeof(testArray) / sizeof(testArray[0]);
    printf("Sum of this array is: %d\n", sumArray(testArray, length));
    return 0;
}

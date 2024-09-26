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


int main(){
    //countdown(21);
    //stackOverflow(50);
    printf("Value: %d\n", factorial(5));
    return 0;
}

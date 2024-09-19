#include <stdio.h>



int binarySearch(int targetNum, int array[], int size){
    // must return the position of the target number in the array
    // Currently failing because I went on an infinite loop
    int low = 0;
    int high = size - 1;
    int middle;
                                                           
    while (low <= high){
        middle = high / 2;
        if (array[middle] == targetNum){
            return middle;
        } else if (array[middle] > targetNum){
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return middle;
}

int main(){
    int myNumbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(myNumbers) / sizeof(myNumbers[0]); // sizeof measures the size of the items in bytes
    int answer = binarySearch(3, myNumbers, size);
    printf("%d\n", answer);

    return 0;
}

#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* quickSort(int* data, int length){
    if (length < 2){
        //Base case
        return data;
    } else {
        //recursive case
        int pivotIndex = length - 1; // make this random for best case, but we are making it last for now
        int leftPointer = -1; // this will keep all values less than pivot on the left
        // Left partition
        // starting pointer is the same pointer as our data
        // ending pointer is pivotIndex - 1, which means the leftPartitonLenght is pivotIndex (pivotIndex - 1 + 1)
        // Right partition
        // starting pointer is pivotIndex + 1
        // which means rightPartitionLength is length - leftPartitionLength + 1

        for (int scanPointer = 0; scanPointer < length; scanPointer++){
            if (data[scanPointer] <= data[pivotIndex] && scanPointer - 1 == leftPointer){
                leftPointer += 1;
            } else if (data[scanPointer] <= data[pivotIndex]){
                leftPointer += 1;
                swap(&data[leftPointer], &data[scanPointer]);
            }
       }
        //quick sort both sides here?
        quickSort(data, leftPointer);
        quickSort(&data[leftPointer + 1], length - (leftPointer + 1));
        return data;
    }

}

void printArray(int* data, int length){
    for (int i = 0; i < length; i++){
        printf("Array item number %d: %d\n", i, data[i]);
    }
}

int main(){
    //int myArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    //int myArray[] = {10};
    //int myArray[] = {};
    //int myArray[] = {245, 98, 65, 123, 56, 0, 2, 21, 67, 88, 87, 83};
    int myArray[] = {900, 1000, 1250, 2340, 44, 33, 66, 11, 0, 9};
    int length = sizeof(myArray) / sizeof(myArray[0]);
    printf("Before Sorting\n");
    printArray(myArray, length);
    quickSort(myArray, length);
    printf("\nAfter Sorting\n");
    printArray(myArray, length);

    return 0;
}

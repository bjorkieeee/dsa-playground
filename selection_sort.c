#include <stdio.h>

void selectionSort(int arr[], int size){
    // We don't need to return an array since we are getting a pointer
    // to the array that gets passed in. So the array will be sorted in 
    // memory already.
    int l;
    int r;
    int workingIndex = 0;
    while (workingIndex < size){
        l = workingIndex;
        for (r = workingIndex; r < size; r++){
            if (arr[r] < arr[l]){
                l = r;
            }         
        }
        //swap
        int placeholder;
        placeholder = arr[l];
        arr[l] = arr[workingIndex];
        arr[workingIndex] = placeholder;

        workingIndex += 1;
    }
}
                
int main() {
    //int myArray[10] = {5, 123, 28, 182, 12398, 9, 8, 2, 5, 7};
    //int myArray[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int myArray[10] = {-50, -56, -2, -4, 2, -38, -66, -100, -3, 0};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    selectionSort(myArray, size);
    for (int i = 0; i < size; i++){
        printf("Value %d at address %p\n", myArray[i], &myArray[i]);
    }
    return 0;
}

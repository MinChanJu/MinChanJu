#include <stdio.h>
#include <stdlib.h>

// Declare the prototype of a function
int* insertElement(int* array, int* size, int position, int value);
int* deleteElement(int* array, int* size, int position);
void updateElement(int* array, int size, int position, int newValue);
void printArray(int* array, int size);

// Main Function
int main() {
    // Array Initialization ([1,2,3,4,5])
    int size = 5;
    int* array = (int*)malloc(size*sizeof(int));
    for (int i=0; i < size; i++) {
        array[i] = i+1;
    }

    // Print Initial Array
    printf("\nInitial Array\n");
    printArray(array, size);


    // Array Insertion
    printf("\n\nArray Insertion\n\n");

    // Insert 40 into the falst 0th position of array
    array = insertElement(array, &size, 0, 40);
    printArray(array, size);

    // Insert 34 into the last 6th position of array
    array = insertElement(array, &size, 6, 34);
    printArray(array, size);

    // Insert 17 into the 3th position of array
    array = insertElement(array, &size, 3, 17);
    printArray(array, size);

    // Insert 127 into the 5th position of array
    array = insertElement(array, &size, 5, 127);
    printArray(array, size);

    // Insert 203 into the -1th position, which is the wrong position in the array
    array = insertElement(array, &size, -1, 203);
    printArray(array, size);

    // Insert 75 into the 10th position, which is the wrong position in the array
    array = insertElement(array, &size, 10, 75);
    printArray(array, size);

    // Insert 30 into the 15th position, which is the wrong position in the array
    array = insertElement(array, &size, 15, 30);
    printArray(array, size);


    // Array Deletion
    printf("\n\nArray Deletion\n\n");

    // Delete the first 0th position of array
    array = deleteElement(array, &size, 0);
    printArray(array, size);

    // Delete the last 7th position of array
    array = deleteElement(array, &size, 7);
    printArray(array, size);

    // Delete the 2th position of array
    array = deleteElement(array, &size, 2);
    printArray(array, size);

    // Delete the 5th position of array
    array = deleteElement(array, &size, 5);
    printArray(array, size);

    // Delete the -1th position, which is the wrong position in the array
    array = deleteElement(array, &size, -1);
    printArray(array, size);

    // Delete the 5th position, which is the wrong position in the array
    array = deleteElement(array, &size, 5);
    printArray(array, size);

    // Delete the 10th position, which is the wrong position in the array
    array = deleteElement(array, &size, 10);
    printArray(array, size);


    // Array Update
    printf("\n\nArray Update\n\n");

    // Update the first 0th position of array to 15
    updateElement(array, size, 0, 15);
    printArray(array, size);

    // Update the last 4th position of array to 23
    updateElement(array, size, 4, 23);
    printArray(array, size);

    // Update the 1th position of array to 349
    updateElement(array, size, 1, 349);
    printArray(array, size);

    // Update the 2th position of array to 268
    updateElement(array, size, 2, 268);
    printArray(array, size);

    // Update the -1th position, which is the wrong position in the array, to 6549
    updateElement(array, size, -1, 6549);
    printArray(array, size);

    // Update the 5th position, which is the wrong position in the array, to 62
    updateElement(array, size, 5, 62);
    printArray(array, size);

    // Update the 10th position, which is the wrong position in the array, to 91
    updateElement(array, size, 10, 91);
    printArray(array, size);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}

// Array Insertion
int* insertElement(int* array, int* size, int position, int value) {
    // The insertion function can also be inserted at the end, so determine whether it is between 0 and size
    if (position < 0 || position > *size) {
        printf("The size of array is %d. Therefore, the insertable position is between 0 and %d. Not %d\n", *size, *size, position);
        return array;
    }

    // Declare a new array to insert
    int* newArray = (int*)malloc((*size+1)*sizeof(int));

    // Copy the left side of the position
    for (int i=0; i < position; i++) {
        newArray[i] = array[i];
    }

    // Insert value into array
    newArray[position] = value;

    //Copy the right side of the position including the position
    for (int i=position; i < *size; i++) {
        newArray[i+1] = array[i];
    }

    // Size update
    *size = *size + 1;

    // Free the dynamically allocated memory
    free(array);

    // Print current action
    printf("Insert %d in the %d-position of the array\n", value, position);

    // Return Inserted Array
    return newArray;
}

// Array Deletion
int* deleteElement(int* array, int* size, int position) {
    // The delete function can only delete the correct index, so make sure it is between 0 and size-1
    if (position < 0 || position >= *size) {
        printf("The size of array is %d. Therefore, the deleteable position is between 0 and %d. Not %d\n", *size, *size-1, position);
        return array;
    }

    // Declare a new array to delete
    int* newArray = (int*)malloc((*size-1)*sizeof(int));
    
    // Copy the left side of the position
    for (int i=0; i < position; i++) {
        newArray[i] = array[i];
    }

    // Copy the right side of the position without including the position
    for (int i=position; i < *size-1; i++) {
        newArray[i] = array[i+1];
    }

    // Size update
    *size = *size - 1;

    // Free the dynamically allocated memory
    free(array);

    // Print current action
    printf("Delete the %d-position of an array\n", position);

    // Return Deleted Array
    return newArray;
}

// Array Update
void updateElement(int* array, int size, int position, int newValue) {
    // The update function can only update the exact index, so make sure it is between 0 and size-1
    if (position < 0 || position >= size) {
        printf("The size of array is %d. Therefore, the updateable position is between 0 and %d. Not %d\n", size, size-1, position);
        return;
    }

    // Update to new value in position
    array[position] = newValue;

    // Print current action
    printf("Update the %d-position of the array to the value %d\n", position, newValue);
}

// Array Print (I made it for convenience)
void printArray(int* array, int size) {
    // Print all elements and size of the array
    printf("size: %d \tarray: ", size);
    for (int i=0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("\n\n");
}
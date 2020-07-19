#ifndef DYNAMICARRAYS_H_INCLUDED
#define DYNAMICARRAYS_H_INCLUDED
#define False 0
#define True 1
#include <stdio.h>
#include <stdlib.h>

//Appends or replaces a value to the array depending on the index specified. Dynamically grows the array
void pushInt(int *arr, int index, int value, int *size, int *capacity){
    if(*size > *capacity){
        printf("Reallocating Memory...\n");
        realloc(arr, sizeof(arr) * 2);
        *capacity = sizeof(arr) * 2;
    }
    arr[index] = value;
    *size = *size + 1;
}

//[UNFINISHED] Should delete the value at a specified index and reallocate the memory accordingly
void deleteInt(int *arr, int index, int *arrSize){
    //The idea is to shift each element in the array over so that the value we want deleted is at the end.
    for(int i = index; i < *arrSize - 1; i++){
      arr[i] = arr[i+1];
    }
    //but for whatever reason, when I reallocate the memory so that the array capacity shrinks, it just messes up the value of a random element
    int *tmp = realloc(arr, (*arrSize - 1) * sizeof(int));

    *arrSize = *arrSize - 1;
     arr = tmp;
}

//Checks if a certain value is within a integer array. If it is, then it returns a 1, else it returns a 0
int inIntArr(int *arr, int value, int arrSize){
    int found;
    int index;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] == value){
            found = True;
            index = i;
            break;
        }
    }
    if(found == True){
        return True;
    }else{
        return False;
    }
}

//Prints out all of the values inside of an integer array
void printIntArr(int *arr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        printf("[%d] %d\n", i, arr[i]);
    }
    printf("Break\n\n");
}

//Loop to allow the user to easily populate an array.
void userPopulateIntArr(int *arr, int startIndex, int cycles, int *size, int *capacity, char *prompt){
    int val;
    for(int i = startIndex; i < cycles; i++){
        printf("[%d]%s", i, prompt);
        scanf("%d", &val);
        pushInt(arr, i, val, size, capacity);
    }
}

void help(){
    char functionUses[10][1000] = {
        "pushInt(int *arr, int index, int value, int *size, int *capacity)\n\tAdds a value to at the given index.",
        "deleteInt(int *arr, int index, int *arrSize)\n\tDeletes the value at a certain index. [Unfinished at the moment].",
        "inIntArr(int *arr, int value, int arrSize\n\tReturns a 1 if the value is in the array, returns a 0 if it is not.",
        "printIntArr(int *arr, int arrSize)\n\tPrints the values in an array.",
        "userPopulateIntArr(int *arr, int startIndex, int cycles, int *size, int *capacity, char *prompt)\n\tLoop to allpw the user to populate the array."
    };

    for(int i = 0; i < 5; i++){
        printf("%s", functionUses[i]);
        printf("\n\n");
    }
}


#endif // DYNAMICARRAYS_H_INCLUDED

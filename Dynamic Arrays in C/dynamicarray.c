//
//  dynamicarray.c
//  DynamicArray
//
//  Created by Sara Vargas on 26/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicarray.h"

void push_back(DynamicArray* arr, void* value) ;
void remove_at(DynamicArray* arr, int index);
void vclear(DynamicArray* arr);
int isEmpty(DynamicArray* arr);

void DynamicArrayInit(DynamicArray* arr) {
    arr->capacity = 4;
    arr->data = malloc(arr->capacity*sizeof(void*));
    arr->count = 0;
    arr->push_back= &push_back;
    arr->remove_at = &remove_at;
    arr->clear = &vclear;
    arr->isEmpty = &isEmpty;
}

void push_back(DynamicArray* arr, void* value) {
    if (arr->count == arr->capacity) {
       arr->capacity = arr->capacity * 3;
       void** new_data = malloc(arr->capacity * sizeof(void*));
        memcpy(new_data, arr->data, arr->count * sizeof(void*));
        free(arr->data);
        arr->data = new_data;
    }
    arr->data[arr->count] = value;
    arr->count++;
}

void remove_at(DynamicArray* arr, int index) {
    if (index >= arr->count) {
        return;
    }
    arr->count--;
    arr->data[index] = arr->data[arr->count];
    arr->data[arr->count] = NULL;
    
}

void vclear(DynamicArray* arr) {
    arr->count=0;
    if (arr->capacity > 0) {
        free(arr->data);
        arr->data = NULL;
        arr->capacity = 0;
    }
}


int isEmpty(DynamicArray* arr) {
    return arr->count == 0;
}


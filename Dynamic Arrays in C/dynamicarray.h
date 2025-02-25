//
//  dynamicarray.h
//  DynamicArray
//
//  Created by Sara Vargas on 26/3/23.
//

#ifndef dynamicarray_h
#define dynamicarray_h
#include <stdlib.h>


typedef struct DynamicArray {
    void** data;
    int capacity;
    int count;
    void (*push_back)(struct DynamicArray*, void*);
    void (*remove_at)(struct DynamicArray*, int);
    void (*clear)(struct DynamicArray*);
    int (*isEmpty)(struct DynamicArray*);
} DynamicArray;

void DynamicArrayInit(DynamicArray* arr);

#endif /* dynamicarray_h */

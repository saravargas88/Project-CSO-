//
//  main.c
//  DynamicArray
//
//  Created by Sara Vargas on 26/3/23.
//

#include <stdio.h>
#include "dynamicarray.h"

int main (int argc, char** args){
    
    DynamicArray da;
    DynamicArrayInit(&da);
    printf("Initialization - count: %d, capacity: %d\n", da.count, da.capacity);
    
    //Here you notice that our struct behaves like a class with the help of function pointers
    da.push_back(&da, "Gizem");
    da.push_back(&da, "NYU");
    da.push_back(&da, "CSCI");
    da.push_back(&da, "201");
    da.push_back(&da, "Spring");
    da.push_back(&da, "2023");
    da.push_back(&da, "Project201");
    printf("Step 2 - count: %d, capacity: %d\n", da.count, da.capacity);
    int i;
    for ( i = 0; i < da.count; i ++){
        printf("%s\n", (char*)da.data[i]);
    }
    
    da.remove_at(&da, 2);
    printf("Step 3 - count: %d, capacity: %d\n", da.count, da.capacity);
    printf("\nDynamic Array data:\n\n");
    
    for ( i = 0; i < da.count; i ++){
        printf("%s\n", (char*)da.data[i]);
    }
    da.clear(&da);
    
    if(da.isEmpty){
        printf("The array is empty now\n");
    }
    return 0;
}

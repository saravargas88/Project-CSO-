#include<stdio.h>
#include<stddef.h>

char mymemory[8000];

struct block{
 size_t size;
 int free;
 struct block *next;
};

typedef struct block block;

 block *list=(void*)mymemory;
//(void*) is a typecast that is used to convert a pointer


void initmemory(){
    list->size = sizeof(mymemory) - sizeof(block);
    list->free = 1;
    list->next = NULL;
}


void split(block *slotToBeSplitted, size_t size)
{
    
    block *newBlock = (void*) ((char*) slotToBeSplitted + sizeof(block) + size);
    newBlock->size = slotToBeSplitted->size - size - sizeof(block);
    newBlock->free = 1;
    newBlock->next = slotToBeSplitted->next;
    slotToBeSplitted->size = newBlock->size;
    slotToBeSplitted->free = 0;
    slotToBeSplitted->next= newBlock; //newblock has 7152 and is free
    
}


void *NewMalloc(size_t allocsSize)
{
    block *curr;
    void *result;
    curr = list;
    printf("curr size is: %d\n\n", curr->size);
    //Find a chunk with enough free space
    size_t c= curr->size;
    while (((c < allocsSize)&&curr->free==0) && curr->next != NULL) {
        curr = curr->next;
    }
  
    //Check cases and allocate with/without splitting
    if (curr->size == allocsSize) {
        curr->free = 0;
        result = (void *)(++curr);
        return result;
    }
   
    if (curr->size> (allocsSize + sizeof(block))) {
        printf("Allocate block with splitting for %d bytes", allocsSize);
        split(curr, allocsSize);
        result = (void *)(++curr);
      // list->size=list->size-sizeof(curr);
        return result;
    }
   

    printf("Insufficient memory to allocate %d bytes", allocsSize);
    return NULL;
    
}



void coalesce(){
    struct block *curr;
    curr=list;
    while (curr != NULL && curr->next != NULL&&curr->next->free==1&&curr->free==1) {
                curr->size += curr->next->size + sizeof(block);
                curr->next = curr->next->next;
        
            }
            
        
    }


void NewFree(void* ptr){
  //TO DO
  //Check if the pointer is in a valid range
    if(!ptr){
        printf("Error: Cannot free null pointer\n");
        return;
      }
    block* curr = (block*) ptr-1;
    
    if (curr < list || curr >= (block*)(mymemory + sizeof(mymemory))){
        printf("Pointer outside of valid range\n");
        return;
      }

      // mark the block as free
      curr->free = 1;

      // coalesce free blocks
      coalesce();
  
  

}

int main(){
 
 if(!(list->size))
 {
  initmemory();
  printf("\n\n--Memory Initialization Completed--\n");
  printf("Initial size is: %d\n\n", list->size);
 }


 int *p=(int*)NewMalloc(800);
 printf("\n");
 char *q=(char*)NewMalloc(250*sizeof(char));
 printf("\n");
 int *r=(int*)NewMalloc(1000*sizeof(int));
 printf("\n");
 NewFree(p);
 printf("\n");
 char *w=(char*)NewMalloc(1000);
 printf("\n");
 NewFree(r);
 printf("\n");
 int *k=(int*)NewMalloc(1500*sizeof(int));
 printf("\n");

}


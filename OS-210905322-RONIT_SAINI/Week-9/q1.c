#include <stdlib.h>
#include <stdio.h>
#define ALGO 2

/*Best 1_______________First 2______________Worst 3*/

struct mab
{
    int offset;
    int size;
    int allocated;
    struct mab *next;
    struct mab *prev;
};

typedef struct mab *MabPtr;

MabPtr memChk(MabPtr m, int size)   // check if memory available
{
    MabPtr temp;
    temp = m;
    MabPtr found_mem = NULL;
    while(temp != NULL)
    {
        if(ALGO == 1)
        {
            if (temp->size - temp->allocated >= size)
            {
                if (found_mem == NULL)
                {
                    found_mem = temp;
                }
                else
                {
                    if (found_mem->size - found_mem->allocated >= temp->size - temp->allocated)
                    {
                        found_mem = temp;
                    }
                    
                }
                
            }
            
        }
        else if(ALGO == 2)
        {
            if(temp->size - temp->allocated >= size)
            {
                found_mem = temp;
                break;
            }
        }
        else if (ALGO == 3)
        {
            if(temp->size - temp->allocated >= size)
            {
                if(found_mem==NULL)
                {
                    found_mem=temp;
                }
                else
                {
                    if(found_mem->size - found_mem->allocated <= temp->size-temp->allocated)
                    {
                        found_mem=temp;
                    }
                }
            }
        }
        temp = temp ->next;
    }
    return found_mem;
}


void memAlloc(MabPtr* m, int size) // allocate a memory block
{
    (*m)->allocated += size;
    return;
}


void memFree(MabPtr* m)
{
    (*m)->allocated = 0;
    return;
}
// free memory block

void memMerge(MabPtr* m)// merge two memory blocks
{
    MabPtr curr = *m;
    while ((curr->next != NULL))
    {
        MabPtr next = curr->next;
        if(curr->allocated == 0 && next->allocated == 0)
        {
            curr->size += next->size;
            curr->next = next->next;
            if(next->next != NULL)
            {
                next->next->prev = curr;
            }
        }
        else
        {
            curr = curr->next;
        }
    }
    return;
}

MabPtr memSplit(MabPtr m, int size); // split a memory block

int main()
{
    return 0;
}
#include "abc.h"
#include "misc/extra/extra.h"

// Copy an array of integers
int * Extra_UtilCopyArray(int * pArray, int nSize) {
    int * pNewArray = ABC_ALLOC(int, nSize);
    for (int i = 0; i < nSize; i++) {
        pNewArray[i] = pArray[i];
    }
    return pNewArray;
}

// Additional utility functions for NPN transformations and truth table manipulation

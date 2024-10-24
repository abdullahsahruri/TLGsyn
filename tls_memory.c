#include "abc.h"
#include "base/abc/abc.h"

// Allocate memory for a new cut
Cut_t * CutCreate(int nLeaves, Abc_Obj_t ** pLeaves) {
    Cut_t * pCut = ABC_ALLOC(Cut_t, 1);
    pCut->nLeaves = nLeaves;
    for (int i = 0; i < nLeaves; i++) {
        pCut->pLeaves[i] = pLeaves[i];
    }
    return pCut;
}

// Add a cut to the cut set
void AddCutToSet(Cut_t * pCutSet, Cut_t * pCut) {
    if (pCutSet->nCuts < MAX_CUTS) {
        pCutSet->pCuts[pCutSet->nCuts++] = *pCut;
    }
}

// Free memory for a cut set
void CutSetFree(Cut_t * pCutSet) {
    for (int i = 0; i < pCutSet->nCuts; i++) {
        ABC_FREE(pCutSet->pCuts[i].pWeights);
    }
    ABC_FREE(pCutSet);
}

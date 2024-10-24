#include "abc.h"
#include "base/abc/abc.h"
#include "misc/extra/extra.h"

// Structure to store NPN classes
typedef struct NpnClass_t_ {
    int nVars;
    unsigned uTruth; // Truth table of the function
    int * pWeights;
    int Threshold;
} NpnClass_t;

// Hash table to store NPN representatives and corresponding weights
st__table * NpnHashTable;

// Initialize NPN hash table
void NpnHashTableInit() {
    NpnHashTable = st_init_table(st_ptrcmp, st_ptrhash);
}

// Compute NPN representative and store in the hash table
int ComputeNpnRepresentative(Abc_Obj_t * pObj, NpnClass_t * pNpnClass) {
    unsigned uTruth = Abc_ObjTruth(pObj);
    pNpnClass->uTruth = Extra_TruthCanonNpn(&uTruth, pNpnClass->nVars);

    // Check if the function is already in the hash table
    if (st_lookup(NpnHashTable, (char *)pNpnClass->uTruth, (char **)&pNpnClass)) {
        // If found, return the existing weights and threshold
        return 1;
    }

    // Calculate weights and threshold
    int pWeights[MAX_VARS];
    int Threshold;
    if (ComputeWeights(pObj, pWeights, &Threshold)) {
        pNpnClass->pWeights = Extra_UtilCopyArray(pWeights, pNpnClass->nVars);
        pNpnClass->Threshold = Threshold;

        // Add to hash table
        st_insert(NpnHashTable, (char *)pNpnClass->uTruth, (char *)pNpnClass);
        return 1; // Function is thresholdable
    }
    return 0; // Not thresholdable
}

// Free the hash table
void NpnHashTableFree() {
    st_free_table(NpnHashTable);
}

#include "abc.h"
#include "base/abc/abc.h"

// Function to calculate TLG count
int CalculateTLGCount(Abc_Ntk_t * pNtk) {
    int TLGCount = 0;
    Abc_Obj_t * pObj;
    int i;
    Abc_NtkForEachNode(pNtk, pObj, i) {
        if (Abc_ObjIsThreshold(pObj))
            TLGCount++;
    }
    return TLGCount;
}

// Function to calculate sum of input weights and threshold values
int CalculateSumWeightsThreshold(Abc_Ntk_t * pNtk) {
    int totalSum = 0;
    Abc_Obj_t * pObj;
    int i;
    Abc_NtkForEachNode(pNtk, pObj, i) {
        if (Abc_ObjIsThreshold(pObj))
            totalSum += Abc_ObjWeightSum(pObj);
    }
    return totalSum;
}

// Function to calculate total gate fan-in
int CalculateGateFanIn(Abc_Ntk_t * pNtk) {
    int totalFanIn = 0;
    Abc_Obj_t * pObj;
    int i;
    Abc_NtkForEachNode(pNtk, pObj, i) {
        totalFanIn += Abc_ObjFaninNum(pObj);
    }
    return totalFanIn;
}

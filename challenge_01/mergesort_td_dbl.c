/* 
Implementation of "Merge Sort" using recursion 
    - [ ] Top down (do a state trace)
        - [x] on array of doubles
        - [ ] on string
    - [ ] Bottom Up
        - [ ] on array of doubles
        - [ ] on string
    - [x] answer validation func
*/

#include <stdlib.h>
#include <stdio.h>

void CopyArray(double A[], int iBegin, int iEnd, double B[]){
    for (int k = iBegin; k < iEnd; k++){
        B[k] = A[k];
    }
}

void TD_Merge(double B[], int iBegin, int iMiddle, int iEnd, double A[]){
    int i = iBegin;
    int j = iMiddle;
    for (int k = iBegin; k < iEnd; k++){
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])){
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
    }
}

void TD_SplitMerge(double B[], int iBegin, int iEnd, double A[]){
    if (iEnd - iBegin <= 1){
        return;
    }
    int iMiddle = (iEnd + iBegin) / 2;
    TD_SplitMerge(A, iBegin, iMiddle, B);
    TD_SplitMerge(A, iMiddle, iEnd, B);
    TD_Merge(B, iBegin, iMiddle, iEnd, A);
    //printf("SplitMerge:\n\t%e\n\t%e\n\t%e\n\t%e\n", B[0], B[1], B[2], B[3]);
    
}

int main(int argc, char* argv[argc]) {
    int const num_args = argc - 1;
    double A[num_args], B[num_args];
    
    // printf("num_args = %d\n", num_args);

    for (int i = 1; i <= num_args; ++i) {       //init A[]
        double const n = strtod(argv[i], 0);    //arg -> double
        A[i-1] = n;
    }

    CopyArray(A, 0, num_args, B);
    TD_SplitMerge(A, 0, num_args, B);

    for (int i = 0; i < num_args; ++i) {
        printf("A[%d]: %.2e\n", i, A[i]);
    }

    // Loop over final array, if unsorted print error
    double last = A[0];
    for (int i = 1; i < num_args; ++i) {
        double curr = A[i];
        if (last > curr) {
            printf("Test Failed.");
            break;
        }
        last = curr;
    }

    return EXIT_SUCCESS;
}

/* 
Implementation of "Merge Sort" using recursion 
    - [x] Top down (do a state trace)
        - [ ] on array of doubles
        - [x] on string
    - [ ] Bottom Up
        - [ ] on array of doubles
        - [ ] on string
    - [ ] answer validation func
*/

#include <stdlib.h>
#include <stdio.h>

void CopyArray(char A[], int iBegin, int iEnd, char B[]){
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

int Len(char arr[]){
    int i = 0;
    for(;;){
        if (arr[i] == '\0'){
            break;
        }
        i++;
    }
    return i;
}

int main(int argc, char* argv[argc]) {
    // Get length of input
    int len = 0;
    for (int i = 1; i < argc; ++i) {
        char* arr = argv[i];
        len += sizeof(arr);
        printf("Len: %d\n", len);
    }

    // // Concatenate input to A[]
    // char A[len];
    // for (int i = 1; i < argc; ++i) {
    //     char arr[] = argv[i];
    //     for (int j = 0; j < Len(arr); j++){
    //         A[i+j] = arr[j];
    //     }
    // }
    // char B[len];
    // CopyArray(A, 0, len, B);
    
    // printf("num_args = %d\n", num_args);
    // TD_SplitMerge(A, 0, num_args, B);

    // for (int i = 0; i < argc; ++i) {
    //     printf("A[%d]: %s\n", i, argv[i]);
    // }

    // Loop over final array, if unsorted print error
    // double last = A[0];
    // for (int i = 1; i < num_args; ++i) {
    //     double curr = A[i];
    //     if (last > curr) {
    //         printf("Test Failed.");
    //         break;
    //     }
    //     last = curr;
    // }

    return EXIT_SUCCESS;
}

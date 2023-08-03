#include <stdlib.h>
#include <stdio.h>

void f1(double A[2], double *B){
    A[0] = 34.34;
    A[1] = 12.12;
    *B = 5.0;
}

int main(){
    double E[2] = {6, 9};
    double e = 33.33;
    f1(E, &e);
    printf("Result:\n");
    for (int i = 0; i < 2; ++i) {
        printf("\tE[%d]: %.2e\n", i, E[i]);
    }
    printf("\te: %.2e\n", e);
}
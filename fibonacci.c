/*
 *Resources used:
 *https://www.programiz.com/c-programming/examples/fibonacci-series
 *
 */


#include <stdio.h>
int shell() {
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("\n%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define K 550

int partition(int[], int, int);
void mQuicksort(int[], int, int, int);
void InsertionSort(int[], int, int);

void Quicksort(int A[], int start, int end) {
    if (start < end - 1) {
        int sel = partition(A, start, end);
        Quicksort(A, start, sel);
        Quicksort(A, sel + 1, end);
    }
}

void modified_quicksort(int A[], int start, int end) {
    mQuicksort(A, start, end, K);
    InsertionSort(A, start, end);
}

void mQuicksort(int A[], int start, int end, int treshold) {
    if (end - start > treshold) {
        int sel = partition(A, start, end);
        mQuicksort(A, start, sel, treshold);
        mQuicksort(A, sel + 1, end, treshold);
    }
}

int partition(int A[], int start, int end) {
    int x, i, j, tmp;

    x = A[end - 1];
    i = start;

    for (j = start; j < end - 1; j++) {
        if (A[j] <= x) {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }

    tmp = A[i];
    A[i] = A[end - 1];
    A[end - 1] = tmp;

    return i;
}

void InsertionSort(int A[], int start, int end) {
    int i, j, key;

    for (j = start + 1; j < end; j++) {
        key = A[j];
        for (i = j - 1; i >= start && A[i] > key; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1] = key;
    }
}

int main(void)
{
    int *testcase,*testcase2;
    int len,times;
    srand(time(NULL));
    while(scanf("%d%d",&len,&times)!=EOF)
    {


    testcase = malloc(len*sizeof(int));
    testcase2 = malloc(len*sizeof(int));
    int i,j;
    for(i=0;i<len;i++)
    {
        int x = rand();
        int y = rand();
        if(y%2 == 1)
            {
                testcase[i] = (-1)*x;
                testcase2[i] = (-1)*x;
            }
        else
            {
                testcase[i] = x;
                testcase2[i] = x;
            }
    }
    clock_t t = clock();
    for(i=0;i<times;i++)
    {
        Quicksort(testcase,0,len);

    }
    t = clock()-t;
    unsigned long long int quick = ((unsigned long long int)t);
    printf("Quicksort: %llu\n",quick);

    t = clock();
    for(i=0;i<times;i++)
    {
        modified_quicksort(testcase2,0,len);

    }
    t = clock()-t;
    unsigned long long int mquick = ((unsigned long long int)t);
    printf("modified_quicksort: %llu\n",mquick);
    free(testcase);
    free(testcase2);
}


}

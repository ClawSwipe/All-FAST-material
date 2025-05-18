#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define iterations 50000
#define threadcount 5

int main()
{
    srand(0);
    int chunk_size = iterations / threadcount; // rounding errors need to be avoided
    int tid = 0;
    int i; // this will take valeus 0,1,2,3,4 when each thread is executed
    int a[iterations], b[iterations], c[iterations];
    for (int i = 0; i < iterations; i++)
    {
        a[i] = rand() % 101;
        b[i] = rand() % 101;
        c[i] = rand() % 101;
	
    }
    // the following for loop code will run in each thread
#pragma omp parallel 
    tid = omp_get_thread_num(); // library call to get thread id.
#pragma omp for
    for (i = tid * chunk_size; i < (tid + chunk_size) + chunk_size; i++)
    {
        a[i] = a[i] + (b[i] * c[i]); // Each threads will read and write respective values from arrays.
        printf("%d\t", a[i]);
    }

    return 0;
}

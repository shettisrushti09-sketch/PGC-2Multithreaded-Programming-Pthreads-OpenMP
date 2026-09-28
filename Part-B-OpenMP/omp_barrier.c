#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4

int main() {

    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        printf("Thread %d: Stage 1\n", id);

        #pragma omp barrier

        printf("Thread %d: Stage 2\n", id);
    }

    return 0;
}


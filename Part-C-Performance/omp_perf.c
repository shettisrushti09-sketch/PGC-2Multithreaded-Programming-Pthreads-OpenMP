#include <stdio.h>
#include <omp.h>

#define N 1000000000L

int main()
{
    int num_threads;

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    omp_set_num_threads(num_threads);

    double start_time = omp_get_wtime();

    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (long i = 0; i < N; i++)
    {
        sum += (double)i * 0.000001;
    }

    double end_time = omp_get_wtime();

    printf("Result = %.2f\n", sum);
    printf("Execution time = %.6f seconds\n",
           end_time - start_time);

    return 0;
}

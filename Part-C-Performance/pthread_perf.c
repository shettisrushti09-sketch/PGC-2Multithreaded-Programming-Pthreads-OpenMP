#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 1000000000L

typedef struct {
    long start;
    long end;
    double sum;
} ThreadData;

void *partial_sum(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0.0;

    for (long i = data->start; i < data->end; i++)
    {
        data->sum += (double)i * 0.000001;
    }

    return NULL;
}

double get_time()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main()
{
    int num_threads;

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];
    ThreadData data[num_threads];

    long chunk = N / num_threads;

    double start_time = get_time();

    for (int i = 0; i < num_threads; i++)
    {
        data[i].start = i * chunk;
        data[i].end = (i == num_threads - 1) ? N : (i + 1) * chunk;

        pthread_create(&threads[i], NULL, partial_sum, &data[i]);
    }

    double total_sum = 0.0;

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
        total_sum += data[i].sum;
    }

    double end_time = get_time();

    printf("Result = %.2f\n", total_sum);
    printf("Execution time = %.6f seconds\n",
           end_time - start_time);

    return 0;
}

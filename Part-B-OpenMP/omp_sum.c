#include <stdio.h>
#include <omp.h>

int main() {
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int total_sum = 0;

    #pragma omp parallel for reduction(+:total_sum)
    for (int i = 0; i < 8; i++) {
        total_sum += arr[i];
    }

    printf("Total sum = %d\n", total_sum);

    return 0;
}


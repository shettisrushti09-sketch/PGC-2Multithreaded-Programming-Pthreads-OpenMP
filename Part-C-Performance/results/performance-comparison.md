# Performance Comparison

## 1. Overview

This experiment compares the execution performance of three implementations:

- Sequential
- Pthreads
- OpenMP

The same summation workload was used for all implementations.

## 2. Sequential Baseline

| Implementation | Execution Time (seconds) |
|---|---:|
| Sequential | 5.815207 |

Result:

`499999999500.00`

The sequential execution time is used as the baseline for calculating speedup.

## 3. Pthreads Performance

| Threads | Execution Time (seconds) | Result |
|---:|---:|---:|
| 1 | 5.760953 | 499999999500.00 |
| 2 | 8.462575 | 499999999500.00 |
| 4 | 7.251828 | 499999999500.00 |
| 6 | 4.956253 | 499999999500.00 |
| 16 | 2.507743 | 499999999500.00 |

## 4. OpenMP Performance

| Threads | Execution Time (seconds) | Result |
|---:|---:|---:|
| 1 | 6.274961 | 499999999500.00 |
| 2 | 2.805272 | 499999999500.00 |
| 4 | 1.656242 | 499999999500.00 |
| 6 | 1.784442 | 499999999500.00 |
| 14 | 1.721868 | 499999999500.00 |
| 16 | 1.979686 | 499999999500.00 |

## 5. Pthreads vs OpenMP

| Threads | Pthreads (seconds) | OpenMP (

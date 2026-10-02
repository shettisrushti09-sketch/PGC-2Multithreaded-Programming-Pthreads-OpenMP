# Performance Comparison

## 1. Overview

This experiment compares the execution performance of three implementations of the same summation workload:

- Sequential
- Pthreads
- OpenMP

The objective is to observe how execution time changes when the workload is parallelized using multiple threads.

The same computation and workload size were used for all implementations to make the comparison meaningful.

---

## 2. Sequential Baseline

The sequential implementation executes the complete workload using a single thread.

| Implementation | Execution Time (seconds) |
S|---|---:|
| Sequential | 5.815207 |

Result:

```text
499999999500.00

The sequential execution time of **5.815207 seconds** is used as the baseline for calculating speedup.

---

## 3. Pthreads Performance

The Pthreads implementation divides the workload among multiple POSIX threads.

| Threads | Execution Time (seconds) | Result |
|---:|---:|---:|
| 1 | 5.760953 | 499999999500.00 |
| 2 | 8.462575 | 499999999500.00 |
| 4 | 7.251828 | 499999999500.00 |
| 6 | 4.956253 | 499999999500.00 |
| 16 | 2.507743 | 499999999500.00 |

### Observation

The execution time does not decrease continuously with every increase in thread count.

For example, the 2-thread and 4-thread executions were slower than the sequential execution. This can occur because of thread creation overhead, scheduling overhead, CPU resource limitations, and system load.

With 16 threads, the execution time decreased substantially to **2.507743 seconds**.

---

## 4. OpenMP Performance

The OpenMP implementation uses the OpenMP runtime to distribute loop iterations among multiple threads.

| Threads | Execution Time (seconds) | Result |
|---:|---:|---:|
| 1 | 6.274961 | 499999999500.00 |
| 2 | 2.805272 | 499999999500.00 |
| 4 | 1.656242 | 499999999500.00 |
| 6 | 1.784442 | 499999999500.00 |
| 14 | 1.721868 | 499999999500.00 |
| 16 | 1.979686 | 499999999500.00 |

### Observation

OpenMP shows a significant reduction in execution time when multiple threads are used.

The lowest measured execution time in this set was **1.656242 seconds with 4 threads**.

Increasing the number of threads beyond this did not always improve performance. This demonstrates that adding more threads does not necessarily produce proportional speedup because of hardware limitations, scheduling overhead, memory access, and other system factors.

---

## 5. Pthreads vs OpenMP

The common thread counts measured for both implementations are compared below.

| Threads | Pthreads (seconds) | OpenMP (seconds) |
|---:|---:|---:|
| 1 | 5.760953 | 6.274961 |
| 2 | 8.462575 | 2.805272 |
| 4 | 7.251828 | 1.656242 |
| 6 | 4.956253 | 1.784442 |
| 16 | 2.507743 | 1.979686 |

### Observation

For the measured runs, OpenMP had lower execution times than Pthreads at the common thread counts.

Pthreads provides explicit control over thread creation, workload distribution, and synchronization. OpenMP provides compiler-supported parallelization and runtime management, which makes parallel loop programming simpler.

The measured values are specific to this system and can vary depending on CPU load, available cores, scheduling, and other system conditions.

---

## 6. Speedup

Speedup measures how much faster a parallel implementation is compared with the sequential baseline.

The formula is:

```text
Speedup = Sequential Execution Time / Parallel Execution Time





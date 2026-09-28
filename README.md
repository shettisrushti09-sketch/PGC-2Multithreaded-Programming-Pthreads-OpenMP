# Multithreaded Programming Using Pthreads and OpenMP

This repository contains the implementation of a multithreaded programming experiment using **Pthreads** and **OpenMP**.

The experiment covers thread creation, parallel computation, race conditions, synchronization, barriers, and performance analysis.

## Experiment Structure

### Part A – Pthreads

The following programs were implemented using POSIX Threads (Pthreads):

- `thread1.c` – Basic thread creation
- `thread2.c` – Multiple thread creation
- `thread_sum.c` – Parallel sum using threads
- `race.c` – Demonstration of race condition
- `mutex.c` – Race condition controlled using mutex synchronization

### Part B – OpenMP

The following programs were implemented using OpenMP:

- `omp1.c` – Basic OpenMP parallel execution
- `omp_sum.c` – Parallel sum using OpenMP
- `omp_race.c` – Race condition demonstration
- `omp_critical.c` – Critical section synchronization
- `omp_barrier.c` – Barrier synchronization

### Part C – Performance Analysis

Performance was measured using:

- Sequential execution
- Pthreads
- OpenMP

The performance analysis includes:

- Execution time
- Speedup
- Efficiency
- Pthreads vs OpenMP comparison
- Performance graph

Detailed measurements are available in:

`Part-C-Performance/results/performance-comparison.md`

The graph is available in:

`Part-C-Performance/results/performance-graph.png`

## Repository Structure

```text
PGC-2Multithreaded-Programming-Pthreads-OpenMP/
│
├── README.md
├── .gitignore
│
├── Part-A-Pthreads/
│   ├── thread1.c
│   ├── thread2.c
│   ├── thread_sum.c
│   ├── race.c
│   └── mutex.c
│
├── Part-B-OpenMP/
│   ├── omp1.c
│   ├── omp_sum.c
│   ├── omp_race.c
│   ├── omp_critical.c
│   └── omp_barrier.c
│
├── Part-C-Performance/
│   ├── sequential.c
│   ├── pthread_perf.c
│   ├── omp_perf.c
│   └── results/
│       ├── performance-comparison.md
│       └── performance-graph.png
│
└── screenshots/
    ├── Pthreads/
    ├── OpenMP/
    └── Performance/

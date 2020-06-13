#include <stdio.h>
#include <assert.h>
#include <string.h>

#ifndef QUEUE_H
    #include "queue.h"
#endif

#ifndef ALGORITHM_H
    #include "algorithm.h"
#endif

#ifndef BASELINE_H
    #include "baseline.h"
#endif

#ifndef BASELINE_X2_H
    #include "baseline_x2.h"
#endif

typedef struct queue queue;
typedef struct algorithm_ops algorithm_ops;

int main(){

    // Initialize queue of algorithms.
    queue algorithms;
    init(&algorithms);

    // Add 'baseline' into list of all algorithms.
    register_algorithm(&algorithms, &baseline_ops);

    // Check whether it was inserted correctly.
    print_algorithms(&algorithms);

    // Set 'baseline' as the current algorithm.
    algorithm_ops* alg = get_algorithm_ops(&algorithms, "baseline");
    assert(strcmp(alg -> name, "baseline") == 0);

    printf("Returned from 'on_recv()' of baseline: %d\n", alg -> on_recv());

    // Add 'baseline_x2' into list of all algorithms.
    register_algorithm(&algorithms, &baseline_x2_ops);

    // Check whether it was inserted correctly.
    print_algorithms(&algorithms);

    // Set 'baseline_x2' as the current algorithm.
    alg = get_algorithm_ops(&algorithms, "baseline_x2");
    assert(strcmp(alg -> name, "baseline_x2") == 0);

    printf("Returned from 'on_recv()' of baseline_x2: %d\n", alg -> on_recv());

    // Deregister 'baseline'.
    deregister_algorithm(&algorithms, "baseline");

    // Check whether it was deleted correctly.
    print_algorithms(&algorithms);
}
#ifndef ALGORITHM_H
    #include "algorithm.h"
#endif

#ifndef BASELINE_H
    #include "baseline.h"
#endif

void baseline_init(){

}

int baseline_on_recv(){
    return 1;
}

void baseline_reset(){

}

void baseline_teardown(){

}

struct algorithm_ops baseline_ops = {
    .name = "baseline",
    .init = baseline_init,
    .on_recv = baseline_on_recv,
    .reset = baseline_reset,
    .teardown = baseline_teardown,
};

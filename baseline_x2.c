#ifndef ALGORITHM_H
    #include "algorithm.h"
#endif

#ifndef BASELINE_X2_H
    #include "baseline_x2.h"
#endif

void baseline_x2_init(){

}

int baseline_x2_on_recv(){
    return 2;
}

void baseline_x2_reset(){

}

void baseline_x2_teardown(){

}

struct algorithm_ops baseline_x2_ops = {
    .name = "baseline_x2",
    .init = baseline_x2_init,
    .on_recv = baseline_x2_on_recv,
    .reset = baseline_x2_reset,
    .teardown = baseline_x2_teardown,
};

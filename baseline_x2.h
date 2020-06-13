#define BASELINE_X2_H

void baseline_x2_init();
int baseline_x2_on_recv();
void baseline_x2_reset();
void baseline_x2_teardown();

extern struct algorithm_ops baseline_x2_ops;

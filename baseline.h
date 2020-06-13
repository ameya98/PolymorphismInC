#define BASELINE_H

void baseline_init();
int baseline_on_recv();
void baseline_reset();
void baseline_teardown();

extern struct algorithm_ops baseline_ops;

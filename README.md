# Runtime Polymorphism in C

## Description 
An example of how to implement runtime polymorphism in C via function-pointers. This is basically how the Linux kernel does it!

* *algorithm.h* defines the struct *algorithm_ops* that contains function-pointers. Algorithms instantiate *algorithm_ops* with pointers to their own definitions of these functions.
```C
struct algorithm_ops {
	/* Initialize private data. */
	void (*init)();
    /* Called when a new packet of data is received. */
	int (*on_recv)();
    /* Reset state. */
	void (*reset)();
	/* Cleanup private data. */
	void (*teardown)();

	/* Name of the algorithm. */
	char name[ALG_NAME_MAXCHAR];
};
```
* *baseline.\** and *baseline_x2.\** are two different algorithms that implement the functions. For example, in *baseline.c*, you will find an instance of *algorithm_ops* as:
```C
struct algorithm_ops baseline_ops = {
    .name = "baseline",
    .init = baseline_init,
    .on_recv = baseline_on_recv,
    .reset = baseline_reset,
    .teardown = baseline_teardown,
};
```
* *queue.c* defines a queue to contain all the algorithms' *algorithm_ops* structs.
* *tester.c* registers *baseline* and *baseline_x2*, and checks whether their *on_recv()* functions are called exactly as defined. Then, it deregisters *baseline*.

## Running the Code
Build and run with:
```bash
make run
```

Compile (but don't execute) with:
```bash
make build
```

Clean output files with:
```
make clean
```

## Expected Output
On `make run`:
```
In queue:
- Algorithm: baseline
Returned from 'on_recv()' of baseline: 1
In queue:
- Algorithm: baseline
- Algorithm: baseline_x2
Returned from 'on_recv()' of baseline_x2: 2
In queue:
- Algorithm: baseline_x2
```
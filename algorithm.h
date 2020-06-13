#define ALGORITHM_H
#define ALG_NAME_MAXCHAR 20

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
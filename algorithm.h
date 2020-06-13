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

	char name[ALG_NAME_MAXCHAR];
};
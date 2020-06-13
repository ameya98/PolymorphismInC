#define QUEUE_H
struct node {
    struct node* next;
    struct node* prev;
    struct algorithm_ops* ops_ptr;
};

struct queue {
    int size;
    struct node* start;
};

typedef struct queue queue;
typedef struct node node;
typedef struct algorithm_ops algorithm_ops;

void init(queue* q);
void register_algorithm(queue* q, algorithm_ops* ops_ptr);
void deregister_algorithm(queue* q, char* alg_name);
node* search(queue* q, char* alg_name);
algorithm_ops* get_algorithm_ops(queue* q, char* alg_name);
void print_algorithms(queue* q);
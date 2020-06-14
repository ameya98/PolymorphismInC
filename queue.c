// Queue containing pointers to algorithm_ops for different algorithms.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "algorithm.h"
#include "queue.h"

// We insert at the back of the queue, and start searching for deletion from the front, like a sliding window.
// This is optimal in terms of traversal when packets arrive in-order.

// Initialize queue. We create a sentinel node for the start.
void init(queue* q){
    node* sentinel_entry = malloc(sizeof(node));
    sentinel_entry -> ops_ptr = malloc(sizeof(algorithm_ops));
    strncpy(sentinel_entry -> ops_ptr -> name, "__sentinel__", ALG_NAME_MAXCHAR);
    sentinel_entry -> next = sentinel_entry;
    sentinel_entry -> prev = sentinel_entry;

    q -> start = sentinel_entry;
    q -> size = 0;
}

// Create an entry for a new algorithm_ops node at the end of the queue.
void register_algorithm(queue* q, algorithm_ops* ops_ptr){

    // If we already have this algorithm in our queue, don't insert!
    node* curr = search(q, ops_ptr -> name);
    if(curr != NULL){
        printf("Algorithm already registered!");
        return;
    }
    
    // Allocate space for new algorithm.
    node* entry = malloc(sizeof(node));
    
    // Node at the back can be accessed using the 'prev' pointer of the start.
    node* back = q -> start -> prev;

    // Adjust outgoing to new node.
    entry -> next = q -> start;
    entry -> prev = back;

    // Adjust incoming to new node.
    back -> next = entry;
    q -> start -> prev = entry;

    // Fill in data.    
    entry -> ops_ptr = ops_ptr;

    q -> size += 1;
}

// Delete the entry for a a given algorithm. As mentioned above, we start searching from the start of the queue.
void deregister_algorithm(queue* q, char* alg_name){

    node* curr = search(q, alg_name);
    if(curr == NULL){
        printf("Algorithm not registered!");
        return;
    }

    while(curr != q -> start){
        if (!strncmp(curr -> ops_ptr -> name, alg_name, ALG_NAME_MAXCHAR)) break;
        curr = curr -> next;
    }

    if(curr == q -> start) return;

    // Adjust pointers.
    node* prev = curr -> prev;
    node* next = curr -> next;

    prev -> next = next;
    next -> prev = prev;

    // Adjust size.
    q -> size -= 1;

    // Free memory.
    free(curr);
}

// Returns the corresponding node pointer for an algorithm.
node* search(queue* q, char* alg_name){
    node* curr = q -> start -> next;
    while(curr != q -> start){
        if (!strncmp(curr -> ops_ptr -> name, alg_name, ALG_NAME_MAXCHAR)) return curr;
        curr = curr -> next;
    }
    return NULL;
}

// Returns the corresponding algorithm_ops pointer for an algorithm.
algorithm_ops* get_algorithm_ops(queue* q, char* alg_name){
    node* curr = search(q, alg_name);
    if(curr != NULL) return curr -> ops_ptr;
    return NULL;
}


// Print a representation of the queue.
void print_algorithms(queue* q){
    node* curr = q -> start -> next;
    printf("In queue:\n");
    while(curr != q -> start){
        printf("- Algorithm: %s\n", curr -> ops_ptr -> name);
        curr = curr -> next;
    }
}
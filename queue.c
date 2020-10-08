#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node {
  struct node *next;
  void* element;
} node_t;

typedef struct queue_t {
  node_t* front;
  node_t* back;
} queueStruct_t;

static node_t *make_node(node_t *next, void *element) {
  node_t *new;
  if (!(new = (node_t*)malloc(sizeof(node_t)))) {
    printf("Malloc failure\n");
    return NULL;
  }
  new->next = next;
  new->element = element;
  return new;
}

/* put element at the end of the queue
 * returns 0 is successful; nonzero otherwise 
 */
int32_t qput(queue_t *qp, void *elementp) {
  //make node type
  node_t *qn = make_node(NULL, elementp);
	if (qn == NULL) {
	  return 1; //return 1 if malloc fails
	}
	//case 1: empty queue
	if (qp->front == NULL){
	  (queueStruct_t*)qp->front = qn;
	  (queueStruct_t*)qp->back = qn;
	  return 0;
	}
	//case 2: nonempty queue
	else {
	  qp->back->next = qn;
	  qp->back = qn;
	  return 0;
	}
	return 1;
}

/* get the first element from queue, removing it from the queue */
void* qget(queue_t *qp) {
  //case 1: empty queue
  if (qp->front == NULL) {
	  return NULL;
	}
	//case 2: nonempty queue
	else {
	  node_t* fp = qp->front;
	  qp->front = qp->front->next;
	  return fp->element;
	}
}

void qconcat (queue_t *q1p, queue_t *q2p) {
  if (q1p != NULL && q2p != NULL) {
    while (q2p != NULL) {
       if(qput(q1p, (node_t*)qget(q2p)) != 0) {//removes first element from q2p and puts it at the end of q1p, fails if put is non-zero
	printf("Concatenation failed.\n");
	return;
       }
    }
  }
}

/*void* qremove(queue_t *qp, bool (*searchfn)(void* elementp, const void* keyp), const void* skeyp) {
  node_t* c;
  for(c=qp->front; c != NULL; c=c->next) { //iterate through the queue //TODO: qp is a queue, not a queueStruct: no front?
    if ((*searchfn)(c, skeyp) == TRUE) { //if the boolean is satisfied with the given key
      return (void*)c;
    }
  }
  return NULL;
  }*/

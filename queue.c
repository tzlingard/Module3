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

node_t *make_node(node_t *next, void *element) {
  node_t *new;
  if (!(new = (node_t*)malloc(sizeof(node_t)))) {
    printf("Malloc failure\n");
    return NULL;
  }
  new->next = next;
  new->element = element;
  return new;
}

/*create a queue function*/
struct queue_t* gopen(void){
  /*define a pointer for this queue*/
  queueStruct_t* head;
  /*if there is a problem with allocating memory*/
  if(!(head = (queue_t*)malloc(sizeof(queueStruct_t)))){
    /*throw an error*/
    printf("[Error: malloc failed allocating person]\n");
    return NULL;
  }
  return (queue_t*)head;
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
  if (((queueStruct_t*)qp)->front == NULL){
    ((queueStruct_t*)qp)->front = qn;
    ((queueStruct_t*)qp)->back = qn;
    return 0;
  }
  //case 2: nonempty queue
  else {
    ((queueStruct_t*)qp)->back->next = qn;
    ((queueStruct_t*)qp)->back = qn;
    return 0;
  }
  return 1;
}

/* get the first element from queue, removing it from the queue */
void* qget(queue_t *qp) {
  //case 1: empty queue
  if (((queueStruct_t*)qp)->front == NULL) {
    return NULL;
  }
  //case 2: nonempty queue
  else {
    node_t* fp =((queueStruct_t*)qp)->front;
    ((queueStruct_t*)qp)->front = ((queueStruct_t*)qp)->front->next;
    return (void*)(fp->element);
  }
}

/*apply a function to all the elements of the queue*/
void qapply(queue_t *qp, void (*fn)(void* elementp)){
  node_t* c;
  for(c=((queueStruct_t*)qp)->front; c!=NULL; c=c->next){
    (*fn)((queueStruct_t*)qp);
  }
}

void qconcat (queue_t *q1p, queue_t *q2p) {
  if ((queueStruct_t*)q1p != NULL && (queueStruct_t*)q2p != NULL) {
    while ((queueStruct_t*)q2p != NULL) {
      if(qput((queueStruct_t*)q1p, (node_t*)qget((queueStruct_t*)q2p)) != 0) {//removes first element from q2p and puts it at the end of q1p, fails if put is non-zero
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

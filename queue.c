<<<<<<< HEAD
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
=======
/* queue.c --- 
 * 
 * 
 * Author: Ariel E. Attias
 * Created: Tue Oct  6 15:44:58 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include "queue.h"


typedef struct node {
  struct node *next;
  void*  element;
} node_t;

typedef struct {
  node_t* front;
  node_t* back;
} queue_t;


node_t *make_node(node_t *next, void *element) {
>>>>>>> cfeafc1768a89d5eec42ea1bec4046ad18c1dda6
  node_t *new;
  if (!(new = (node_t*)malloc(sizeof(node_t)))) {
    printf("Malloc failure\n");
    return NULL;
  }
  new->next = next;
  new->element = element;
  return new;
}

<<<<<<< HEAD
=======
/*create a queue function*/
struct queue_t* gopen(void){
	/*define a pointer for this queue*/
	queue_t* head;
	/*if there is a problem with allocating memory*/
	if(!(head = (queue_t*)malloc(sizeof(queue_t)))){
		/*throw an error*/
		printf("[Error: malloc failed allocating person]\n");
		return NULL;
	}
 	return head;
}


>>>>>>> cfeafc1768a89d5eec42ea1bec4046ad18c1dda6
/* put element at the end of the queue
 * returns 0 is successful; nonzero otherwise 
 */
int32_t qput(queue_t *qp, void *elementp) {
<<<<<<< HEAD
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
=======
	//make node type
	node_t *qn = make_node(NULL, elementp);
	if (qn == NULL) {
		return 1; //return 1 if malloc fails
	}
	//case 1: empty queue
	if (qp->front == NULL){
		qp->front = qn;
		qp->back = qn;
		return 0;
	}
	//case 2: nonempty queue
	else {
		qp->back->next = qn;
		qp->back = qn;
		return 0;
>>>>>>> cfeafc1768a89d5eec42ea1bec4046ad18c1dda6
	}
	return 1;
}

/* get the first element from queue, removing it from the queue */
void* qget(queue_t *qp) {
<<<<<<< HEAD
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
=======
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


/*apply a function to all the elements of the queue*/
void qapply(queue_t *qp, void (*fn)(void* elementp)){
	for(qp=front; qp!=NULL;qp=qp->next){
		(*fn)(qp);
	}
}
>>>>>>> cfeafc1768a89d5eec42ea1bec4046ad18c1dda6

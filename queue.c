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
	queue_t* head;
	/*if there is a problem with allocating memory*/
	if(!(head = (queue_t*)malloc(sizeof(queue_t)))){
		/*throw an error*/
		printf("[Error: malloc failed allocating person]\n");
		return NULL;
	}
 	return head;
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
		qp->front = qn;
		qp->back = qn;
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


/*apply a function to all the elements of the queue*/
void qapply(queue_t *qp, void (*fn)(void* elementp)){
	for(qp=front; qp!=NULL;qp=qp->next){
		(*fn)(qp);
	}
}

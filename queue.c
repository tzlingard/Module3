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
typedef void queue_t;

#create a queue function
struct queue_t* gopen(void){
	#define a pointer for this queue
	queue_t* head;
	#if there is a problem with allocating memory
	if(!(head = (queue_t*)malloc(sizeof(queue_t)))){
		#throw an error
		printf("[Error: malloc failed allocating person]\n");
		return Null;
	}
	return head;
}

#apply a function to all the elements of the queue
void qapply(queue_t *qp, void (*fn)(void* elementp)){
	for(qp=front; qp!=NULL;qp=qp->next){
		(*fn)(qp);
	}
}

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
static int SIZE=10;
typedef void queue_t;


struct queue_t* gopen(void){
	queue_t* head;

	if(!(head = (queue_t*)malloc(sizeof(queue_t)))){
		printf("[Error: malloc failed allocating person]\n");
		return Null
	}
	return head;
}

void qapply(queue_t *qp, void (*fn)(void* elementp)){
	for(qp=front; qp!=NULL;qp=qp->next){
		(*fn)(qp);
	}

}

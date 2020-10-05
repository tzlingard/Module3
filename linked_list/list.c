#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "list.h"

static car_t *front = NULL;

/* puts a car at the front of the list */
int32_t lput(car_t *cp) {
  cp->next = front;
  front = cp;
  return 0;
}

/* removes and returns the first car in the list */
car_t *lget() {
  if (front == NULL) {
    return NULL; //returns NULL if list is empty
  }
  else {
    car_t *first = front;
    front = front->next;
    return first;
  }
}

/* applies a function to every car in the list */
void lapply(void (*fn)(car_t*)) {
  car_t *c;
  for (c=front; c!=NULL; c=c->next) {
    (*fn)(c);
  }
}

/* removes every car with the specified plate */
car_t *lremove(char *platep) {
  car_t *c;
  car_t *r = NULL;
  if (!strcmp(front->plate, platep)) {
    r = lget();
  }
  else {
    for (c=front; c != NULL; c=c->next) {
      if (!strcmp(c->next->plate, platep)) {
	c->next = c->next->next;
	r = c->next;
      }
    }
  }
  return r;
}

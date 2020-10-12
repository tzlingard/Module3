#include <stdio.h>
#include "queue.h"
#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>


#define MAXREG 10

/* the representation of a car */
typedef struct car {
	struct car *next;
	char plate[MAXREG];
	double price;
	int year;
} car_t;

 
car_t *make_car(char plate[], double price, int year) {
  car_t *new;
  if (!(new = (car_t*)malloc(sizeof(car_t)))) {
    printf("Malloc failure\n");
    return NULL;
  }
  strcpy(new->plate, plate);
  new->price = price;
  new->year = year;
  new->next = NULL;
  return new;
}

void print_car(void *c) {
	car_t* car = (car_t*)c;
  if (car != NULL) {
    printf("Plate: %s\n",car->plate);
    printf("Price: %lf\n", car->price);
    printf("Year: %d\n", car->year);
  }
  else {
    printf("Nothing to print.\n");
  }
	printf("\n");
}

bool platecheck(void* c, const void* p){
	car_t *car = (car_t*)c;
	char *plate = (char*)p;
	return (!strcmp(car->plate, plate));
}

car_t *front = NULL;

int main(void) {
  
  car_t *c1 = make_car("123456", 9999.99, 2014);
  car_t *c2 = make_car("Darty1", 120000, 2019);
  car_t *c3 = make_car("SUNGOD", 80080.42, 2020);
  car_t *c4 = make_car("DARTXC", 1769.99, 1769);
	car_t *c5 = make_car("CS5050", 5050.50, 1950);
	car_t *c6 = make_car("ENGS50", 5050.50, 1950);



	
	printf("Test 1: Open a new hashtable\n");
	hashtable_t *h1 = hopen(10);
	printf("\n\n");
	
	printf("Test 2 : Put to queue (Adds 6 cars)\n");
	//hput(h1,(void*)c1, (char*)(c1->plate), sizeof((char*)(c1->plate)));
	printf("\n\n");
	
	printf("Tests complete\n");
  free(c1);
  free(c2);
  free(c3);
  free(c4);
	free(c5);
	free(c6);
  exit(EXIT_SUCCESS);
	
}

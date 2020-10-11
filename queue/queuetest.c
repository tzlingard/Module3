#include <stdio.h>
#include "queue.h"
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

void print_car(car_t *car) {
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
	return (strcmp(car->plate, plate) == 0);
}

car_t *front = NULL;

int main(void) {
  int fails = 0;
  car_t *c1 = make_car("123456", 9999.99, 2014);
  car_t *c2 = make_car("Darty1", 120000, 2019);
  car_t *c3 = make_car("SUNGOD", 80080.42, 2020);
  car_t *c4 = make_car("DARTXC", 1769.99, 1769);



	
	printf("Test 1: Open a new queue\n");
	queue_t *q1 = qopen();
	printf("\n\n");
	
	printf("Test 2: Get and print from empty queue\n");
	car_t *cc1 = (car_t*)qget(q1);
	print_car(cc1);
	printf("\n\n");

	printf("Test 3 : Put to queue\n");
	qput(q1,(void*)c1);
	qput(q1,(void*)c2);
	qput(q1,(void*)c3);
	qput(q1,(void*)c4);
	printf("\n\n");

	printf("Test 4: Get and print from nonempty queue\n");
	cc1 = (car_t*)qget(q1);
	print_car(cc1);
	printf("\n\n");

	printf("Test 5: Search for plate 'SUNGOD' from nonempty queue\n");
	char* plate1 = "SUNGOD";
	car_t *find_car1 = qsearch(q1, platecheck, (void*)plate1);
 	print_car(find_car1);
	printf("\n\n");

	printf("Test 6: Search for plate 'THIS_SHOULD_FAIL' from nonempty queue\n");
	char* plate2 = "THIS_SHOULD_FAIL";
	car_t *find_car2 = qsearch(q1, platecheck, (void*)plate2);
	print_car(find_car2);
	printf("\n\n");


	///need tests for
	//qclose
	//qapply
	//qremove
	//qconcat
	
	
	cc1 = (car_t*)qget(q1);
	cc1 = (car_t*)qget(q1);
	cc1 = (car_t*)qget(q1);
	
	
  printf("Test completed with %d errors.\n", fails);
  free(c1);
  free(c2);
  free(c3);
  free(c4);
	free(q1);
  exit(EXIT_SUCCESS);
	
}

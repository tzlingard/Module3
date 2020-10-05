#include<stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

void print_car(car_t*);
car_t *make_car(char plate[], double, int);

car_t *front = NULL;

int main(void) {
  int fails = 0;
  car_t *c1 = make_car("123456", 9999.99, 2014);
  car_t *c2 = make_car("Darty1", 120000, 2019);
  car_t *c3 = make_car("SUNGOD", 80080.42, 2020);
  car_t *c4 = make_car("DARTXC", 1769.99, 1769);
  if (lget() != NULL) {
    printf("Failed: get from an empty list\n");
    fails++;
  }
  printf("Apply to an empty list: \n");
  // lapply(print_car);
  printf("%s\n", lremove("DARTXC")->plate);
  printf("The above code is not the problem\n");
  if (lput(c1) != 0) {
    printf("Failed: put to an empty list\n");
    fails++;
  }
  if (lput(c2) != 0) {
    printf("Failed: put to a non-empty list\n");
    fails++;
  }
  if (lget() == NULL) {
    printf("Failed: get from a non-empty list\n");
    fails++;
  }
  lput(c3);
  lput(c4);
  printf("Apply to a non-empty list: \n");
  // lapply(print_car);
  if (lremove("DARTXC") != c4) {
    printf("Failed: Remove from a non-empty list at the end\n");
    fails++;
  }
  if (lremove("Darty1") != c2) {
    printf("Failed: Remove from a non-empty list at the beginning\n");
    fails++;
  }
  lput(c1);
  lput(c2);
  if (lremove("123456") != c1) {
    printf("Failed: Remove from a non-empty list somewhere in the middle\n");
    fails++;
  }
  printf("Test completed with %d errors.\n", fails);
  free(c1);
  free(c2);
  free(c3);
  free(c4);
  exit(EXIT_SUCCESS);
}

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
}

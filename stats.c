#include <stdio.h>
#include "stats.h"

#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,  45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  unsigned char min = 0;
  unsigned char max = 0;
  unsigned char mean = 0;
  unsigned char median = 0;

  printf("=== Original Array ===\n");
  print_array(test, SIZE);

  /* Sort array descending */
  sort_array(test, SIZE);

  /* Calculate statistics */
  min = find_minimum(test, SIZE);
  max = find_maximum(test, SIZE);
  mean = find_mean(test, SIZE);
  median = find_median(test, SIZE);

  printf("\n=== Sorted Array (Descending) ===\n");
  print_array(test, SIZE);

  printf("\n=== Statistical Summary ===\n");
  print_statistics(min, max, mean, median);
}

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median) {
  printf("Minimum : %u\n", min);
  printf("Maximum : %u\n", max);
  printf("Mean    : %u\n", mean);
  printf("Median  : %u\n", median);
}

void print_array(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL) return;
  
  for (unsigned int i = 0; i < size; i++) {
    printf("%3u ", ptr[i]);
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }
}

unsigned char find_median(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL || size == 0) return 0;

  /* Note: Assumes array is already sorted or sorts a copy */
  if (size % 2 == 0) {
    return (ptr[(size / 2) - 1] + ptr[size / 2]) / 2;
  } else {
    return ptr[size / 2];
  }
}

unsigned char find_mean(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL || size == 0) return 0;

  unsigned int sum = 0;
  for (unsigned int i = 0; i < size; i++) {
    sum += ptr[i];
  }
  return (unsigned char)(sum / size);
}

unsigned char find_maximum(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL || size == 0) return 0;

  unsigned char max = ptr[0];
  for (unsigned int i = 1; i < size; i++) {
    if (ptr[i] > max) {
      max = ptr[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL || size == 0) return 0;

  unsigned char min = ptr[0];
  for (unsigned int i = 1; i < size; i++) {
    if (ptr[i] < min) {
      min = ptr[i];
    }
  }
  return min;
}

void sort_array(unsigned char *ptr, unsigned int size) {
  if (ptr == NULL || size == 0) return;

  for (unsigned int i = 0; i < size - 1; i++) {
    for (unsigned int j = i + 1; j < size; j++) {
      if (ptr[i] < ptr[j]) {
        unsigned char temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
      }
    }
  }
}
/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief A simple program who perform statistical analytics on a dataset 
 *
 * a couple of functions that can analyze an array of unsigned
 * char data items and report analytics on the maximum, minimum,
 * mean, and median of the data set. In addition, there are functions
 * to reorder this data set from large to small. All statistics are 
 * rounded down to the nearest integer. After analysis and sorting is done,
 * the data is printed to the screen in nicely formatted presentation
 *
 * @author Tassio Leno
 * @date 14/09/2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main(){

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char mean, median, minimum, maximum;
  unsigned char sortedTest[SIZE];

  /* Statistics and Printing Functions Go Here */
  sort_array(test, sortedTest, SIZE);
  mean = find_mean(sortedTest, SIZE);
  median = find_median(sortedTest, SIZE);
  maximum = find_maximum(sortedTest, SIZE); // notice that if you put a number greater than 255 in the dataset, it will overflow.
  minimum = find_minimum(sortedTest, SIZE);
  print_array(sortedTest, SIZE);
  print_statistics(mean, median, minimum, maximum);
  
  return;
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char mean, unsigned char median, unsigned char minimum, unsigned char maximum){

  printf("Analytics statistics: \n");
  printf("Mean: %d\n", mean);
  printf("Median: %d\n", median);
  printf("Minimum: %d\n", minimum);
  printf("Maximum: %d\n", maximum);

}

void print_array(const unsigned char *const array, unsigned int size){
  for (int i = 0; i <size; i++){
    printf("%d\n", array[i]);
  }
}

unsigned char find_median(const unsigned char *const array, unsigned int size){
  unsigned char parity;
  unsigned char position;
  unsigned char result;

  parity = (size%2==0)?1:0;
  
  if (parity){
    position = size/2;
    result = (array[position - 1] + array[position])/2;
  }
  else{
    position = size/2;
    result = array[position];
  }

  return result;
}

unsigned char find_mean(const unsigned char *const array, unsigned int size){

  int sum;

  for (int i = 0; i < size; i++){
    sum = sum + array[i];
  }
  unsigned char result;
  result = sum/size;
}

unsigned char find_maximum(const unsigned char *const array, unsigned int size){

  unsigned char result;


  for (int i = 0; i<size; i++){
    for (int j = i+1; j < size; j++){
      if (array[j] > result){
        result = array[j];
      }
    }
  }
  return result;
}

unsigned char find_minimum(const unsigned char *const array, unsigned int size){

  unsigned char result;

  for (int i = 0; i<size; i++){
    for (int j = i+1; j < size; j++){
      if (array[j] < result){
        result = array[j];
      }
    }
  }
  return result;
}

void sort_array(const unsigned char *const array, unsigned char *const result, unsigned int size){

  for (int i = 0; i<size; i++){
    result[i]=array[i];
  }

  for (int i = 0; i<size; i++){
    for (int j = i+1; j < size; j++){
      if (result[i] > result[j]){
        int aux = result[i];
        result[i] = result[j];
        result[j] = aux;
      }
    }
  }
}

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
 * @file stats.h
 * @brief file for stats declarations
 *
 * @author Tassio Leno
 * @date 14/09/2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median
 *
 * @param mean An unsigned char mean value of a data set
 * @param median An unsigned char median value of a data set
 * @param minimum An unsigned char  minimum value of a data set
 * @param maximum An unsigned char maximum value of a data set
 *
 * @return printed statistics in command line
 */
void print_statistics(unsigned char mean, unsigned char median, unsigned char minimum, unsigned char maximum);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param array A constant unsigned pointer to a dataset array
 * @param size An unsigned constant int value representing the size of the dataset
 *
 * @return printed array in command line
 */
void print_array(const unsigned char *const array, unsigned const int size);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array A constant unsigned pointer to a dataset array
 * @param size An unsigned constant int value representing the size of the dataset
 *
 * @return unsigned char median value
 */
unsigned char find_median(const unsigned char *const array, unsigned const int size);

/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param array A constant unsigned pointer to a dataset array
 * @param size An unsigned constant int value representing the size of the dataset
 *
 * @return unsigned char mean value
 */
unsigned char find_mean(const unsigned char *const array, unsigned const int size);

/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param array A constant unsigned pointer to a dataset array
 * @param size An unsigned constant int value representing the size of the dataset
 *
 * @return unsigned char minimum value
 */
unsigned char find_minimum(const unsigned char *const array, unsigned const int size);

/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param array A constant unsigned pointer to a dataset array
 * @param size An unsigned constant int value representing the size of the dataset
 *
 * @return unsigned char maximum value
 */
unsigned char find_maximum(const unsigned char *const array, unsigned const int size);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.
 *
 * @param array A constant unsigned pointer to a dataset array
 * @param result An unsigned char pointer to a variable to store the result
 * @param size An unsigned constant int value representing the size of the dataset
 *
 * @return nothing
 */
void sort_array(const unsigned char *const array, unsigned char *const result, unsigned int size);
#endif /* __STATS_H__ */

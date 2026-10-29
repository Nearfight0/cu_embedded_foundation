/*
Introduction to Embedded Systems Software and Development Environments.
Assignment 1
@Yusif Mirzabayli
*/

#ifndef __STATS_H__
#define __STATS_H__

/*
Printing the statistics of an array including maximum, minimum, mean and median values.

 */

 void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median);

 void print_array(unsigned *ptr, unsigned char size);

 unsigned char find_median(unsigned char *ptr, unsigned int size);

 unsigned char find_mean(unsigned char *ptr, unsigned int size);

 unsigned find_max(unsigned char *ptr, unsigned int size);

 unsigned find_min(unsigned char *ptr, unsigned int size);

 unsigned sort_array(unsigned char *ptr, unsigned int size);

#endif
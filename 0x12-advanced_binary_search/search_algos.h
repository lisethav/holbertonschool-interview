#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int binary_search(int *array, size_t left, size_t right, int value);
void print_binary(int *array, size_t left, size_t right);

#endif /* SEARCH_ALGOS_H */
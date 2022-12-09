#ifndef SORT_H
#define SORT_H

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void build_max_heap(int *array, size_t size, size_t index, size_t lenght);

#endif /* SORT_H */
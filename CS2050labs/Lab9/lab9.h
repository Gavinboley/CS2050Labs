#include <stdio.h>
#include <stdlib.h>

int ascendingBinarySearch(int *array, int element);
int isSortedAscending(int *array);

// Starter Code

void * createArray(size_t elementSize, int numElements);
int getSize(int *array);
void freeArray(void *array);

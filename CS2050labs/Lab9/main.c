#include "lab9.h"

int main() {
	int *array = createArray(sizeof(int), 10);
	for(int i = 0; i<getSize(array); i++)
	{
		array[i] = i+1;
	}
	for(int i = 0; i<getSize(array); i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
	int error = isSortedAscending(array);
	printf("Error code: %d\n", error);
	printf("index of 0: %d\n", ascendingBinarySearch (array,0));
	printf("index of 1: %d\n", ascendingBinarySearch (array,1));
	printf("index of 9: %d\n", ascendingBinarySearch (array,9));
	printf("index of 10: %d\n", ascendingBinarySearch (array,10));
	printf("index of 11: %d\n", ascendingBinarySearch (array,11));
	
	
	
	for(int i = 0; i<getSize(array); i++)
	{
		array[i] = (getSize(array)-1)-i;
	}
	for(int i = 0; i<getSize(array); i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
	int error2 = isSortedAscending(array);
	printf("Error code: %d\n", error2);
	printf("index of: %d\n", ascendingBinarySearch (array,0));
	printf("index of: %d\n", ascendingBinarySearch (array,1));
	printf("index of: %d\n", ascendingBinarySearch (array,9));
	printf("index of: %d\n", ascendingBinarySearch (array,10));
	printf("index of: %d\n", ascendingBinarySearch (array,11));
	
	freeArray(array);
}

void * createArray(size_t elementSize, int numElements) {
	int *array = malloc(sizeof(int) + elementSize * numElements);

	if(!array) {
		return NULL;
	}

	*array = numElements;

	return ++array;
}

void freeArray(void *array) {
	int *arr = array;
	free(arr - 1);
}

int getSize(int *array) {
	return array[-1];
}

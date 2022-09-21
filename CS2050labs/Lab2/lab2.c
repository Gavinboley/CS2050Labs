#include "lab2.h"

int * createIntArrayFromFile(FILE *file , int *size);
int lastAddressOf(int *array , int size , int **result , int element);
void freeArray(int *array);


/*
createIntArrayFromFile takes in the pointer to the file and the pointer to the array int size

createIntArrayFromFile takes the first int of the file and sets the value of the memory location of size passed through to the value
then it allocates an array of ints and sets their values equal to the numbers in the file one by one until its size is reached
it also checks to make sure it didnt fail to allocate memory for it

it returns the array pointer if it succeeded or null if it didnt.
*/
int * createIntArrayFromFile(FILE *file , int *size)
{
	int i = 0;
	fscanf(file, "%d", size);
	int currentint = 0;
	int *arrayInts;
	printf("%d" , *size);
	arrayInts = malloc((*size)*sizeof(int));
	while ((!feof (file)) && (arrayInts != NULL))
    {
		fscanf(file, "%d", &currentint);
		arrayInts[i] = currentint;
		i++;
	}
	if(arrayInts == NULL)
	{
		return NULL;
	}
	return arrayInts;
}

/*
combs through intaken array to check if it has a specific number and returns 0 if it finds it and 1 if it doesnt. it sets the value of result to the memory location of that number
*/

int lastAddressOf(int *array , int size , int **result , int element)
{
	for(int i=0; i<size; i++)
	{
		if(*array == element)
		{
			result = &array;
			return 0;
		}
		array++;
	}
	return 1;
}

/*
frees the allocated memory for previously malloced array and sets its pointer null
*/

void freeArray(int *array)
{
	free(array);
}
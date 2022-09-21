#include "lab3.h"

/* createCenteredArray function
	
	takes in the requested size of the array to be created
	creates array of that size and sets center value to be index zero
	returns the pointer to the array or null if the array is even/other errors
	
*/
int * createCenteredArray ( int size )
{
	if( size % 2 == 1)
	{
		int *array;
		array = malloc(size*sizeof(int));
		array = array - ((size)/2);
		return array; 
	}
	else
	{
		return NULL; 
	}
}

/* getAtIndex function
	
	takes in the pointer to the array, the size of that array, and the requested index
	makes sure that the index is part of the array 
	returns the value at that index or 1 if index isnt in the array or if the pointer is null
	
*/

int getAtIndex (int * array , int size , int index )
{
	if(array != NULL)
	{
		if(index<size)
		{
			return array[index];
		}
		else
		{
			return 1;
		}
	}
	else
		return 1;
}

/* avergaeUpperHalf function
	
	takes in the pointer to the array and the size of that array
	calculates the average from the center to the end
	and returns the average of those numbers. if array is null it returns 1.0
	
*/

float averageUpperHalf(int *array, int size)
{
	if(array != NULL)
		{
		int avgNumerator = 0; int avgDenominator = 0;	
		for(int i = 0; i<=(size/2);i++)
		{
			avgNumerator += array[i];
			avgDenominator += 1;
		}
		float average = avgNumerator/avgDenominator;
		return average;
	}
	else
		return 1.0f;
}

/* freeCenteredArray function
	
	takes in the pointer to the array and its size
	frees the array and then sets the address to null
	returns nothing
	
*/

void freeCenteredArray(int *array, int size)
{
	if(array != NULL)
	{
		array = array + ((size)/2);
		free(array);
		array = NULL;
	}
}

  //main method used to test methods

int main(void)
{
	int size = 5;
	int index = 4;
	int *array;
	
	array = createCenteredArray(size); 
	
	for(int i = (-(size)/2); i <= ((size)/2) ;i++)
	{
		array[i] = i;                              //says this is invalid pointer although it works
	}

	for(int i = (-(size)/2); i <= ((size)/2) ;i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
	for(int i = 0; i<= size/2; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
	printf("array[0] = %d\n" , array[0]);
	int valueOf = getAtIndex(array, size, index);
	float averageUpper = averageUpperHalf(array, size);
	printf("value of index at %d is %d\n", index, valueOf);
	printf("value of average of upper is %.2f\n", averageUpper);
	freeCenteredArray(array, size);
	
}

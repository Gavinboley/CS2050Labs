#include "lab1.h"

/*
	avgEven:
	Takes a pointer to an array of integers, an int of the size of that array, and the pointer location 
	to the float called result.
	
	Skims through the array to find even numbers, calculates their average, and writes to the memory
	location of result which the user provies and wants changed.
	
	Returns the number of even numbers in the array that are used to calculate the average(denominator)
	OR zero if there is no even numbers in the array
*/

int avgEven(int *array, int size, float *result)
{
	int evenSum = 0;
	int evenCount = 0;
	for(int i = 0;i < size;i++)
	{
		if(array[i] % 2 == 0)
		{
			evenSum += array[i];        //numerator
			evenCount += 1;				//denominator
		}
	}
	if(evenCount == 0)					//if no even numbers
	{
		return 0;
	}
	float evenAvg = (evenSum/evenCount);
	*result = evenAvg;
	return evenCount;
}

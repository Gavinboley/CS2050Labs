#include "lab0.h"

 /*
	CountOccurances takes in an int of the size of an array,
	the array of that size, and an int value that it looks for
	when combing through the array. It checks if any values in the
	array are the same as the int query and then returns the number
	of times it appears.
 
 */


int countOccurrences ( int size , int array [] , int query )
{
	int queryCount = 0;   
	for(int i=0; i<size;i++)
	{
		if (array[i] == query)
		{
			queryCount++;
		}
	}
	return queryCount;
}

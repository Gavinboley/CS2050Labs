#include "lab9.h"

int isSortedAscending (int * array )
{
	int arraySize = getSize(array);
	int j = 1;
	for(int i = 0; i < arraySize; i++)
	{
		if(array[i]<array[j])
		{
			if(i==arraySize-2)
				return 1;
		}
		j++;
	}
	return 0;
}

int ascendingBinarySearch ( int * array , int element )
{
	if(isSortedAscending(array) == 1)
	{
		int first = 0;
		int last = getSize(array);
		int mid;
		while(first<=last)
		{
			mid = (first+last)/ 2;
			if(element > array[mid])
				first = mid+1;
			else if(element < array[mid])
				last = mid-1;
			else
				return mid;
		}
		return -1;
	}
	else
		return -1;
}
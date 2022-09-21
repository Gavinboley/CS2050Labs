#include "lab2.h"

int main() {
	FILE* file = fopen("numbers.txt", "r");
	int size = 0;
	int *intarray = createIntArrayFromFile(file, &size);
	for(int i; i<size; i++)
	{
		printf("%d\n", intarray[i]);
	}
	printf("is this null? %d\n", intarray[49]);
	printf("size: %d\n", size);
	
	/*
		int resultint = 0;
		int *result;
		result = &resultint;
		int error = lastAddressOf(intarray , size , &result , 10);
		printf("error: %d", error);
		if(error==0)
		{
			 printf("the number i have is %d\n", *result);  //tells you the value of the pointer result which is written when searching
		}
		if(error==1)
		{
			printf("couldnt find it sorry\n");
		}
		*/
		freeArray(intarray);
} 


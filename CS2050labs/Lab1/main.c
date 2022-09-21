#include "lab1.h"

int main() {
	FILE *file = fopen("numbers.txt", "r");

	if(!file) {
		// Unable to open the specified file
		return EXIT_FAILURE;
	}

	int size;

	if(fscanf(file, "%d", &size) != 1) {
		fclose(file);
		// Unable to read the array size from the file
		return EXIT_FAILURE;
	}

	int array[size];

	for(int i = 0; i < size; ++i) {
		fscanf(file, "%d", array + i);
	}

    fclose(file);

    // END STARTER CODE
	float result = -1.0f;
	printf("%d\n", avgEven(array, size, &result));
	printf("%.3f\n", result);

}

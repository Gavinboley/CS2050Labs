#include "lab10.h"
#include "time.h"

int main() {
	BST *bst = initBST();
	clock_t time;
	insertBST(bst, 1);
	insertBST(bst, 5);
	insertBST(bst, 2);
	insertBST(bst, 4);
	insertBST(bst, 3);
	time = clock();
	printf("BST Contains Success for value 4(0 fail, 1 success): %d\n", BSTContains(bst, 4));
	time = clock() - time;
	printInOrder(bst);
	printf("Time between BST search and printing the BST: %f\n", ((double)time)/CLOCKS_PER_SEC);
	printf("BST Contains Success for value 6(0 fail, 1 success): %d\n", BSTContains(bst, 6));
	printf("Min Value of BST: %d\n",getMin(bst));
	freeTree(bst);
}


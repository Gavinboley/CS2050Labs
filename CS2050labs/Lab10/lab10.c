#include "lab10.h"

// suggested implementation
typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

typedef struct BST {
	Node *root;
} BST;

BST * initBST ();
void insertTree(Node *oldTree, Node *newTree);
void DeleteTree(Node *tree);
void printtree(Node *tree);

/*
	initBST initializes the BST by allocating memory(with empty starting member) and returns it, or NULL if it cant
*/
BST * initBST ()
{
	BST *bst = malloc(sizeof(BST)); 
	if(bst)
	{
		return bst;
	}
	else
		return NULL;
}

/*
	insertBST inserts the value requested into the tree appropriately based on BST datatype. returns 1 if it cant, 0 if it can
*/
int insertBST ( BST * tree , int data )
{
	Node *newTree = malloc(sizeof(Node));
	if(!newTree)
	{
		return 1;
	}
	newTree->data = data;
	newTree->left = newTree->right = NULL;
	
	if(tree && tree->root)
		insertTree(tree->root, newTree);
	else
		tree->root = newTree;

	return 0;
}

/*
	insertTree is a helper function to insertBST which does the actual inserting after the setup from the other function
*/
void insertTree(Node *oldTree, Node *newTree)
{
	int newnum, oldnum;
	oldnum = oldTree->data;
	newnum = newTree->data;
	if(newnum < oldnum)
	{
		if(oldTree->left)
			insertTree(oldTree->left, newTree);
		else
			oldTree->left = newTree;
		return;
	}
	if(newnum > oldnum)
	{
		if(oldTree->right)
			insertTree(oldTree->right, newTree);
		else
			oldTree->right = newTree;
		return;
	}
}

/*
	BSTContains checks if the requested value is a part of the tree and returns 1 if it is, 0 if it isnt
*/
int BSTContains(BST *tree, int data)
{
	if(tree)
	{
		Node * top = tree->root;
		while(top)
		{
			if(data<top->data)
			{
				if(top->left == NULL)
					return 0;
				top = top->left;
			}
			else if(data>top->data)
			{
				if(top->right == NULL)
					return 0;
				top = top->right;
			}
			if(data == top->data)
				return 1;
		}
	}
	return 0;
}

/*
	freeTree begins and ends the process of freeing the tree
*/
void freeTree(BST *tree)
{
	DeleteTree(tree->root);
	free(tree);
	tree = NULL;
}

/*
	DeleteTree is responsible for freeing all subtreed memory
*/
void DeleteTree(Node *tree)
{
	if (tree == NULL) return;
	DeleteTree(tree->left);
	DeleteTree(tree->right);
	free(tree);
	tree = NULL;
}

/*
	printInOrder begins the printing of the tree in order and spacing
*/
void printInOrder(BST *tree)
{
	printtree(tree->root);
	printf("\n");
}

/*
	printtree is responsible for printing all subtree members 
*/
void printtree(Node *tree)
{
	if (tree == NULL) return;
	printtree(tree->left);
	printf("%d ", tree->data);
	printtree(tree->right);
}

/*
	getMin gets the minimum member of the tree and returns it
*/
int getMin ( BST * tree )
{
	Node * top = tree->root;
	while(tree)
	{
		if(top->left == NULL)
			return top->data;
		top = top->left;
	}
	return tree->root->data;
}

/* //main function, ***********cannot submit two files*******
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
*/
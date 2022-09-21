#include "lab7.h"

void changeListSize(Node * list, int amount);

/*
	initList 
*/
Node * initList ()
{
	Node *list;
    list = malloc(sizeof(Node));
	int size = 0;
	list->data = &size;
    return list;
}

/*
	*(int*)list->data += amount;
*/
void changeListSize(Node* list, int amount)
{
	*(int*)list->data += amount;
}

int getSize(Node* list)
{
	return *(int*)list->data;
}

/*

*/

int insertAtIndex ( Node * list , void * data , int index )
{
	int i = 0;
	Node *addThis = malloc(sizeof(Node));
	if(!addThis)
	{
		return 1;
	}
	for(Node* thisOne=list; thisOne!=NULL; thisOne=thisOne->next) 
	{
		if(index == getSize(list))
		{
			changeListSize(list, 1);
			addThis->data = data;
			addThis->next = NULL;
			thisOne->next = addThis;
			return 1;
		}
		if(i+1 == index)
		{
			changeListSize(list, 1);
			addThis->data = data;
			if(thisOne->next == NULL)
				addThis->next = NULL;
			else
				addThis->next = thisOne->next->next;
			thisOne->next = addThis;
			return 1;
		}
		i++;
	}
	return 0;
}

void * getAtIndex ( Node * list , int index )
{
	int i = 0;
	for(Node* thisOne=list; thisOne->next!=NULL; thisOne=thisOne->next) 
	{
		if(i == index)
		{
			return thisOne->data;
		}
		i++;
	}
	return NULL;
}

void * removeAtIndex ( Node * list , int index )
{
	int i = 0;
	void* data = NULL;
	for(Node* thisOne=list; thisOne->next!=NULL; thisOne=thisOne->next) 
	{
		if(i+1 == index)
		{
			changeListSize(list, -1);
			data = thisOne->data;
			thisOne->next = thisOne->next->next->next;
			return data;
		}
		i++;
	}
	return NULL;
}

void * removeAtTail ( Node * list )
{
	void* data = NULL;
	for(Node* thisOne=list; thisOne->next!=NULL; thisOne=thisOne->next) 
	{
		if(thisOne->next->next==NULL)
		{
			changeListSize(list, -1);
			data = thisOne->next->data;
			thisOne->next = NULL;
			return data;
		}
	}
	return NULL;
}

void freeList ( Node ** list )
{
	Node * currentNode = *list;
    for(Node * nextNode; currentNode!=NULL; currentNode = nextNode)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = NULL;
    }
	*list = NULL;
}

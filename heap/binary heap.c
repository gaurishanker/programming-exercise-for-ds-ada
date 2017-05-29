#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

int heap[1000];
int size;

int parent(int i)
{
	return (i-1)/2;
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int getMin()
{
	return heap[0];
}

void printTree()
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ",heap[i]);
	}
	printf("\n");
}

void insert(int data)
{
	if(size == 1000)
		printf("OVERFLOW\n");
	heap[size] = data;
	int i=size;
	size++;
	while(i!=0 && heap[i] < heap[parent(i)] )
	{
		swap(&heap[i],&heap[parent(i)]);
		i = parent(i);
	}
	//printf("After insertion \n");
	//printTree();
}



void decreaseKey(int i,int new_val)
{
	heap[i] = new_val;
	while(i != 0 && heap[parent(i)] > heap[i])
	{
		swap(&heap[i],&heap[parent(i)]);
		i = parent(i);
	}
}

int left(int i)
{
	return (2*i+1);
}

int right(int i)
{
	return (2*i+2);
}

void heapify(int i)
{
	int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && heap[l] < heap[i])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;
    if (smallest != i)
    {
    	printf("\n In heapify %d %d\n", i , smallest );
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int extractMin()
{
	if(size==0)
	{
		printf("No elements to delete\n");
		return 0;
	}
	if(size == 1)
	{
		size--;
		return heap[0];
	}
	int temp = heap[0];
	heap[0] = heap[size-1];
	size--;
	heapify(0);
	//printf("After extractMin \n");
	//printTree();
}

void delete(int i)
{
	decreaseKey(i,INT_MIN);
	extractMin();
}

int main(int argc, char const *argv[])
{
	size = 0;
	insert(11);
	insert(3);
	insert(2);
	insert(15);
	insert(5);
	insert(4);
	insert(45);
	extractMin();
	delete(1);
	return 0;
}
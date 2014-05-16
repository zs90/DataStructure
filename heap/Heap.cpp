#include "stdafx.h"
#include <stdlib.h>

using namespace std;

//a为输入堆，n为待上滤元素下标
void MinHeapAjustUp(int heap[], int pos)
{
	int father_index, child_index, element;
	
	//两个节点分别为父节点和子节点，其中子节点为待上滤节点
	child_index = pos;
	father_index = (child_index - 1)/2;

	element = heap[pos];

	while(father_index >= 0)
	{
		//若父节点大于待上滤节点，则将节点上滤，换句话说，将父节点的值赋给子节点，然后更新下标
		if( heap[father_index] > element )
		{
			heap[child_index] = heap[father_index];
			child_index = father_index;
			father_index = (child_index - 1)/2;
		}
		else
			break;
	}

	//最后空出来的是子节点，而不是父节点
	heap[child_index] = element;
}

//heap[]为输入堆，pos为待下滤元素下标,size为堆大小
void MinHeapAjustDown(int heap[], int pos, int size)
{
	int father_index, child_index, element;

	//设置父子节点，其中父节点设为待下滤节点
	father_index = pos;
	child_index = father_index * 2 + 1;
	element = heap[pos];

	while( child_index < size)
	{
		// 需要找到左右两个孩子节点中最小的那个。注意不要越界
		if( child_index + 1 < size  && heap[child_index] > heap[child_index + 1])
		{
			child_index++;
		}

		//将最小的子节点与待下滤的值比较，如果子节点更小，则需下滤，换句话说，子节点的值赋给父节点，并更新下标
		if( heap[child_index] < element)
		{
			heap[father_index] = heap[child_index];
			father_index = child_index;
			child_index = father_index * 2 + 1;
		}
		else
			break;
	}

	//空出来的是父节点，而不是子节点
	heap[father_index] = element;
}

//建立最小堆
//注意！堆可以有两种方式来建立，一种是下滤法，一种是上滤法。
//下滤法效率更高，时间复杂度为O(n),上滤法则需O(nlogn)
//heap为原始堆，size为堆的大小
void BuildMinHeapDown(int heap[], int size)
{
	for( int i = size / 2 - 1; i >= 0; --i)
	{
		MinHeapAjustDown(heap, i, size);
	}
}
void BuildMinHeapUp(int heap[], int size)
{
	for( int i = 0; i < size; i++)
	{
		MinHeapAjustUp(heap, i);
	}
}

inline void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//堆的删除,只能堆顶开始删除
void MinHeapDelete(int heap[], int size)
{
	Swap(heap[size-1],heap[0]);
	//删除后size-1
	MinHeapAjustDown(heap, 0, size-1);	
}

//堆排序
void MinHeapSort(int heap[], int size, int sorted[])
{
	//首先输出堆顶元素，然后删除。注意size在递减。
	for(int i = size - 1, j = 0; i >= 0; --i)
	{
		sorted[j++] = heap[0];
		MinHeapDelete(heap, size--);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int src[8] = {5,4,3,7,1,8,23,-2};
	int heap[15];
	int sorted[15]; 
	memcpy(heap, src, sizeof(src)); 
	BuildMinHeapDown(heap,8);
	MinHeapSort(heap,8,sorted);
	for(int i = 0; i < 8; ++i)
		printf("%d ",sorted[i]);
	system("pause");
    	return 0;
}


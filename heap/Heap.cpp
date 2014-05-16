#include "stdafx.h"
#include <stdlib.h>

using namespace std;

//aΪ����ѣ�nΪ������Ԫ���±�
void MinHeapAjustUp(int heap[], int pos)
{
	int father_index, child_index, element;
	
	//�����ڵ�ֱ�Ϊ���ڵ���ӽڵ㣬�����ӽڵ�Ϊ�����˽ڵ�
	child_index = pos;
	father_index = (child_index - 1)/2;

	element = heap[pos];

	while(father_index >= 0)
	{
		//�����ڵ���ڴ����˽ڵ㣬�򽫽ڵ����ˣ����仰˵�������ڵ��ֵ�����ӽڵ㣬Ȼ������±�
		if( heap[father_index] > element )
		{
			heap[child_index] = heap[father_index];
			child_index = father_index;
			father_index = (child_index - 1)/2;
		}
		else
			break;
	}

	//���ճ��������ӽڵ㣬�����Ǹ��ڵ�
	heap[child_index] = element;
}

//heap[]Ϊ����ѣ�posΪ������Ԫ���±�,sizeΪ�Ѵ�С
void MinHeapAjustDown(int heap[], int pos, int size)
{
	int father_index, child_index, element;

	//���ø��ӽڵ㣬���и��ڵ���Ϊ�����˽ڵ�
	father_index = pos;
	child_index = father_index * 2 + 1;
	element = heap[pos];

	while( child_index < size)
	{
		// ��Ҫ�ҵ������������ӽڵ�����С���Ǹ���ע�ⲻҪԽ��
		if( child_index + 1 < size  && heap[child_index] > heap[child_index + 1])
		{
			child_index++;
		}

		//����С���ӽڵ�������˵�ֵ�Ƚϣ�����ӽڵ��С���������ˣ����仰˵���ӽڵ��ֵ�������ڵ㣬�������±�
		if( heap[child_index] < element)
		{
			heap[father_index] = heap[child_index];
			father_index = child_index;
			child_index = father_index * 2 + 1;
		}
		else
			break;
	}

	//�ճ������Ǹ��ڵ㣬�������ӽڵ�
	heap[father_index] = element;
}

//������С��
//ע�⣡�ѿ��������ַ�ʽ��������һ�������˷���һ�������˷���
//���˷�Ч�ʸ��ߣ�ʱ�临�Ӷ�ΪO(n),���˷�����O(nlogn)
//heapΪԭʼ�ѣ�sizeΪ�ѵĴ�С
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

//�ѵ�ɾ��,ֻ�ܶѶ���ʼɾ��
void MinHeapDelete(int heap[], int size)
{
	Swap(heap[size-1],heap[0]);
	//ɾ����size-1
	MinHeapAjustDown(heap, 0, size-1);	
}

//������
void MinHeapSort(int heap[], int size, int sorted[])
{
	//��������Ѷ�Ԫ�أ�Ȼ��ɾ����ע��size�ڵݼ���
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


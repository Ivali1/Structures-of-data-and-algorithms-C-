
#include<iostream>
#include <algorithm>
#include <assert.h>


///
///	Пирамидално сортиране (Heap Sort)
/// ASC
void Shifft(int* pArr, int pos, int size)
{
	int tempBox = pArr[pos];
	int ni = pos;
	int si = 2 * pos + 1;
	while (si < size)
	{
		if (si < (size - 1) && pArr[si] > pArr[si + 1])
		{
			++si;
		}

		if (pArr[si] < tempBox)
		{
			pArr[ni] = pArr[si];
			ni = si;
			si = 2 * si + 1;
		}
		else
			break;
	}
	pArr[ni] = tempBox;
}

/*void HeapSort(int* pArr, int size)
{
	if (pArr == NULL || size == 0)
	{
		return;
	}
	int pos = size / 2 - 1;

	while (pos >= 0)
	{
		Shifft(pArr, pos, size);
		--pos;
	}
	int tempSize = size-1;
	while (tempSize >= 0)
	{
	  std::swap(pArr[0], pArr[tempSize]);
		Shifft(pArr, 0, tempSize);
        --tempSize;
	}
}*/
void HeapSort(int* pArr, int size)
{
	if (pArr == NULL || size == 0)
	{
		return;
	}
	int pos = size / 2 - 1;

	while (pos >= 0)
	{
		Shifft(pArr, pos, size);
		--pos;
	}
	int* tempArray = new int[size];
	int tempSize = size - 1;
	int i=0;
	while (tempSize >= 0)
	{
		tempArray[i] = pArr[0];
		pArr[0] = pArr[tempSize];
		Shifft(pArr, 0, tempSize);
		--tempSize;
		++i;
	}
	i = 0;
	for (int j = 0; j < size; ++j)
	{
		pArr[j] = tempArray[i];
		++i;
	}
}


//Сортираме във възходящ ред


int main()

{
	int arr[] = { 40,60,10,20,50,30 };
	for (int i = 0; i < 6; ++i)
	{
		std::cout << arr[i];

	}
	std::cout << std::endl;
	HeapSort(arr, 6);
	for (int i = 0; i < 6; ++i)
	{
		std::cout << arr[i];

	}
	std::cout << std::endl;
	return 0;
}
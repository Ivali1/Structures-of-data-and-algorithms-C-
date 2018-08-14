#include<iostream>

void Merge(int* left, int sizeLeft, int* right, int sizeRight, int* result)
{
	int i = 0;
	int iLeft = 0;
	int jRight = 0;

	while (iLeft < sizeLeft && jRight < sizeRight)
	{
		if (left[iLeft] < right[jRight])
		{
			result[i] = left[iLeft];
			++iLeft;
		}
		else
		{
			result[i] = right[jRight];
			++jRight;
		}
		++i;
	}

	while (iLeft < sizeLeft)
	{
		result[i] = left[iLeft];
		++i;
		++iLeft;
	}

	while (jRight < sizeRight)
	{
		result[i] = right[jRight];
		++i;
		++jRight;
	}

}


void MergeSort(int* array, int size)
{
	int* result = new int[8];
	if (size < 2)
	{
		return;
	}
	int middle = size / 2;

	MergeSort(array, middle);
	MergeSort(array + middle, size - middle);
	Merge(array, middle, array + middle, size - middle,result);

	for (int i = 0; i < size; ++i)
	{
		array[i] = result[i];
	}

}




int main()
{
	

	int parray[8] = { 2,4,1,6,8,5,3,7 };
	
	for (int i = 0; i < 8; ++i)

		std::cout << parray[i];

	std::cout << std::endl;

	MergeSort(parray, 8);
	for (int i = 0; i < 8; ++i)

		std::cout << parray[i];

	std::cout << std::endl;
	

	return 0;
}

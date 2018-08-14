
#include<iostream>
#include<string.h>

void CountingSort(int* pArr, int size)
{
	int min = pArr[0];
	int max = pArr[0];
	for (int i = 1; i < size; ++i)
	{
		if (pArr[i] < min)
		{
			min = pArr[i];
		}
		if (pArr[i] > max)
		{
			max = pArr[i];
		}
	}

	//Create a count array to store count of inidividul
		// characters and initialize count array as 0
	int* count = new int[50];

	int* Output = new int[size];
	for (int i = min; i <= max; ++i)
	{
		count[i] = 0;
	}
	for (int i = min; i <= max; ++i)
	{
		std::cout << count[i] << " ";

	}
	std::cout << std::endl;
	// store count of each character
	for (int i = 0; i < size; ++i)
	{
		++count[pArr[i]];
	}
	for (int i = min; i <= max; ++i)
	{
		std::cout << count[i] << " ";

	}
	std::cout << std::endl;

	// Change count[i] so that count[i] now contains actual
	// position of this character in output array

	int k = min;
	count[k] = count[k];  
	for (int k = min + 1; k <= max; ++k)
	{
			count[k] = count[k] + count[k - 1];

	}
	k = 0;
	for (int i = min; i <= max; ++i)
	{
		std::cout << count[i] << " ";

	}
	std::cout << std::endl;



	for (int i = 0; i < size; ++i) 

	{
		Output[count[pArr[i]]-1] = pArr[i];
		--count[pArr[i]];

	}
	for (int i = min; i <= max; ++i)
	{
		std::cout << count[i] << " ";

	}
	std::cout << std::endl;

	for (int i = 0; i < size; ++i)
	{
		pArr[i] = Output[i];
	}
	for (int i = min; i <= max; ++i)
	{
		std::cout << count[i] << " ";

	}
	std::cout << std::endl;
}


int main()
{


	int arr[] = { 10,7,12,4,9,13 };
	for (int i = 0; i <6;++i)
	{
		std::cout << arr[i] << " ";

	}
	
	std::cout << std::endl;
	CountingSort(arr,6);
	for (int i = 0; i < 6; ++i)
	{
		std::cout << arr[i];

	}
	std::cout << std::endl;
	
	return 0;
}
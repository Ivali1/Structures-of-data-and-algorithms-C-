#include<iostream>

void InsertionSort(int arr[], size_t sizeArr)
{
	for (size_t i = 1; i < sizeArr; ++i)
	{
		size_t j = i;
		int curr = arr[i];
		while (j >0 && arr[j - 1] >= curr)
		{
			arr[j] = arr[j - 1];
			--j;

		}
		arr[j] = curr;

	}
}

int main()
{
	int arr[9] = { 5,8,1,6,2,7,4,3,9 };
	InsertionSort(arr, 9);
	for (int i = 0; i < 9; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
	return 0;
}
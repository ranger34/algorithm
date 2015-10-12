#include <iostream>
using namespace std;

const int N = 20;

void output(int nums[])
{
	for(int i = 0; i < N; i++)
		cout << nums[i]<< " ";
	cout << endl;
}

void merge(int nums[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *left = new int[n1];
	int *right = new int [n2];

	for(i = 0; i < n1; i++)
		left[i] = nums[p + i];
	for(j = 0; j < n2; j++)
		right[j] = nums[q + 1 + j];

	i = j = 0;
	k = p;
	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
			nums[k++] = left[i++];
		else
			nums[k++] = right[j++];
	}

	while(i < n1)
		nums[k++] = left[i++];
	while(j < n2)
		nums[k++] = right[j++];

	delete []left;
	delete []right;
}


void mergeSort(int nums[], int p, int r)
{
	if(p < r)
	{
		int q = (p + r)/2;
		mergeSort(nums, p, q);
		mergeSort(nums, q+1, r);

		merge(nums, p, q, r);

		output(nums);
	}
}

int main()
{
	int nums[N] = {4, 11, 6, 33, 3, 99, 9, 22, 1, 55, 2, 44, 7, 88, 0, 77, 2, 66, 5, 34};

	mergeSort(nums, 0, N-1);

	return 0;
}
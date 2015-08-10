#include <iostream>
using namespace std;

const int N = 8;
int x = 0;

void Output(int data[], int index)
{
	cout << index << ": ";
	for(int i = 0; i < N; i++)
		cout << data[i] << " ";
	cout << endl;
}

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(int data[], int low, int high)
{
	int pivot = data[low];
	while(low < high)
	{
		while(low < high && data[high] >= pivot)
			--high;
		Swap(data[low], data[high]);

		while(low < high && data[low] <= pivot)
			++low;
		Swap(data[low], data[high]);
	}

	Output(data, ++x);
	return low;
}

void QuickSort(int data[], int low, int high)	//recursion
{
	if(low < high)
	{
		int pivot = Partition(data, low, high);
		QuickSort(data, low, pivot - 1);
		QuickSort(data, pivot + 1, high);
	}
}

int main()
{
	int data[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	Output(data, 0);
	QuickSort(data,0, N-1);

	return 0;
}
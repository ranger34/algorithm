#include <iostream>
using namespace std;

const int N = 8;

void Print(int data[], int index)
{
	cout << index << ": ";
	for(int i = 0; i < N; i++)
		cout << data[i] << " ";
	cout << endl;
}

void Swap(int data[], int j)
{
	int tmp = data[j];
	data[j] = data[j + 1];
	data[j + 1] = tmp;
}

void BubbleSort_1(int data[])		//simplest one
{
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < N - 1 - i; j++)
		{
			if(data[j] > data[j + 1])
				Swap(data, j);
		}
		Print(data,i + 1);
	}

}

void BubbleSort_2(int data[])	// find the min one and the max one every time
{
	int low = 0;
	int high = N -1;
	int i = 0, j;
	while(low < high)
	{
		for(j = low; j < high; ++j)
			if(data[j] > data[j + 1])
				Swap(data, j);
		--high;

		for(j = high; j > low; --j)
			if(data[j - 1] > data[j])
				Swap(data, j - 1);
		++low;

		Print(data, ++i);
	}
}

int main()
{
	int data[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	Print(data, 0);
	//BubbleSort_1(data);
	BubbleSort_2(data);

	return 0;
}
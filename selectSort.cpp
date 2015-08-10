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

void SelectSort(int data[])
{
	int k, tmp;
	for(int i = 0; i < N; i++)
	{
		k = i;
		for(int j = i + 1; j < N; j++)	//select the min one
			if(data[j] < data[k])
				k = j;

		if(k != i)
		{
			tmp = data[i];
			data[i] = data[k];
			data[k] = tmp;
		}

		Print(data,i + 1);
	}

}

int main()
{
	int data[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	Print(data, 0);
	SelectSort(data);

	return 0;
}
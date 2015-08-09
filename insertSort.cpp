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

void InsertSort(int data[])
{
	int j, tmp;
	for(int i = 1; i < N; i++)	//i means the point
	{
		tmp = data[i];
		j = i - 1;

		while(tmp < data[j] && j >= 0)
		{	
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = tmp;		// insert

		Print(data,i);
	}

}

int main()
{
	int data[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	InsertSort(data);

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5;			// number of items
const int C = 10;			// capacity of bag

struct Item
{
	float weight;
	float value;
	float ratio;
};

bool compare(Item a, Item b)
{
	return a.ratio > b.ratio;
}

float Fractional_Knapsack(Item (&item)[N])	// greedy algorithm
{
	float value = 0;
	float capacity = C;
	float tmp[N];

	sort(item, item + N, compare);

	for(int i = 0; i < N; i++)
	{
		if(item[i].weight < capacity)
		{
			value += item[i].value;
			capacity -= item[i].weight;
			tmp[i] = 1;
		}
		else
		{
			tmp[i] = capacity/item[i].weight;
			value += item[i].value * tmp[i];
			capacity = 0;
		}
	}

	return value;
}

int main()
{
	float w[N] = {2.0, 2.0, 6.0, 5.0, 4.0};
	float v[N] = {6.0, 3.0, 5.0, 4.0, 6.0};
	Item item[N];
	
	for(int i = 0; i < N; i++)
	{
		item[i].weight = w[i];
		item[i].value = v[i];
		item[i].ratio = v[i]/w[i];
		cout << item[i].ratio<< " ";
	}
	cout << endl;
	cout << Fractional_Knapsack(item) << endl;

	return 0;
}
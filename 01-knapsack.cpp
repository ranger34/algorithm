#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5;			// number of items
const int C = 10;			// capacity of bag
int w[N + 1] = {0, 2, 2, 6, 5, 4};
int v[N + 1] = {0, 6, 3, 5, 4, 6};
int f[N + 1][C + 1] = {{0}};
int ff[N + 1] = {0};

/*
recurrence equation:
f(i,j) = max{f(i - 1,j - w[i]) + v[i](j>=w[i]), f(i - 1,j)} 
*/
int Knapsack()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			if(j >= w[i])
				f[i][j] = max(f[i-1][j],f[i-1][j-w[i]] + v[i]);
			else
				f[i][j] = f[i-1][j];
		}
	}
	return f[N][C];
}

/*
space optimization
recurrence equation:
f(j) = max{f(j - w[i]) + v[i](j>=w[i]), f(j)} 
*/

int Knapsack_SpaceOpt()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = C; j >= w[i]; j--)		//set low bound to be w[i]
		{
			if(j >= w[i])
				ff[j] = max(ff[j], ff[j - w[i] + v[i]]);
			else
				ff[j] = ff[j];
		}
	}
	return f[N][C];
}

int main()
{
	cout << Knapsack() << endl;
	cout << Knapsack_SpaceOpt() << endl;
	return 0;
}
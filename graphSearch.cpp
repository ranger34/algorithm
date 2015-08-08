#include <iostream>
#include <Stack>
#include <Queue>
using namespace std;

const int vnum = 5;
int visited[vnum];

struct Graph
{
	int vertex[vnum];
	int arc[vnum][vnum];
};

void CreatGraph(Graph &G, int data[], int maxtrix[][vnum])
{
	for(int i = 0; i < vnum; i++)
		G.vertex[i] = data[i];
	for(int i = 0; i < vnum; i++)
		for(int j = 0; j < vnum; j++)
			G.arc[i][j] = maxtrix[i][j];
}

void DFS(Graph *G, int v)
{
	if(!visited[v])
	{
		cout << G->vertex[v];
		visited[v] = 1;
	}
	for(int i = 0; i < vnum; i++)
		if(G->arc[v][i] && visited[i] != 1)
			DFS(G, i);
}

void BFS(Graph *G, int v)
{
	int f;
	queue<int> q;
	if(!visited[v])
	{
		cout << G->vertex[v];
		visited[v] = 1;
		q.push(v);
	}
	while(!q.empty())
	{
		f = q.front();
		q.pop();
		for(int i = 0; i < vnum; i++)
			if(G->arc[f][i] && visited[i] != 1)
			{
				cout << G->vertex[i];
				visited[i] = 1;
				q.push(i);
			}
	}
}

int main()
{
	Graph *G = new Graph;

	int data[vnum] = {1, 2, 3, 4, 5};
	int arcMatrix[vnum][vnum] = 
	{
		{0, 1, 1, 0, 0},
		{1, 0, 0, 1, 0},
		{1, 0, 0, 1, 1},
		{0, 1, 1, 0, 1},
		{0, 0, 1, 1, 0},
	};

	CreatGraph(*G, data, arcMatrix);
	cout << "vertex: ";
	for(int i = 0; i < vnum; i++)
		cout << G->vertex[i];
	cout << endl << "arc: " << endl;
	for(int i = 0; i < vnum; i++)
	{
		cout << "  ";
		for(int j = 0; j < vnum; j++)
			cout << G->arc[i][j];
		cout << endl;
	}
	cout << endl;

	cout << "DFS: " << endl;
	DFS(G, 0);
	cout << endl;

	memset(visited, 0, sizeof(visited));

	cout << "BFS: " << endl;
	BFS(G, 0);
	cout << endl;

	return 0;
}

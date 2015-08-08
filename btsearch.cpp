#include <iostream>
#include <Stack>
#include <Queue>
using namespace std;

int index = 0;

typedef struct Node
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}* Tree;

void treeConstructor(Tree &node, char data[])
{
	char e = data[index++];
	if(e == '#')
		node = nullptr;
	else
	{
		node = new Node;
		node->data = e;
		treeConstructor(node->lchild, data);
		treeConstructor(node->rchild, data);
	}
}

void DFS(Tree root)
{
	stack<Node *> nodeStack;
	nodeStack.push(root);
	Node *node;
	while(!nodeStack.empty())
	{
		node = nodeStack.top();
		cout << node->data;
		nodeStack.pop();
		if(node->rchild)
			nodeStack.push(node->rchild);
		if(node->lchild)
			nodeStack.push(node->lchild);
	}
}

void BFS(Tree root)
{
	queue<Node *>nodeQueue;
	nodeQueue.push(root);
	Node *node;
	while(!nodeQueue.empty())
	{
		node = nodeQueue.front();
		cout << node->data;
		nodeQueue.pop();
		if(node->lchild)
			nodeQueue.push(node->lchild);
		if(node->rchild)
			nodeQueue.push(node->rchild);
	}
}

int main()
{
	char data[16] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#', '\0'};
	Tree root;
	treeConstructor(root, data);
	cout << "DFS: ";
	DFS(root);
	cout << endl;
	cout << "DFS: ";
	BFS(root);
	cout << endl;

	return 0;
}

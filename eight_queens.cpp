#include <iostream>
using namespace std;

int a[8],n = 8,i,j,t=1;

//�ο�:http://blog.csdn.net/bone_ace/article/details/41419695

//Check���������n�еĻʺ��Ƿ��֮ǰ�Ļʺ��г�ͻ��û�г�ͻ����1

/*Լ��������
1.����ͬһ�У�a[n] != a[i]
2.����ͬһ�У���Ϊ������ÿһ����һ���ʺ��λ�ã�����ͬһ�в����г�ͻ������Ҫ���ǡ�
3.����ͬһ������ߣ�a[n]-a[i] != n-i
4.����ͬһ�ҶԽ��ߣ�a[n]-a[i] != -(n-i)
����3��4���Ժϳɣ�abs(a[n]-a[i]) != abs(n-i)
*/
int Check(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(abs(a[i]-a[n])==abs(i-n) || a[i]==a[n])
			return 0;
	}
	return 1;
}

//���õݹ�ʵ��������������ͻ���
void Try(int i)
{
	int j,k;
	for(j=1;j<=n;j++)
	{
		a[i]=j;
		if(Check(a,i))	//�����j�в�����֮ǰ�Ļʺ��ͻ
		{
			//���i<n������û���ҵ��˸��ʺ󣬼����ݹ�
			if(i<n)
				Try(i+1);
			//����ҵ���һ�������
			else
			{
				printf("��%d�ֽⷨ��\n",t++);
				for(k=1;k<=n;k++)
					printf("��%d���ʺ�%d\n",j,a[k]);
				printf("\n\n");
			}
		}
	}
}

int main()
{
	cout << "n=" << n << endl;
	Try(1);

	return 0;
}
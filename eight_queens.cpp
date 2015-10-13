#include <iostream>
using namespace std;

int a[8],n = 8,i,j,t=1;

//参考:http://blog.csdn.net/bone_ace/article/details/41419695

//Check函数检验第n行的皇后是否和之前的皇后有冲突，没有冲突返回1

/*约束条件：
1.不在同一列：a[n] != a[i]
2.不在同一行：因为现在是每一行求一个皇后的位置，所以同一行不会有冲突，不需要考虑。
3.不在同一对左角线：a[n]-a[i] != n-i
4.不在同一右对角线：a[n]-a[i] != -(n-i)
条件3和4可以合成：abs(a[n]-a[i]) != abs(n-i)
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

//利用递归实现深度优先搜索和回溯
void Try(int i)
{
	int j,k;
	for(j=1;j<=n;j++)
	{
		a[i]=j;
		if(Check(a,i))	//如果第j列不会与之前的皇后冲突
		{
			//如果i<n，即还没有找到八个皇后，继续递归
			if(i<n)
				Try(i+1);
			//如果找到了一组解就输出
			else
			{
				printf("第%d种解法：\n",t++);
				for(k=1;k<=n;k++)
					printf("第%d个皇后：%d\n",j,a[k]);
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
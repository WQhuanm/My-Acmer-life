#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 120;
//堆排序
//没有稳定性
//思想在建立一个堆（这里是大堆），然后每次把堆顶（最大值）取出，再次建堆，直到取完，这样就排序完了
//假设目前节点i，有如下定理，其父节点是（i-1）/2，子节点是2*1+1与2*i+2，（注意，二叉树第一个数是数组的a[0]才符合这个情况，
//而所有节点n，可以推出第一个非叶子节点（即最后一个父节点），即(n-1)/2
int n;
int a[N];
void make_mheap(int start, int end)   //建堆的函数，每次传入要比较的节点与目前堆的最后位置end
{
	int fa = start;//先让这个节点为父节点，比较子节点与他的大小（如果有的话）
	int son = 2 * fa + 1;
	while (son <= end)
		{
			if (son < end && a[son] < a[son + 1])son++;//这一句是取出俩子节点中较大的一个，son < end是说如果你有俩子节点的话
			if (a[son] > a[fa])//只要这个点比子节点小，更换，然后，就需要继续比较与下一级子节点的大小
				{
					swap(a[fa], a[son]);
					fa = son;//变成子节点
					son = fa * 2 + 1;//重新寻找他的新的子节点
				}
			else return ;//如果他就是比子节点大，可以跳出（不跳就别想出去了）
		}
}
void heapsort( )//这里是每次取堆顶，重新建立最大堆
{
	for (int i = n - 1; i >= 0; --i)
		{
			swap(a[0], a[i]);
			make_mheap(0, i - 1);
		}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	int end = n - 1;
	for (int i = (n - 1) / 2; i >= 0; --i)make_mheap(i, end);//i = (n - 1) / 2是最后一个父节点，我们要从底层到顶部（遍历每个父节点）逐步建立最大堆
	heapsort();
	for (int i = 0; i < n; ++i)cout << a[i] << " ";
	return 0;
}

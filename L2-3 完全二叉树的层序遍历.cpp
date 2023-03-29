#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 2e5 + 10;

int a[N],t[N];
int cnt,n;
void build(int p)
{
	if (p>n)return;//层序遍历顺序遍历前n个点，超过n就返回
	build(p<<1);
	build(p<<1|1);
	t[p]=a[++cnt];//后序遍历就是儿子们都访问完了才赋值根节点
}

int main()
{
	cin>>n;
	for (int i=1; i<=n; ++i)cin>>a[i];
	build(1);
	for (int i=1; i<=n; ++i)cout<<t[i]<<" \n"[i==n];
}


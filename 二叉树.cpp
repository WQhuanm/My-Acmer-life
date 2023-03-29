#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int t[N];//t表示树上节点
int cnt;
for (int i=1; i<=n; ++i)cout<<t[i]<<endl;
void build(int p)
{
	build(p<<1);//每次x先进入左儿子
	build(p<<1|1);//再进入右儿子
	cout<<t[p];//最后存储根节点
}


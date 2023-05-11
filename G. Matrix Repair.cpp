#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 1e3 + 10;

int a[N][N],cntc[N],cntr[N],c[N],r[N],cc[N],rr[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)
			{
				cin>>a[i][j];
				if(~a[i][j])cntr[i]++,cntc[j]++,cc[j]^=a[i][j],rr[i]^=a[i][j];//cc,rr维护的是当前已知的异或和
			}
	for(int i=1; i<=n; ++i)cin>>r[i];
	for(int i=1; i<=n; ++i)cin>>c[i];
	queue<int>q;
	for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)if(a[i][j]==-1&&(cntr[i]==n-1||cntc[j]==n-1))q.push((i-1)*n+j);
	while(!q.empty())
		{
			int u=q.front();
			q.pop();//每次都操作可以变成已知的-1元素
			int x=(u+n-1)/n,y=u-(x-1)*n;
			if(a[x][y]!=-1)continue;
			if(cntr[x]==n-1)a[x][y]=r[x]^rr[x];
			else if(cntc[y]==n-1)a[x][y]=c[y]^cc[y];
			cntr[x]++,cntc[y]++;
			cc[y]^=a[x][y],rr[x]^=a[x][y];
			for(int i=1; i<=n; ++i)
				{
					if(a[i][y]==-1&&(cntr[i]==n-1||cntc[y]==n-1))q.push((i-1)*n+y);//暴力查找更新后a[i][j]属于的i行或者j列是不是只有一个元素未知
					if(a[x][i]==-1&&(cntr[x]==n-1||cntc[i]==n-1))q.push((x-1)*n+i);
				}
		}
	for(int i=1; i<=n; ++i)if(cntr[i]!=n||cntc[i]!=n)
			{
				cout<<-1<<endl;
				return;
			}
	for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)
			{
				cout<<a[i][j]<<" \n"[j==n];
			}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

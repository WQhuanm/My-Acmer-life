#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e2 + 10;

int dis[N][N];
bool sex[N];//标记性别，0为男，1为女

int main()
{
	int n,k,x,d;
	char c;
	cin>>n;
	memset(dis,0x3f,sizeof(dis));//初始无穷大
	for (int i=1; i<=n; ++i)
	{
		cin>>c>>k;
		if (c=='F')sex[i]=1;
		else sex[i]=0;
		while (k--)
		{
			cin>>x>>c>>d;
			dis[i][x]=min(d,dis[i][x]);
		}
	}
	//floyd
	for (int k=1; k<=n; ++k)for (int i=1; i<=n; ++i)for (int j=1; j<=n; ++j)if (i!=j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	vector<int>f,m;
	int fd=INF,md=INF;//大众情人的离他最远异性距离
	for (int i=1; i<=n; ++i)
	{
		int maxn=0;//记录离i最远的异性
		for (int j=1; j<=n; ++j)
		{
			if (sex[i]^sex[j]) //异或为真，性别不同
			{
				maxn=max(maxn,dis[j][i]);//j到i的距离（不是i到j，是其他人对i）
			}
		}
		if (sex[i])//女性
		{
			if (maxn<fd)
			{
				fd=maxn;
				f.clear();
				f.push_back(i);
			}
			else if (maxn==fd)f.push_back(i);
		}
		else
		{
			if (maxn<md)
			{
				md=maxn;
				m.clear();
				m.push_back(i);
			}
			else if (maxn==md)m.push_back(i);
		}
	}
	for (int i=0; i<(int)f.size(); ++i)
	{
		cout<<f[i];
		if (i==(int)f.size()-1)cout<<endl;
		else cout<<' ';
	}
	for (int i=0; i<(int)m.size(); ++i)
	{
		cout<<m[i];
		if (i==(int)m.size()-1)cout<<endl;
		else cout<<' ';
	}
	return 0;
}


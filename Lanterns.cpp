#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const double eps=1e-9;
const int N = 110;
bitset<N>b;
vector< bitset<N> >a(N);
int n,m;
void print()//打印看目前情况
{
	cout<<endl;
	for(int i=1; i<=n; ++i)for(int j=1; j<=m+1; ++j)cout<<a[i][j]<<" \n"[j==m+1];
	cout<<endl;
}
void gauss(vector<bitset<N>>a)
{
	int r=1;
	for(int i=1; r<=n&&i<=m; ++i)
		{
			//print();
			int mx=r;
			for(int j=r+1; j<=n; ++j)if(a[j][i]>a[mx][i])mx=j;
			if(!a[mx][i])continue;//主元为0，跳过
			if(mx!=r)swap(a[mx],a[r]);
			for(int j=1; j<=n; ++j)if(j!=r)
					{
						if(a[j][i]==a[r][i])a[j]^=a[r];//只有j行在第i个位置的ai是1，才需要异或消去为0，否则无需操作
					}
			r++;
		}
	//print();
	int ans=1;
	for(int i=r; i<=n; ++i)//无解
		if(a[i][m+1])
			{
				cout<<0<<endl;
				return;
			}
	for(int i=r; i<=m; ++i)ans*=2;//自由元个数x，答案是2^x
	cout<<ans<<endl;
}
int tt=0;
void mysolve()
{
	int k,x;
	cin>>n>>m;
	for(int i=1; i<=n; ++i)a[i].reset();
	for(int i=1; i<=m; ++i)
		{
			cin>>k;
			while(k--)cin>>x,a[x].set(i);
		}
	int q;
	cin>>q;
	cout<<"Case "<<++tt<<":"<<endl;
	while(q--)
		{
			for(int i=1; i<=n; ++i)cin>>x,a[i][m+1]=x;
			gauss(a);//传入原始矩阵，避免原始矩阵被替换，
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

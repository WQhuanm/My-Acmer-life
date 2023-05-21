#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const double eps=1e-9;
const int N = 2e3 + 10;
vector<bitset<N>>a(N);
int n,m,ans[N],k;
bool flag;

bool gauss(vector<bitset<N>>a,int t)
{
	int r=1;
	for(int i=1; i<=m&&r<=t; ++i)
		{
			int mx=r;
			for(int j=r+1; j<=t; ++j)if(a[j][i]>a[mx][i])mx=j;
			if(!a[mx][i])continue;
			if(mx!=r)swap(a[mx],a[r]);
			for(int j=1; j<=t; ++j)if(j!=r&&a[r][i]==a[j][i])a[j]^=a[r];
			r++;
		}
	if(r<=m)return 0;
	else
		{
			for(int i=1; i<=m; ++i)ans[i]=a[i][m+1];
			return flag=1;
		}
}
void mysolve()
{
	cin>>m>>n;
	int x;
	string s;
	for(int i=1; i<=n; ++i)
		{
			cin>>s;
			for(int j=0; j<m; ++j)a[i][j+1]=s[j]-'0';
			cin>>x;
			a[i][m+1]=x;
		}
	int l=1,r=n;
	while(l<=r)
		{
			int mid=l+((r-l)>>1);
			if(gauss(a,mid))k=mid,r=mid-1;
			else l=mid+1;
		}
	if(flag)
		{
			cout<<k<<endl;
			for(int i=1; i<=m; ++i)
				{
					if(ans[i])cout<<"?y7M#"<<endl;
					else cout<<"Earth"<<endl;
				}
		}
	else cout<<"Cannot Determine"<<endl;

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

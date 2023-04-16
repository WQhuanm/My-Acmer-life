#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e3 + 10;
int a[N];
void mysolve()
{
	int n;
	cin>>n;
	int p1=1,p2=n;
	for(int i=1; i<=n; i+=2)a[i]=p1++,a[i+1]=p2--;//构造链
	int x;
	char c='+';
	cout<<c<<" "<<n+1<<endl;
	cin>>x;
	cout<<c<<" "<<n+2<<endl;
	cin>>x;
	int k=1,p=0;
	c='?';
	for(int i=2; i<=n; ++i)
		{
			cout<<c<<" "<<1<<' '<<i<<endl;
			cin>>x;
			if(x>p)p=x,k=i;//找到端点k
		}
	vector<int>ans1(n+1),ans2(n+1);
	ans1[k]=a[1],ans2[k]=a[n];
	for(int i=1; i<=n; ++i)if(i!=k)
			{
				cout<<c<<" "<<k<<" "<<i<<endl;
				cin>>x;
				ans1[i]=a[1+x];//分别找出k在不同端点形成的序列
				ans2[i]=a[n-x];
			}
	cout<<"!";
	for(int i=1; i<=n; ++i)cout<<" "<<ans1[i];
	for(int i=1; i<=n; ++i)cout<<" "<<ans2[i];
	cout<<endl;
	cin>>x;
}

int32_t main()
{
	//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
//	system("pause");
	return 0;
}

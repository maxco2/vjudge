#include<bits/stdc++.h>
using namespace std;
int n;
void solve();
int main()
{

	ios::sync_with_stdio(false);
	while((cin>>n)&&(n!=0))
	{
		solve();
	}
	return 0;
}
std::vector<pair<int,int>> s;
int sum;
bool isconf(int x,int y)
{
	for(auto& i:s)
	{
		if(x==i.first)
			return true;
		else if(y==i.second)
			return true;
		else if(fabs(x-i.first)==fabs(y-i.second))
			return true;
	}
	return false;
}
map<int,int> dp;
void dfs(int lev)
{
	if(lev==n) {sum+=1;return;}
	for(int y=0;y<n;++y)
		if(!isconf(lev,y))
		{
			s.push_back(make_pair(lev,y));
			dfs(lev+1);
			s.pop_back();
		}
}
void solve()
{
	if(dp.find(n)!=dp.end()) {cout<<dp[n]<<endl;return;}
	sum=0;
	s.clear();
	dfs(0);
	dp[n]=sum;
	cout<<sum<<endl;
}

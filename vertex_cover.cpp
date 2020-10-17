#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 5;

vector<int> gr[N];
int dp[N][2];

void dfs(int curr, int parent)
{
	dp[curr][0] = 0;
	dp[curr][1] = 1;

	for (int x : gr[curr])
	{
		if (x != parent)
		{
			dfs(x, curr);
			dp[curr][0] += dp[x][1];
			dp[curr][1] += min(dp[x][0], dp[x][1]);
		}
	}
}

void solve()
{
	int n; cin >> n;
	int x, y;
	for (int i = 0 ; i < n - 1; i++)
	{
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	dfs(1, 0);

	cout << min(dp[1][0], dp[1][1]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    w(T)
	{
		solve();
	}
	return 0;
}
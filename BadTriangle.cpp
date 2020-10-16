    #include <bits/stdc++.h>
    #include <cmath>
    using namespace std;
    #define int long long
    #define endl "\n"
    const int MOD = 1e9+7;
    int max(int x, int y)
    {
        return (x>y)?x:y;
    }
    // std::vector<pair<int,int> unecces;
    void dfs(int u, vector<int> adj[], 
        vector<bool> &visited) {
        visited[u] = true;
        for (int v : adj[u])
        {
            if(!visited[v])
                dfs(v,adj,visited);
        }
    }
     
    int gcd(int a, int b)
    {
        if(a==0)
            return b;
        else
            return gcd(b%a,a);
    }
     
    int32_t main()
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
        #endif
        
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
     
        int t;
        cin >> t;
        
        while(t--)
        {
            int n;
            cin >> n;
            int a[n];
            for(int i=0;i<n;i++)
            {
                cin >> a[i];
     
            }
            int i = 0;
            int j = 1;
            int k = n-1;
            if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i])
                cout << -1 << endl;
            else
                cout << i+1 << " " << j+1 << " " << k+1 << endl;
        }
        return 0;
    }

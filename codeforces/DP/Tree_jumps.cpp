// MUST try


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <numeric>
#include <cstddef>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define ll long long
#define ar array
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define int long long

const int M = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        vector<vector<int>> levels(n);
        vector<int> depth(n), parent(n);
        vector<int> adj[n];
        vector<int> dp(n);
        depth[0] = parent[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            cin >> parent[i];
            --parent[i];
            adj[parent[i]].push_back(i);
            depth[i] = depth[parent[i]] + 1;
            levels[depth[i]].push_back(i);
        }
        for (int i = n - 1; i > 0; --i)
        {
            if (levels[i].empty())
                continue;
            int s = 0;
            for (auto it : levels[i])
            {
                dp[it] = (sum + 1) % M;
                for (auto u : adj[it])
                {
                    dp[it] -= dp[u];
                    dp[it] = (dp[it] % M + M) % M;
                }
                s += dp[it];
            }
            sum = s;
        }

        cout << (sum + 1) % M << endl;
    }

    return 0;
}
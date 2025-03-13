// dfs + binary search

const int mxN = 2e5 + 5;
vector<int> g[mxN];
int a[mxN], b[mxN];
int ans[mxN];
int pref_a, pref_b;
vector<int> prefix;

void dfs(int x)
{
    pref_a += a[x];
    pref_b += b[x];
    prefix.push_back(pref_b);
    ans[x] = upper_bound(prefix.begin(), prefix.end(), pref_a) - prefix.begin();
    for (auto ch : g[x])
    {
        dfs(ch);
    }
    pref_a -= a[x];
    pref_b -= b[x];
    prefix.pop_back();
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, p, ax, bx;
        cin >> n;
        for (int i = 0; i < n; ++i)
            g[i].clear();

        for (int i = 1; i < n; ++i)
        {
            cin >> p >> ax >> bx;
            --p;
            g[p].push_back(i);
            a[i] = ax, b[i] = bx;
        }
        dfs(0);
        for (int i = 1; i < n; ++i)
        {
            cout << ans[i] - 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}

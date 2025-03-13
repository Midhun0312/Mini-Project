// Polycarp was gifted an array 𝑎
//  of length 𝑛
// . Polycarp considers an array beautiful if there exists a number 𝐶
// , such that each number in the array occurs either zero or 𝐶
//  times. Polycarp wants to remove some elements from the array 𝑎
//  to make it beautiful.

// For example, if 𝑛=6
//  and 𝑎=[1,3,2,1,4,2]
// , then the following options are possible to make the array 𝑎
//  array beautiful:

// Polycarp removes elements at positions 2
//  and 5
// , array 𝑎
//  becomes equal to [1,2,1,2]
// ;
// Polycarp removes elements at positions 1
//  and 6
// , array 𝑎
//  becomes equal to [3,2,1,4]
// ;
// Polycarp removes elements at positions 1,2
//  and 6
// , array 𝑎
//  becomes equal to [2,1,4]
// ;
// Help Polycarp determine the minimum number of elements to remove from the array 𝑎
//  to make it beautiful.

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
        int x;
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            mp[x]++;
        }
        vector<int> v;
        for (auto x : mp)
            v.push_back(x.second);
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        for (int i = 0; i < v.size(); ++i)
        {
            ans = min(ans, n - v[i] * static_cast<int>(v.size() - i));
        }
        cout << ans << endl;
    }

    return 0;
}
// Planet Lapituletti
// Clocks display time in a format HH:MM
//  Hours are numbered from 0 to ℎ−1 and minutes are numbered from 0 to 𝑚−1.
// An inhabitant of the planet Lapituletti begins to look at a mirrored image of the clocks at some time moment 𝑠
//  and wants to know the nearest future time moment (which can possibly happen on the next day), when the reflected clock time is valid.

//  input
//  5
// 24 60
// 12:21
// 24 60
// 23:59
// 90 80
// 52:26
// 1 100
// 00:01
// 10 10
// 04:04

// output
// 12:21
// 00:00
// 52:28
// 00:00
// 00:00

// Note
// In the second test case it is not hard to show that the reflection of 23:59 is incorrect, while the reflection of the moment 00:00 on the next day is correct.

int hh, mm;
vector<int> valid = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int mirror(int n)
{
    string p = to_string(n);
    string ans = "";
    if (p.size() == 1)
        p = '0' + p;
    for (int i = 1; i >= 0; --i)
    {
        if (valid[p[i] - '0'] == -1)
            return 1e9;
        ans += char(valid[p[i] - '0'] + '0');
    }
    return stoi(ans);
}

string opti(int x)
{
    string ans = to_string(x);
    if (x < 10)
    {
        ans = '0' + ans;
    }
    return ans;
}

int main()
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
        cin >> hh >> mm;
        string s;
        cin >> s;

        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        while (1)
        {
            if (m == mm)
            {
                h++;
                m = 0;
            }
            if (h == hh)
            {
                h = 0;
            }
            if (mirror(m) < hh && mirror(h) < mm)
            {
                cout << opti(h) << ":" << opti(m) << endl;
                break;
            }
            m++;
        }
    }
    return 0;
}

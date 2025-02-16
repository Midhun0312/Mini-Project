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
using namespace std;
 
#define ll long long
#define ar array
#define pii pair<int,int> 
#define f first
#define s second
#define pb push_back
 

 
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("io/input.txt", "r", stdin);
        freopen("io/output.txt", "w", stdout);
        freopen("io/error.txt", "w", stderr);
    #endif
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i<n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        vector<pair<int,int>> rep;
        int flag = 1;
        for(int i = 1; i<n; ++i){
            if(v[i] == rep.back().first) rep.back().second++;
            if(v[i] == v[i-1]) rep.pb({v[i], 0});
        }
        for(int i = 0; i<rep.size(); ++i) {
            int a = rep[i].first;
            int freq = rep[i].second;
            if(freq == 4) {
                cout << a << " " << a << " " << a <<  " " << a << endl;
                flag = 0;
                break;
            }
            for(int i = 0; i<n; ++i) {
                if(freq > 2  && a == v[i]){
                    if(upper_bound(v.begin() , v.end() , a) != v.end())
                }
            }
        }
        if(flag)
        cout << -1 << endl;
    }


    return 0;
}
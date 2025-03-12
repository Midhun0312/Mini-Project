// given an array 𝑎 of length 𝑛. He needed to minimize the number of inversions∗ in the array after applying the spell exactly once.The spell was simple;
// to apply it, Akito had to choose two numbers 𝑙 and 𝑟 such that 1≤𝑙≤𝑟≤𝑛 and perform a cyclic shift of the subarray from 𝑙 to 𝑟
//  one position to the left.
// Copy
// input :

// 4
// 7
// 1 4 3 2 5 3 3
// 6
// 1 4 3 2 5 3
// 8
// 7 6 5 8 4 3 2 1
// 10
// 1 1 1 5 1 1 5 6 7 8

// output :

// 2 7
// 2 4
// 1 8
// 4 6

// In the first example, the array [1,4,3,2,5,3,3]
//  will turn into the array [1,3,2,5,3,3,4]
// . The inversions in it are (2,3)
// , (4,5)
// , (4,6)
//  and (4,7)
// . It can be shown that it is not possible to achieve fewer than 4
//  inversions.

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
        freopen("../../io/input.txt", "r", stdin);
        freopen("../../io/output.txt", "w", stdout);
        freopen("../../io/error.txt", "w", stderr);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int l, r;
        int ans = 0, flag = 1;
        for (int i = 0; i < n; ++i)
        {
            int del = 0;
            for (int j = i; j < n; ++j)
            {
                if (arr[i] > arr[j])
                {
                    del--;
                    if (ans > del)
                    {
                        ans = del;
                        l = i + 1, r = j + 1;
                        flag = 0;
                    }
                }
                else if (arr[i] < arr[j])
                {
                    del++;
                }
            }
        }
        if(flag) l = 1 , r = 1;
        cout << l << " " << r << endl;
    }


    return 0;
}
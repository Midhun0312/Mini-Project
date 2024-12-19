// You are given an integer array arr of length n that represents a permutation of the integers
// in the range[0, n - 1]. We split arr into some number of chunks(i.e., partitions),
// and individually sort each chunk.After concatenating them, the result should equal the sorted array.
//  Return the largest number of chunks we can make to sort the array.
// Input : arr = [ 1, 0, 2, 3, 4 ] Output : 4
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    int max_ele = -1;
    int ct = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        max_ele = max(max_ele, arr[i]);
        if (i == max_ele)
            ct++;
    }
    return ct;
}
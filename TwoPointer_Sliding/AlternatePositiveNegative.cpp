// Time complexity : O(n)
// Space Complexity : O(n)

vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(n,0);
        int indexpos = 0, indexneg=1;
        for(auto num: nums){
            if(num>0){
                ans[indexpos] = num;
                indexpos+=2;
            }
            if(num<0){
                ans[indexneg] = num;
                indexneg += 2;
            }
        }
        return ans;
        
    }

// Type 2 : if the no. of elements are not equal
//  - brute solution .  store +ve in one array and -ve in another array and then merge them
#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int idx = n-1;
        vector<int> ans(n);
        while(l <= r){
            if(abs(nums[l]) > abs(nums[r])){
                ans[idx] = nums[l] * nums[l];
                l++;
            }else{
                ans[idx] = nums[r] * nums[r];
                r--;
            }
            idx--;
        }
        return ans;
    }
};

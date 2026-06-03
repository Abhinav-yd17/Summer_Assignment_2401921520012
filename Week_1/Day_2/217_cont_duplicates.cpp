#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> hset;
        
        for(int idx = 0; idx < nums.size(); idx++) {
            
            if(hset.count(nums[idx]))
                return true;
           
            hset.insert(nums[idx]);
        }
        return false;
    }
};
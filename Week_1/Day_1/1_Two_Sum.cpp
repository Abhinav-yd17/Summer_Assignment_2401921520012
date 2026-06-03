#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> track;

        for(int i=0;i<nums.size();i++){
            int x = target - nums[i];

            if(track.count(x))
                return {track[x], i};

            track[nums[i]] = i;
        }

        return {};
    }
};
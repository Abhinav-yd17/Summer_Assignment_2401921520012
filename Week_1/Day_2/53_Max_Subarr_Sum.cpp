#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxsum = INT_MIN;
       int sum = 0 ;
       if(nums.size()==1){
        return nums[0];
       }
       for(int i = 0 ; i < nums.size(); i ++){
        sum = sum + nums[i];
         maxsum = max(maxsum , sum);
         if(sum < 0 ){
            sum = 0 ;
        }
         }

       return maxsum ; 
    }
};
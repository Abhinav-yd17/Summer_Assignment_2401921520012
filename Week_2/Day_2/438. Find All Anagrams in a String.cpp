#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) return ans;  
        unordered_map<char,int> mpp;
        for (char c : p) mpp[c]++;
        int l = 0, r = 0, k = p.size(), count = mpp.size();
        while (r < s.size()) {
            if (mpp.find(s[r]) != mpp.end()) {
                mpp[s[r]]--;
                if (mpp[s[r]] == 0) count--;
            }
            if (r - l + 1 < k) {
                r++;
            }
            else if (r - l + 1 == k) {
                if (count == 0) ans.push_back(l);
                if (mpp.find(s[l]) != mpp.end()) {
                    if (mpp[s[l]] == 0) count++;
                    mpp[s[l]]++;
                }
                l++;
                r++;
            }
        }
        return ans;
    }
};
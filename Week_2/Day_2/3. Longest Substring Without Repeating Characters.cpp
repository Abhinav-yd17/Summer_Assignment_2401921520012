#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int l = 0, r = 0;
        int maxLen = 0;
        int n = s.length();
        while(r < n) {
            if(hash.find(s[r]) != hash.end()) {
                if(hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
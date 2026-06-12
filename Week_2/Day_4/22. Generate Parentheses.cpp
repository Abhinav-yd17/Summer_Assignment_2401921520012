#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    void solve(string s, int open, int close, vector<string> &ans) {
        
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        if (open == close) {
            string s1 = s;
            s1.push_back('(');
            solve(s1, open - 1, close, ans);
        }

        else if (open == 0) {
            string s1 = s;
            s1.push_back(')');
            solve(s1, open, close - 1, ans);
        }

        else if (close == 0) {
            string s1 = s;
            s1.push_back('(');
            solve(s1, open - 1, close, ans);
        }

        else {
            string s1 = s;
            string s2 = s;

            s1.push_back('(');
            s2.push_back(')');

            solve(s1, open - 1, close, ans);
            solve(s2, open, close - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n, n, ans);  
        return ans;
    }
};

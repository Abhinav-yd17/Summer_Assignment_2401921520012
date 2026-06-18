#include <bits/stdc++.h>
using namespace std;
class Solution {
public:    
    vector<int> findPSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> pse(n);
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }  
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> findNSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nse(n);
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> pse = findPSE(heights, n);
        vector<int> nse = findNSE(heights, n);
        
        int maxi = 0; 
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }   
        return maxi;
    }
};
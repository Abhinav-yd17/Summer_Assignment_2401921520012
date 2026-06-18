#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else if (val >= mini) {
            st.push(val);
        } else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }
    void pop() {
        long long x = st.top();
        st.pop();
        if (x < mini) {
            mini = 2LL * mini - x;
        }
    }
    int top() {
        long long x = st.top();
        if (x >= mini) return x;
        return mini;
    }
    int getMin() {
        return mini;
    }
};

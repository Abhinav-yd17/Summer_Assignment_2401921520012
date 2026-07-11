#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) 
        {
            while (curr != nullptr)
             {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            // Move to right subtree
            curr = curr->right;
        }
        return result;
    }
};
int main() 
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);
    cout << "Inorder Traversal: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
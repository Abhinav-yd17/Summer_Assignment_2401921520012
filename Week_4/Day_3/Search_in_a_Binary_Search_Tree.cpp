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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val == val) return root;
            else if (val < root->val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}
int main() 
{
    vector<int> values = {4,21,71,12,34};
    TreeNode* root = nullptr ;
    for (int v : values) root = insertBST(root, v)  ;
    int target = 2 ;
    Solution sol;
    TreeNode* result = sol.searchBST(root, target);
    if (result) {
        cout << "Found node with value: " << result->val << endl;
    }
     else {
        cout << "Value not found in BST." << endl;
    }
    return 0;
}

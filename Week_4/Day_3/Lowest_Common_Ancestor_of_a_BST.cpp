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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) 
        {
            if (p->val < root->val && q->val < root->val) {
                root = root->left ;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right ;
            }
             else 
            {
                return root ;
            }
        }
        return nullptr;
    }
};
TreeNode* insertBST(TreeNode* root, int val) 
{
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root ;
}
int main() 
{
    vector<int> values = {6,24,81,8,47,73,92,31,45};
    TreeNode* root = nullptr;
    for (int v : values) root = insertBST(root, v);
    TreeNode* p = root->left ;
    TreeNode* q = root->right;      
    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val 
         << " is: " << lca->val << endl;

    return 0;
}
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
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) 
            {
                root = root->left ;
            } 
            else if (p->val > root->val && q->val > root->val) 
            {
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
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}
TreeNode* findNode(TreeNode* root, int val) 
{
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    return findNode(root->right, val);
}
int main() 
{
    vector<int> values = {6,22,18,80,48,74,97,37,52};
    TreeNode* root = nullptr;
    for (int v : values) root = insertBST(root, v);
    TreeNode* p = findNode(root, 2); //
}
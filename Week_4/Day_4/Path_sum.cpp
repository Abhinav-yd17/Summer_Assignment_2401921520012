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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(51);
    root->left = new TreeNode(41);
    root->right = new TreeNode(81);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}
int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();
    int targetSum = 22;
    if (sol.hasPathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists!" << endl;
    } else {
        cout << "No path with sum " << targetSum << " found." << endl;
    }

    return 0;
}
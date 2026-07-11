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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
private:
    int maxGain(TreeNode* node, int &maxSum) {
        if (!node) return 0;
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);
        int currentPath = node->val + leftGain + rightGain ;
        maxSum = max(maxSum, currentPath);
        return node->val + max(leftGain, rightGain);
    }
};
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
   return root;
}
int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();
    cout << "Maximum Path Sum: " 
         << sol.maxPathSum(root) << endl; 
    return 0;
}
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int &diameter) {
        if (!node) return 0;
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(42);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(41);
    root->left->right = new TreeNode(5);
    return root;
}
int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();
    cout << "Diameter of Binary Tree: " 
         << sol.diameterOfBinaryTree(root) << endl; 
    return 0;
}
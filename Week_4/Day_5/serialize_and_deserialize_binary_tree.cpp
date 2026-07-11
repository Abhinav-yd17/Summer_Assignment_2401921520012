#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> inorderIndex; // map value -> index for quick lookup
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // store inorder indices for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        
        // pick current root from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // find root in inorder
        int inIndex = inorderIndex[rootVal];
        
        // recursively build left and right subtrees
        root->left = build(preorder, inorder, preIndex, inStart, inIndex - 1);
        root->right = build(preorder, inorder, preIndex, inIndex + 1, inEnd);
        
        return root;
    }
};

// Helper function: print inorder traversal of constructed tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper function: print preorder traversal of constructed tree
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution sol;
    
    // Example input
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    
    TreeNode* root = sol.buildTree(preorder, inorder);
    
    cout << "Constructed Tree Inorder: ";
    printInorder(root);
    cout << endl;
    
    cout << "Constructed Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    unordered_map<int, int> inorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) 
    {
        if (inStart > inEnd) return NULL;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);        
        int inIndex = inorderIndex[rootVal];
        root->left = build(preorder, inorder, preIndex, inStart, inIndex - 1);
        root->right = build(preorder, inorder, preIndex, inIndex + 1, inEnd); 
        return root;
    }
};
void printInorder(TreeNode* root) 
{
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main() {
    Solution sol;
    vector<int> preorder = {3,9,20,14,71};
    vector<int> inorder = {9,3,15,20,71};
    TreeNode* root = sol.buildTree(preorder, inorder);
    cout << "Constructed Tree Inorder: " ;
    printInorder(root);
    cout << endl; 
    cout << "Constructed Tree Preorder: " ;
    printPreorder(root);
    cout << endl;
    return 0;
}
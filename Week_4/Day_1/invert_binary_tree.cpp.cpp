#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root == nullptr) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
void printTree(TreeNode* root) 
{
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
int main() 
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2) ;
    root->right = new TreeNode(7) ;
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3) ;
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(10) ;
    Solution sol ;    
    TreeNode* inverted = sol.invertTree(root);
    cout << "Inverted Tree (Preorder): "  ;
    printTree(inverted) ;
    return 0;
}
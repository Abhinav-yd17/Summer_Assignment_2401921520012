#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* t1, TreeNode* t2) 
    {
        if (!t1 && !t2) return true ;
        if (!t1 || !t2) return false ;
        return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right) 
            && isMirror(t1->right, t2->left)  ;
    }
};

TreeNode* buildSymmetricTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    return root;
}
TreeNode* buildNonSymmetricTree() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(13);
    root->right->right = new TreeNode(13);
    return root;
}
int main()                                                                
{
    Solution sol;
    TreeNode* symmetricRoot = buildSymmetricTree();
    cout << "Symmetric Tree: " << (sol.isSymmetric(symmetricRoot) ? "True" : "False") << endl;
    TreeNode* nonSymmetricRoot = buildNonSymmetricTree();
    cout << "Non-Symmetric Tree: " << (sol.isSymmetric(nonSymmetricRoot) ? "True" : "False") << endl;
    return 0;
}
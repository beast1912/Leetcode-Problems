/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mini_dist = INT_MAX;
    TreeNode* prev = NULL;
    
    void inorder_traversal(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder_traversal(root->left);
        if(prev != NULL)
        {
            mini_dist = min(mini_dist,root->val - prev->val);
            
        }
        prev = root;
        inorder_traversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder_traversal(root);
        return mini_dist;
    }
};
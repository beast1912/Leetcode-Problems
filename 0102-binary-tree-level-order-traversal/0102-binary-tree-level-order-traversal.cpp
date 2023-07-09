/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> levelOrder(TreeNode *root)
        {
            if(root == NULL)
                return {};
            vector<vector < int>> ans;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                vector<int> nodes;
                int n = q.size();
                for (int i = 0; i < n; i++)
                {
                    TreeNode *temp = q.front();
                    if (temp->left!=NULL)
                        q.push(temp->left);
                    if (temp->right!=NULL)
                        q.push(temp->right);
                    nodes.push_back(temp->val);
                    q.pop();
                }
                ans.push_back(nodes);
            }
            return ans;
        }
};
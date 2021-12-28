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
    void binaryToTreePath(TreeNode* root, vector<string>& res, string s)
    {   
        if(root->left == nullptr && root->right == nullptr)
        {
            res.push_back(s); 
            return; 
        }
        
        if(root->left)
        {
            binaryToTreePath(root->left, res, s + "->" + to_string(root->left->val));
        }        
        
        if(root->right)
        {
            binaryToTreePath(root->right, res, s + "->" + to_string(root->right->val));
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        
        if(root == nullptr)
        {
            return res; 
        }
        
        binaryToTreePath(root, res, to_string(root->val)); 
        
        return res; 
    }
};
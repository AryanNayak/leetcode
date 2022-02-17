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
    int idx = 0; 
    TreeNode* buildTree(int start, int end, vector<int>& inorder, vector<int>& preorder)
    {
        
        if(start > end)
        {
            return nullptr; 
        }
        
        TreeNode* root = new TreeNode(preorder[idx++]); 
        
        int inIdx ; 
        
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == root->val)
            {
               inIdx = i; 
                break; 
            }
        }
        
        
        root->left = buildTree(start, inIdx - 1, inorder, preorder); 
        root->right = buildTree(inIdx + 1, end, inorder, preorder);         
        
        return root; 
    }    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size(); 
        
        return buildTree(0, n - 1, inorder, preorder); 
        
    }
};
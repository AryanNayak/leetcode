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
    int goodNode = 0; 
    
    void preorder(TreeNode* root, int maxValueSoFar)
    {
        if(root == nullptr)
            return ; 
        
        if(root->val >= maxValueSoFar)
        {
            goodNode++; 
        }
        
        preorder(root->left, max(root->val, maxValueSoFar)); 
        preorder(root->right, max(root->val, maxValueSoFar));         
        
        
                
    }

    
    int goodNodes(TreeNode* root) {
       
        preorder(root, INT_MIN);     
        
        return goodNode; 
        
    }
};
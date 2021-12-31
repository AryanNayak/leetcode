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
    TreeNode* getRightMostNode(TreeNode* node, TreeNode* curr)
    {
        while(node->right != nullptr && node->right != curr)
        {
            node = node->right; 
        }
        return node; 
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = -1; 
        
        TreeNode* curr = root; 
        
        while(curr != nullptr)
        {
            TreeNode* left = curr->left; 

            if(left == nullptr)
            {
                if(--k == 0)
                {
                    ans = curr->val; 
                }
                curr = curr->right; 
            }
            else
            {
                TreeNode* rightMostNode = getRightMostNode(left, curr); 
                
                if(rightMostNode->right == nullptr)
                {
                    rightMostNode->right = curr; 
                    curr = curr->left; 
                }
                else
                {
                    rightMostNode->right = nullptr; 
                    if(--k == 0)
                        ans = curr->val;
                    curr = curr->right; 
                }
            }
        }
        return ans; 
    }
};
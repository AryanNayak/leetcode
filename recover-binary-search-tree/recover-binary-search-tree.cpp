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
    
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root; 
        TreeNode* prev = nullptr;
        TreeNode* a = nullptr; 
        TreeNode* b = nullptr; 
        
        while(curr != nullptr)
        {
            
            TreeNode* left = curr->left; 
            
            if(left == nullptr)
            {
                if(prev != nullptr && prev->val > curr->val)
                {
                    if(a == nullptr)
                    {
                        a = prev; 
                    }
                    b = curr; 
                }
                
                prev = curr; 
                
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
                    
                    if(prev != nullptr && prev->val > curr->val)
                    {
                        if(a == nullptr)
                        {
                            a = prev; 
                        }
                        b = curr; 
                    }
                    prev = curr; 
                    curr = curr->right; 
                }
            }
        }
        
        if(a != nullptr)
        {
            int temp = a->val; 
            a->val = b->val; 
            b->val = temp; 
        }
        
        
    }
};
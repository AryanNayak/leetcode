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
    
    TreeNode* getlca(TreeNode* root, int p, int q)
    {
        
        if(root == nullptr)
            return nullptr; 
        
        
        if(root->val == p || root->val == q)
        {
            return root; 
        }
        
        
        TreeNode* lca1 = getlca(root->left, p, q); 
        TreeNode* lca2 = getlca(root->right, p, q); 
        
        if(lca1 != nullptr && lca2 != nullptr)
        {
            return root; 
        }
        
        if(lca1 == nullptr)
        {
            return lca2; 
        }
        else if(lca2 == nullptr)
        {
            return lca1; 
        }
        
        return root; 
    }
    bool traverse(TreeNode* root, string& lca_string, int val)
    {
        if(root == nullptr)
        {
            return false; 
        }
        
        if(root->val == val)
        {
            return true;
        }
        
        lca_string.push_back('L'); 
        
        if(traverse(root->left, lca_string, val))
        {
            return true; 
        }
        
        lca_string.pop_back(); 
        
        
        lca_string.push_back('R'); 
        if(traverse(root->right, lca_string, val))
        {
            return true; 
        }
        lca_string.pop_back(); 
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
     
        TreeNode* lca = getlca(root, startValue, destValue); 
        
        string lca_start = "", lca_dest = ""; 
        
        traverse(lca, lca_start, startValue);
        traverse(lca, lca_dest, destValue); 
        
        for(auto& c : lca_start)
        {
            c = 'U';
        }
        
        return lca_start + lca_dest; 
    }
};
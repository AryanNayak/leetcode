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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>> ans;
        
        if(root == nullptr)
            return ans; 
        
        
        queue<TreeNode*> q; 
        
        q.push(root); 
        
        
        while(q.empty() == false)
        {
  
            int count = q.size(); 
            
            vector<int> res; 
            for(int i = 0; i < count; i++)
            {
                
                TreeNode* curr = q.front(); 
                q.pop(); 
                
                
                res.push_back(curr->val); 
                
                if(curr->left != nullptr)
                    q.push(curr->left); 
                
                if(curr->right != nullptr)
                    q.push(curr->right); 
                
        
            }
            
            ans.push_back(res); 
    
        }
            
        return ans;     
        
    }
};
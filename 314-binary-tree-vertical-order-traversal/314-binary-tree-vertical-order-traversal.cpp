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
    vector<vector<int>> verticalOrder(TreeNode* root) {
       
        if(root == nullptr)
            return {}; 
        
        map<int, vector<int>> mp; 
    
        queue<pair<int, TreeNode* >> q; 
        
        vector<vector<int>> res; 
        
        q.push({0, root}); 
        
        while(!q.empty())
        {
            
            auto p = q.front(); 
            q.pop(); 
            
            mp[p.first].push_back(p.second->val); 
            
            if(p.second->left != nullptr)
            {
                q.push({p.first-1, p.second->left}); 
            }
            
            if(p.second->right != nullptr)
            {
                q.push({p.first + 1, p.second->right}); 
            }
            
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            res.push_back(it->second); 
        }
        
        return res; 
    }
};
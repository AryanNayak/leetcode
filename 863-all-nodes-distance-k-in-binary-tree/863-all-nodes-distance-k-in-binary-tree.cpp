/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool nodeToRootPath(TreeNode* root, int data, vector<TreeNode*>& path)
    {
        if(root == nullptr)
            return false; 
        
        if(root->val == data)
        {
            
            path.push_back(root); 
            return true; 
        }
    
        bool res = nodeToRootPath(root->left, data, path) || nodeToRootPath(root->right, data, path); 
        
        if(res)
            path.push_back(root); 
        return res;
        
    }
    void kdown(TreeNode* root, int k, TreeNode* block, vector<int>& ans)
    {
     
        if(root == nullptr || k < 0 || root == block)
            return; 
        
        
        if(k == 0)
        {
            ans.push_back(root->val); 
            return; 
        }
        
        
        kdown(root->left, k - 1, block, ans); 
        kdown(root->right, k - 1, block, ans); 
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      
        vector<TreeNode*> path; 
        
        nodeToRootPath(root, target->val, path); 
        
        for(auto e : path)
        {
            cout << e->val << endl; 
        }
        
        vector<int> ans; 
        
        TreeNode* block = nullptr; 
        
        for(int i = 0; i < path.size(); i++)
        {
            kdown(path[i], k - i, block, ans); 
            block = path[i]; 
        }
        
        return ans; 
        
    }
};
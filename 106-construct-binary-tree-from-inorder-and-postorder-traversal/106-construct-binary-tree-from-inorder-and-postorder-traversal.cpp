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
    TreeNode* buildTree(int isi, int iei, vector<int>& inorder, int psi, int pei, vector<int>& postorder)
    {
        if(psi > pei)
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[pei]); 
        
        int idx = isi; 
        
        while(inorder[idx] != postorder[pei])
        {
            idx++; 
        }
        
        int tel = idx - isi; 
        
        
        root->left = buildTree(isi, idx - 1, inorder, psi, psi + tel - 1, postorder); 
        root->right = buildTree(idx + 1, iei, inorder, psi + tel, pei - 1, postorder); 
        
        return root; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n  = inorder.size(); 
        
        return buildTree(0, n - 1, inorder, 0, n - 1, postorder); 
        
    }
};
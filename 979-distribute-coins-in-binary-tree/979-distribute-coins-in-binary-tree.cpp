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
    int postOrder(TreeNode* root, int& moves)
    {   
        
        if(root == nullptr)
        {
            return 0; 
        }
        
        int leftExcess = postOrder(root->left, moves);         
        
        int rightExcess = postOrder(root->right, moves); 
        
        moves += abs(leftExcess) + abs(rightExcess); 
        
        return (root->val - 1) + leftExcess + rightExcess; 
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0; 
        postOrder(root, moves); 
        return moves;
    }
};
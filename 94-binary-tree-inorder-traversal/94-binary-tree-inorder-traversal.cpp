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

TreeNode *getRightMostNode(TreeNode *node, TreeNode *curr)
{
    while (node->right != nullptr && node->right != curr)
    {
        node = node->right;
    }

    return node;
}

vector<int> inorderTraversal(TreeNode *root)
{
    TreeNode *curr = root;  
    vector<int> arr; 
    while (curr != nullptr)
    {
        TreeNode *left = curr->left;
        if (left == nullptr)
        {

            arr.push_back(curr->val); 
            curr = curr->right;
        }
        else
        {
            TreeNode *rightMostNode = getRightMostNode(left, curr);
            if (rightMostNode->right == nullptr)
            {                                // thread creation block
                rightMostNode->right = curr; // thread is created

                curr = curr->left;
            }
            else
            {                                   // thread destroy block
                rightMostNode->right = nullptr; // thread is cut down

                arr.push_back(curr->val); 

                curr = curr->right;
            }
        }
    }

    return arr;
}

};
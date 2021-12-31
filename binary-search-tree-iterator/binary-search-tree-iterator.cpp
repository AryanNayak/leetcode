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
class BSTIterator {
private: 
    TreeNode* curr = nullptr; 
public:
    BSTIterator(TreeNode* root) {
        curr = root; 
    }
    
    TreeNode* getRightMostNode(TreeNode* node, TreeNode* curr)
    {
        while(node->right != nullptr && node->right != curr)
        {
            node = node->right; 
        }
        
        return node; 
    }
    int next() {
        int nextNode = -1; 
        while(curr != nullptr)
        {
            TreeNode* left = curr->left; 
            
            if(left == nullptr)
            {
                nextNode = curr->val; 
                curr = curr->right; 
                break; 
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
                    
                    nextNode = curr->val; 
                    curr = curr->right; 
                    
                    break;
                }   
            }    
        }
     
        return nextNode; 
           
    }
    bool hasNext() {
        return curr != nullptr; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
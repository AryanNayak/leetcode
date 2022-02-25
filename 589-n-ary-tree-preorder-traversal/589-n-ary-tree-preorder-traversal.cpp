/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private: 
    vector<int> result; 
public:    
    vector<int> preorder(Node* root) {
        
        // preorderRecursive(root); 
        
        if(root == nullptr)
            return result; 
        
        
        stack<Node*> st; 
        
        st.push(root); 
        
        while(st.empty() == false)
        {
            
            Node* node = st.top(); 
            
            st.pop(); 
            
            result.push_back(node->val); 
            
            for(int i = node->children.size() - 1; i >= 0; i--)
            {
                st.push(node->children[i]); 
            }
    
        }

        return result; 
        
    }
    
    void preorderRecursive(Node* root)
    {
    if(root == nullptr)
        return; 
        
        
    result.push_back(root->val); 
        
    for(int i = 0; i < root->children.size(); i++)
    {
        preorderRecursive(root->children[i]); 
    }
        
    }
  
    
};
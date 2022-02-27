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

class Codec {
public:
 string serialize(Node* root) {
        string res; 
        if (!root) return "[null]"; 
        
        // BFS
        queue<Node*> q; 
        q.push(root);
        while (!q.empty())
        {
            int sz=q.size();
            for (int i=0; i<sz; i++)
            {
                Node* cur= q.front(); q.pop();
                // NULL node
//                 if (!root) { res+="null ";  continue; } 
                
                res+=to_string(cur->val);
                res.push_back(' ');
                
                // number of children
                int c_count = cur->children.size();
 // do we really need to push count? yes! , otherwise don't know how many children to parse later!!              
                res+= to_string(c_count); 
                res.push_back(' ');

                for (int j=0; j<c_count; j++)
                    q.push(cur->children[j]);
            }
        }    
        // mistake: forget adding []
        res="["+res+"]";
       //  cout<<res<<endl;
        return res; 
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {        
        //strip off []
        data = data.substr(1, data.size()-2);        
        return parse(data);     
    }

    Node* parse (string & data)
    {   
        istringstream iss(data);
        queue<Node*> q;  Node* root; 
         // obtain the first node, null or an integer
        string str;  iss>> str; 
        
        if (str=="null")  return NULL;  
       
        root= new Node (stoi(str)); // value        
        int c_count; iss>> c_count;  // child count
        root->children.resize(c_count);
        q.push(root); // push the root node        
        
        bool isRoot=true;        
        
        while (!q.empty())
        {
            int sz=q.size();
            for (int i=0; i<sz; i++)
            {
                //  current node's value
                Node* cur = q.front(); q.pop();                
               
                // number of children
                for (int j=0; j<cur->children.size(); j++)
                {   
                    string str; iss>>str;                
                    if (str=="null") {cur->children[j]=NULL; continue; } 
                    // value
                    // mistake: !! int val; iss>> val;// str is already value now
                    Node* child = new Node(stoi(str)); 
                                       
                    // problem: first root node has value and children count set already                
                    // solution: shift the logic: when first creating the node, set all its values                                       
                    int c_count; iss>>c_count;                 
                    child->children.resize(c_count); 
                    
                    // attach child to current parent
                    cur->children[j]=child; 
                    
                    q.push(child);
                }
            }   
        }
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
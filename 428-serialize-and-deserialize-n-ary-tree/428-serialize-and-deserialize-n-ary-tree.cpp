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
  // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root)
            return "";
        ostringstream ostr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            // if (curr) {
                ostr << curr->val << " " << curr->children.size() << " ";
                for (auto child : curr->children) {
                    q.push(child);
                }
            // } else {
            //     ostr << "# ";
            // }
        }
        return ostr.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty())
            return nullptr;
        istringstream istr(data);
        queue<Node*> q;
        string val = "", size = "";
        istr >> val;
        istr >> size;
        Node* root = new Node(stoi(val), vector<Node*>(stoi(size), nullptr)), *node = root;
        q.push(node);
        bool done = false;
        while (!q.empty() && !done) {
            auto curr = q.front();
            q.pop();
            int s = curr->children.size();
            for (int i = 0; i < s; i++) {
                if (!(istr >> val)) {
                    done = true;
                    break;
                }
                if (!(istr >> size)) {
                    done = true;
                    break;
                }
                if (val != "#") {
                    Node* next = new Node(stoi(val), vector<Node*>(stoi(size), nullptr));
                    curr->children[i] = next;
                    q.push(next);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
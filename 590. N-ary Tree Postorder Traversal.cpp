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
public:
    void rec(Node* root, vector<int>&a){
        if(!root) return;
        int i=0;
        while(i<(root->children).size()){
            if(root->children[i]) rec(root->children[i],a);
            i++;
        }
        a.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> a;
        rec(root,a);
        return a;
    }
};
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
        vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> a;
        if(!root) return a;
        vector<int> t;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            if(!cur){
                a.push_back(t);
                t.clear();
                q.push(NULL);
                if(q.front()==NULL) break;
            }else{
                t.push_back(cur->val);
                for(int i=0; i<cur->children.size(); i++){
                    if(cur->children[i]!=NULL) q.push(cur->children[i]);
                }
            }
        }
        return a;
    }
};
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = ""; queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr){
                s.append(to_string(curr->val) + ".");
                q.push(curr->left); q.push(curr->right);
            }else s.append("#.");
        }
        return s;
    }
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data); string str; getline(s, str, '.');
        TreeNode* root = new TreeNode(stoi(str)); 
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            getline(s,str,'.');
            if(str=="#") curr->left = NULL;
            else{
                curr->left = new TreeNode(stoi(str)); 
                q.push(curr->left);
            }
            getline(s,str,'.');
            if(str=="#") curr->right = NULL;
            else{
                curr->right = new TreeNode(stoi(str)); 
                q.push(curr->right);
            }
        }
        return root;
    }
};
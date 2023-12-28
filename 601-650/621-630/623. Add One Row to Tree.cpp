class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        TreeNode* garbage = new TreeNode();
        if(depth==1){
            TreeNode* temp = new TreeNode(val);
            temp->left=root;
            
            return temp;
        }
        q.push(root);
        q.push(garbage);
        int curr = 0;
        while(!q.empty()){
            if(q.front()==garbage){
                q.pop();
                continue;
            }
            curr++;
            if(curr==depth-1){
                cout<<q.front()->val;
                while(q.front()!=garbage){
                    TreeNode *temp =  q.front();
                    q.pop();
                    TreeNode* t1 = new TreeNode(val);
                    TreeNode* t2 = new TreeNode(val);
                    TreeNode *lTemp=nullptr, *rTemp=nullptr;
                    if(temp->left)
                        lTemp = temp->left;
                    if(temp->right)
                        rTemp = temp->right;
                    
                    temp->left = t1;
                    t1->left = lTemp;
                    
                    temp->right = t2;
                    t2->right = rTemp;
                }
                
                break;
            }
            
            while(q.front()!=garbage){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            q.push(garbage);
        }
        
        return root;
    }
};
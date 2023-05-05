class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        long long sum=0;
        
        while(!q.empty()){
            sum=0;
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            double avg = (double)sum/s;
            ans.push_back(avg);
        }
 
        return ans;
        
    }
};
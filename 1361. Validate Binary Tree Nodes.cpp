class Solution {
private:
    int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        for(int i = 0; i<n; i++){
            if(!children.count(i)) return i;
        }
        return -1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        int root = findRoot(n, left, right);
        if (root == -1) return false;
        
        unordered_set<int> vis; stack<int> st;
        vis.insert(root); st.push(root);
        
        while(!st.empty()) {
            int u = st.top(); st.pop();
            int lc = left[u], rc = right[u];
            if(lc!=-1){
                if(vis.count(lc)) return 0;
                st.push(lc); vis.insert(lc);
            }
            if(rc!=-1){
                if(vis.count(rc)) return 0;
                st.push(rc); vis.insert(rc);
            }
        }
        return (vis.size() == n);
    }
};
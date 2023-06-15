#define pii pair<int,int>
class TrieNode{
public:
    TrieNode* links[2];
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int n){
        TrieNode* node = root;
        for(int i=31; i>=0; i--){
            int bit = ((n>>i) & 1);
            if(!node->links[bit]){
                node->links[bit] = new TrieNode();
            }
            node = node->links[bit];
        }
    }
    int xorMax(int k){
        int ans=0; TrieNode* node = root;
        for(int i=31; i>=0; i--){
            int bit = ((k>>i) & 1);
            int expc = 1 - bit;
            if(node->links[expc]){
                ans += (pow(2,i));
                // ans = ans | (1<<i);
                node = node->links[expc];
            }else{
                node = node->links[bit];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>&v, vector<vector<int>>&q) {
        vector<int> ans(q.size(), -1); sort(v.begin(), v.end());
        vector<pair<int, pii>> vp;
        for(int i=0; i<q.size(); i++){
            vp.push_back( { q[i][1], {q[i][0], i} } );
        }
        sort(vp.begin(), vp.end());
        Trie trie; int i=0;
        for(auto x : vp){
            int m = x.first; int k = x.second.first;
            int idx = x.second.second;
            while(i<v.size() and v[i]<=m){
                trie.insert(v[i]);
                i++;
            }
            if(i!=0) ans[idx] = trie.xorMax(k);
        }
        return ans;
    }
};
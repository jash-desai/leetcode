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
                // ans += (pow(2,i));
                ans = ans | (1<<i);
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
    int findMaximumXOR(vector<int>&v) {
        Trie trie;
        for(int x : v){
            trie.insert(x);
        }
        int ans = INT_MIN;
        for(int x : v){
            ans = max(ans, trie.xorMax(x));
        }
        return ans;
    }
};
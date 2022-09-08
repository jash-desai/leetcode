class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].size(), noofwords=words.size();
        vector<int> result;
        unordered_map<string,int> wordmap;
        if(n*noofwords > s.size()){
            return result;
        }
        for(string word : words){
            wordmap[word]++;
        }
        for(int i=0; i<=s.size() - (noofwords*n); i++){
            unordered_map<string, int> wordsusedmap;
            for(int j=i; j<i +(noofwords*n); j+=n){
                string cur = s.substr(j,n);
                if(wordmap.find(cur) == wordmap.end()){
                    break;
                }
                wordsusedmap[cur]++;
                if(wordsusedmap[cur] > wordmap[cur]){
                    break;
                }
                if( wordsusedmap == wordmap){
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};
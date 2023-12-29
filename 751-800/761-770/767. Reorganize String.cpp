class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        for(int i=0; i<26; i++){
            if(freq[i]!=0) pq.push({freq[i], i+'a'});
        }
        string ans;
        while(pq.size()>1){
            auto [fp, ip] = pq.top(); pq.pop();
            auto [fq, iq] = pq.top(); pq.pop();
            ans += (ip); ans += (iq); fp--, fq--;
            if(fp>0) pq.push({fp, ip}); 
            if(fq>0) pq.push({fq, iq}); 
        }
        if(pq.size()){
            auto [fp, ip] = pq.top(); pq.pop();
            if(fp==1) ans += ip;
            else ans = "";
        }
        return ans;
    }
};
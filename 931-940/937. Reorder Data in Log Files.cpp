#define pss pair<string,string>
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>&v) {
        vector<string> digit; vector<pss> letter;
        for(auto log : v){
            if(log.back()>='a' and log.back()<='z'){
                int len = log.find(' ');
                string a = log.substr(0,len);
                string b = log.substr(len);
                letter.push_back({b,a});
            }
            else digit.push_back(log);
        }
        sort(letter.begin(),letter.end(),[](pss&a, pss&b){
    return (a.first != b.first) ? a.first < b.first : a.second < b.second;
    });
        vector<string>ans;
        for(auto temp:letter) ans.push_back(temp.second+temp.first);
        for(auto j: digit) ans.push_back(j);
        return ans;
    }
};
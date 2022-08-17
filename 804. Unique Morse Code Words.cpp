class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& v){
        int n=v.size();
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        for(auto str:v){
            string t;
            for(auto ch:str){
                t += (arr[ch-'a']);
            }
            s.insert(t);
        }
        return s.size();
    }
};
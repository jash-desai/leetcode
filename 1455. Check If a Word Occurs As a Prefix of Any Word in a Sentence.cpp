class Solution {
public:
    int isPrefixOfWord(string s, string p) {
        auto sent = " " + s, word = " " + p;
        auto pos = sent.find(word);
        if (pos != string::npos){
            return count(begin(sent), begin(sent) + pos + 1, ' ');
        }
        return -1;
}
};
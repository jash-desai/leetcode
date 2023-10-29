class Solution {
public:
    int strStr(string str, string sub) {
        size_t a = str.find(sub, 0);
        return a!=string::npos ? a : -1;
    }
};
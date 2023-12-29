class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = size(s), i = 0, j = n-1;
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return size(temp) < size(goal);
        }
        while(i<j and s[i] == goal[i]) i++;
        while(j >= 0 and s[j] == goal[j]) j--;
        if(i < j) swap(s[i], s[j]);
        return s == goal;
    }
};
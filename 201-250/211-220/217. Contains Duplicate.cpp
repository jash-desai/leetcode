auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        sort(v.begin(),v.end());
        return adjacent_find(v.begin(),v.end()) == v.end() ? 0 : 1;
    }
};
// class Solution {
//     map<string, int> mp; vector<int> v; int k; int n;
// private:
//     int rec(int i, int p){
//         if(i==n) return -1e9;
//         string key = to_string(i) + ":" + to_string(p);
//         if(mp.count(key)) return mp[key];
//         int ans1 = -1e9, ans2 = -1e9;
//         if(p==-1 or i-p<=k){
//             ans1 = v[i] + rec(i+1,i);
//         }
//         ans2 = rec(i+1, p);
//         return mp[key] = max(ans1, ans2);
//     }
// public:
//     int constrainedSubsetSum(vector<int>& v, int k) {
//         n = v.size(); this->v = v; this->k = k; 
//         mp.clear(); int ans = 1e9 + rec(0,-1);
//         if(ans==0) ans = *max_element(begin(v), end(v));
//         return ans;
//     }
// };
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            while (i - heap.top().second > k) {
                heap.pop();
            }

            int curr = max(0, heap.top().first) + nums[i];
            ans = max(ans, curr);
            heap.push({curr, i});
        }
        
        return ans;
    }
};
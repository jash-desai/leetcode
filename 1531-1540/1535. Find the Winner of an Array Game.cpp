class Solution {
public:
    int getWinner(vector<int>& v, int k) {
        int curr = v[0], cnt = 0; queue<int> q; int mx = v[0];
        for(int i=1; i<v.size(); i++) q.push(v[i]), mx = max(mx, v[i]);
        while(q.size()){
            int opp = q.front(); q.pop();
            if(curr > opp){
                cnt++;
                q.push(opp);
            }else{
                cnt = 1;
                q.push(curr);
                curr = opp;
            }
            if(cnt == k) return curr;
            if(curr == mx) return curr;
        }
        return -1;
    }
};
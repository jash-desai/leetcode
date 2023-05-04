class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> qr, qd;
        int n = s.size();
        for(int i = 0; i<n; i++){
            (s[i] == 'R') ? qr.push(i) : qd.push(i);
        }
        while(!qr.empty() and !qd.empty()){
            int r_id = qr.front(), d_id = qd.front();
            qr.pop(), qd.pop();
            (r_id < d_id) ? qr.push(r_id + n) : qd.push(d_id + n);
        }
        return (qr.size() > qd.size())? "Radiant" : "Dire";
    }
};
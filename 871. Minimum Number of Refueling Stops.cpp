class Solution {
public:
    int minRefuelStops(int l, int p, vector<vector<int>> &v) {
        // l = target dist.
        // p = initial fuel
        // v = {dist. from start pt., fuel available at that station}
        
        sort(v.begin(),v.end());
        int n=v.size();
        int a=0;
        int c=p;
        priority_queue<int, vector<int>> pq;
        bool f=0;
        for(int i=0; i<n; i++){
            if(c>=l) break;
            while(c<v[i][0]){
                if(pq.empty()){
                    f=1;
                    break;
                }
                a++;
                c+=pq.top();
                pq.pop();
            }
            if(f) break;
            pq.push(v[i][1]);
        }
        if(f) return -1;
        while(!pq.empty() and c<l){
            c+=pq.top();
            pq.pop();
            a++;
        }
        if(c<l) return -1;
        return a;
    }
};
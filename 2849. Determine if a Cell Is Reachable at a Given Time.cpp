class Solution {
public:
    bool isReachableAtTime(int sr, int sc, int er, int ec, int k) {
        // queue<array<int,3>> q; q.push({sr,sc,0});
        // while(q.size()){
        //     int sz = q.size();
        //     while(sz--){
        //         auto [r,c,t] = q.front(); q.pop();
        //         if(t>k) continue;
        //         if(r==er and c==ec and t==k) return 1;
        //         for(int i=-1; i<2; i++){
        //             for(int j=-1; j<2; j++){
        //                 if(!i and !j) continue;
        //                 int nr = r + i, nc = c + j;
        //                 q.push({nr,nc,t+1});
        //             }
        //         }
        //     }
        // }
        // return 0;
        int distX = abs(sr-er), distY = abs(sc-ec);
        if(distX==0 and distY==0 and k==1) return 0;
        return (min(distX, distY) + abs(distX-distY) <= k);
    }
};
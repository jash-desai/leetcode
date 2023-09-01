class Solution {
private:
    int countbits(int num){
        int count = 0;
        while(num){
            num = num & (num-1);
            count++;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> a(n+1);
        for(int i=0; i<=n; i++){
            a[i] = countbits(i);
            // int t = i;
            // for(int j=0; j<32; j++){
            //     if(1&t) a[i]++;
            //     t >>= 1;
            // }
        }
        return a;
    }
};
class Solution {
    int powTwo[31];
private:
    void power(){
        powTwo[0] = 1;
        for(int i=1; i<31; i++){
            powTwo[i] = powTwo[i-1]*2;
        }
        return;
    }
    int rec(int n, int k){
        if(n==1 or k==1) return 0;
        int l = powTwo[n-1];
        int m = l/2;
        if(k<=m) return rec(n-1,k);
        return (1 - rec(n-1,k-m));
    }
public:
    int kthGrammar(int n, int k) {
        power();
        return rec(n,k);
    }
};
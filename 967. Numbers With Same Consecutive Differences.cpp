class Solution {
public:
    int digits(int x) {
        int count = 0;
        while(x){
			count++;
            x = x/10;
        }
        return count;
    }
    void findNumbers(int curr, int n ,int k, vector<int> &a){
        if(digits(curr) == n){
            a.push_back(curr);
            return;
        }
        for(int i=0; i<10; i++){
           int d = curr % 10;
           if(abs(d - i) == k) {
               findNumbers((curr*10 + i), n, k, a); 
           } 
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> a;
        if(n==1){
            a.push_back(0);
        }
        for(int i=1; i<10; i++) {
            findNumbers(i, n, k, a);    
        }
        return a; 
    }
};
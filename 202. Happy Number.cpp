class Solution {
    int f(int n){
        int sum=0;
        while(n){
            int d = n%10;
            n /= 10;
            sum += d*d;
        }
        return sum;
}
public: 
    bool isHappy(int n) {
        unordered_set<int> visited;
        // for(int i=0; i<19; i++){
        while(1){
            if(n==1){
                return 1;
            }
            n = f(n);
            if(visited.count(n) == 1){
                return false;
            }
            visited.insert(n);
        }
        assert(false);
    }
};
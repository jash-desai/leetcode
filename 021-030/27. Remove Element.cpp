class Solution {
public:
    int removeElement(vector<int> &v, int k) {
        int n=v.size();
        sort(v.begin(),v.end());
        int c=0; int ki=INT_MAX;
        for(int i=0; i<n; i++){
            if(v[i]==k){
                c++;
                ki = min(ki,i);
            }
        }
        int i=ki;
        if(ki+c >= n){
            return (n-c);
        }
        int j=ki+c;
        while(j<n){
            swap(v[i],v[j]);
            i++; j++;
        }

        return (n-c);
    }
};
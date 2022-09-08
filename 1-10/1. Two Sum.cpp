class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        //hashing-method
        int n=v.size();
        map<int, int> m;
        vector<int> a(2,-1);
        m[v[0]]=0;
        for(int i=1; i<n; i++){
            int t=k-v[i];
            if(m.find(t)!=m.end()){
                a[0]=m[t];
                a[1]=i;
                break;
            }else{
                m[v[i]] = i;
            }
        }
        return a;
    }
};
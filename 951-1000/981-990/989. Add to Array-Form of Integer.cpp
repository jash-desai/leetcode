class Solution {
public:
    vector<int> addToArrayForm(vector<int>& v, int k) {
        int n=v.size();
        vector<int> a;
        while(k){
            int x = k%10;
            k /=10;
            a.push_back(x);
        }
        reverse(v.begin(), v.end());
        int i=0, j=0;
        int c=0;
        vector<int> ans;
        if(v.size() < a.size()){
            vector<int> t = v;
            v=a; a=t;
        }
        while(i<v.size() and j<a.size()){
            int x = v[i]+a[i] + c;
            c=0;
            ans.push_back((x%10));
            if(x>9) c = x/10;
            i++; j++;
        }
        while(i<v.size()){
            int x = v[i]+c;
            c=0;
            ans.push_back(x%10);
            if(x>9) c = x/10;
            i++;
        }
        if(c>0) ans.push_back(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>&v) {
        /*
        int n = size(v); stack<int> st; vector<int> ans;
        for(int a : v){
            if(st.empty()){ st.push(a); continue; } // first element
            if(a>0 and st.top()>0){ st.push(a); continue; } // + +
            if(a<0 and st.top()<0){ st.push(a); continue; } // - -
            if(a>0 and st.top()<0){ st.push(a); continue; } // - +
            int b = st.top(); st.pop();
            if(abs(a)>abs(b)){
                while(!st.empty()){
                    if(st.top()>0 and a<0){
                        if(abs(st.top()) < abs(a)) st.pop();
                        else if(abs(st.top()) == abs(a)){
                            st.pop(); a=0; break;
                        }else{ a=0; break;}
                    }else{ st.push(a); break;}
                }
                if(st.empty() and a!=0) st.push(a);
            }else if(abs(a)<abs(b)){
                st.push(b);
            }
        }
        if(st.empty()) return {};
        while(!st.empty()){ ans.push_back(st.top()); st.pop(); }
        return vector<int>(rbegin(ans), rend(ans));
        */
        int n = size(v), j{0};
        for(int i{0}; i<n; i++){
            int b = v[i];
            while(j>0 and v[j-1]>0 and b<0 and v[j-1]<(-b)) j--;
            if(j==0 or b>0 or v[j-1]<0) v[j++] = b;
            else if(v[j-1] == -b) j--;
        }
        return vector<int>(begin(v), begin(v)+j);
    }
};
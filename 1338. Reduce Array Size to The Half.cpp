#include<bits/stdc++.h>
class Solution {
public:
    int minSetSize(vector<int>&v){
        int n=v.size();
        map<int,int> m;
        for(int i=0; i<n; i++){
            m[v[i]]++;
        }
        multimap<int,int,greater<int>> mm;
        for(auto i:m){
            mm.insert({i.second, i.first});
        }
        int s=0;
        int a = 0;
        for(auto it=mm.begin(); it!=mm.end(); it++){
            s+=it->first;
            a++;
            if(s>=n/2){
                return a;
            }
        }
        return -1;
    }
};
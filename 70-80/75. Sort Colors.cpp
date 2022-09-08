// keep count method
/*
class Solution {
public:
    void sortColors(vector<int>&v){
        int a=0; int b=0; int c=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]==0) a++;
            if(v[i]==1) b++;
            if(v[i]==2) c++;
        }
        for(int i=0; i<a; i++){
            v[i]=0;
        }for(int i=a; i<a+b; i++){
            v[i]=1;
        }for(int i=a+b; i<a+b+c; i++){
            v[i]=2;
        }
    }
};
*/
class Solution {
public:
    void sortColors(vector<int>&v){
        int lo = 0; 
        int hi = v.size() - 1; 
        int mid = 0;
        while(mid<=hi){
            switch(v[mid]){
                case 0 : swap(v[lo++],v[mid++]); break;
                case 1 : mid++; break;
                case 2 : swap(v[hi--],v[mid]); break;
            }
        }
    }
};
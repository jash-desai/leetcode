/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int findPeak(MountainArray&v){
        int n = v.length(), l = 1, r = n-2;
        while(l<=r){
            int m = l + ((r-l) >> 1);
            int x = v.get(m);
            int lx = v.get(m-1);
            int rx = v.get(m+1);
            if(x > lx and x > rx) return m;
            if(x > lx) l = m+1;
            else r = m-1;
        }
        return -1;
    }
    int findElement(MountainArray&v, int l, int r, int k, bool f){
        int n = v.length(), ans = -1;
        while(l<=r){
            int m = l + ((r-l) >> 1);
            int x = v.get(m);
            if(x == k){
                ans = m, r = m-1;
                continue;
            }
            if(f){
                if(x > k) r = m-1;
                else l = m+1;
            }else{
                if(x > k) l = m+1;
                else r = m-1;
            }
        }
        return ans;
    }
public:
    int findInMountainArray(int k, MountainArray &v) {
        int n = v.length(); int idx = findPeak(v);
        int idx1 = findElement(v,0,idx,k,true);
        int idx2 = findElement(v,idx+1,n-1,k,false);
        if(idx1==-1 and idx2==-1) return -1;
        if(idx1!=-1) return idx1;
        else return idx2;
    }
};
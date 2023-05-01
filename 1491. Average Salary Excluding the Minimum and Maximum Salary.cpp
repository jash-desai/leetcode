class Solution {
public:
    double newPrecision(double n, int i){
        return (floor(pow(10,i)*n)/pow(10,i));
    }
    double average(vector<int>& v) {
        sort(v.begin(), v.end());
        double a=0;
        for(int i=1; i<(v.size()-1); i++){
            a += v[i];
        }
        return (a/(v.size()-2));
    }
};
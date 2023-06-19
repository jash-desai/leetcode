class Solution {
public:
	bool reorderedPowerOf2(int n){
		string s = to_string(n);
		sort(s.begin(),s.end());

		vector<string> power;

		for(int i=0; i<=30; i++){
			int p = pow(2,i);
			power.push_back(to_string(p));
		}		
        for(int i=0; i<=30; i++){
            sort(power[i].begin(),power[i].end());
        }
        for(auto x:power){
            if(x == s ) return true;
        }
		return 0;
	}
};
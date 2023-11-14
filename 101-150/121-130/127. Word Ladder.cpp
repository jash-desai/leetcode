class Solution {
public:
	int ladderLength(string a, string b, vector<string>&v) {
		queue<pair<string,int>> q; q.push({a,1});
		unordered_set<string> st(v.begin(), v.end());
		st.erase(a);
		while(!q.empty()){
			string s = q.front().first;
			int d = q.front().second; q.pop();
			if(s==b) return d;
			for(int i=0; i<s.size(); i++){
				char org = s[i];
				for(char ch='a'; ch<='z'; ch++){
					s[i]=ch;
					if(st.count(s)){
						st.erase(s); q.push({s,d+1});
					}
				}
				s[i]=org;
			}
		}
		return 0;
    }
};
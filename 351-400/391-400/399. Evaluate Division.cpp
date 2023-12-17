class Solution {
public:
void dfs(string start,string end,map<string,double>&mp,map<string,vector<string>>&gr, double&val,map<string,int>& vis,bool& found){
        vis[start]=1;
        if(found==true) return;
        for(auto child:gr[start]){
            if(vis[child]!=1){
                val*=mp[start+"->"+child];
                if(end==child){
                    found=true;
                    return;
                }
                dfs(child,end,mp,gr,val,vis,found);
                if(found==true) return;
                else val/=mp[start+"->"+child];
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>&eq, vector<double>& vals, vector<vector<string>>& qr) {
        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> gr;
        for(int i=0;i<eq.size();i++){
            string u=eq[i][0];
            string v=eq[i][1];
            mp[u+"->"+v]=vals[i];
            mp[v+"->"+u]=1/vals[i];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        for(int i=0;i<qr.size();i++){
            string st=qr[i][0]; string en=qr[i][1];
            if(gr.find(st)==gr.end() or gr.find(en)==gr.end()){
                ans.push_back(-1);
            }else{
                // ans.push_back(1);
                double val=1;
                map<string,int> vis;
                bool found=false;
                if(st==en) found=true;
                else dfs(st,en,mp,gr,val,vis,found);
                if(found==true) ans.push_back(val);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};